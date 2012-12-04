#!/bin/bash

#
# #see http://wiki.osdev.org/Loopback_Device
#

#
# Shell guards
#
set -e -u

#
# Cleanup
#
sudo umount /mnt/remote/dev || true
sudo umount /mnt/remote     || true
sudo losetup -d /dev/loop1  || true
sudo losetup -d /dev/loop0  || true
rm -f kernel-image.hdd      || true

#
# CHS variables
#
DSK_BYTES_PER_SECTOR=512
DSK_CYLINDERS=256
DSK_HEADS=16
DSK_SECTORS=63
let DSK_SIZE_BYTES="$DSK_BYTES_PER_SECTOR * $DSK_SECTORS * $DSK_HEADS * $DSK_CYLINDERS"
let DSK_SIZE_BLOCKS="$DSK_SIZE_BYTES / $DSK_BYTES_PER_SECTOR"
let FS_OFFSET="2048 * $DSK_BYTES_PER_SECTOR"

#
# Dump sizes
#
echo "$DSK_SIZE_BYTES - $FS_OFFSET"

#
# Create image
#
dd if=/dev/zero of=kernel-image.hdd bs=$DSK_BYTES_PER_SECTOR count=$DSK_SIZE_BLOCKS

#
# Setup loopback for the disk
#
sudo losetup /dev/loop0 kernel-image.hdd

#
# Partitioning TODO: sfdisk or parted to avoid interactive
#
sudo echo "
n
p
1
2048

w
" |sudo fdisk -u -C$DSK_CYLINDERS -H$DSK_HEADS -S$DSK_SECTORS /dev/loop0 || true

#
# Update partitions
#
sudo partprobe

#
# Setup loopback for the partition
#
sudo losetup -o $FS_OFFSET /dev/loop1 /dev/loop0

#
# Update partitions
#
sudo partprobe

#
# Create file system
#
sudo mkfs.ext2 -m0 -L Zeno /dev/loop1
sudo tune2fs -c 0 -i 0 -m 0 -r 0 -T now -U random /dev/loop1

#
# Update partitions
#
sudo partprobe

#
# Mount new fs
#
sudo mkdir -p /mnt/remote
sudo mount /dev/loop1 /mnt/remote

#
# Create unix fs structure
#
sudo mkdir /mnt/remote/boot
sudo mkdir /mnt/remote/boot/grub
sudo mkdir /mnt/remote/etc
sudo mkdir /mnt/remote/bin
sudo mkdir /mnt/remote/usr
sudo mkdir /mnt/remote/var
sudo mkdir /mnt/remote/lib
sudo mkdir /mnt/remote/dev
sudo mkdir /mnt/remote/proc
sudo mkdir /mnt/remote/tmp
sudo mkdir /mnt/remote/home
sudo mkdir /mnt/remote/root

sudo chmod 700 /mnt/remote/root
sudo chmod 777 /mnt/remote/tmp
sudo chmod +t /mnt/remote/tmp

#
# Copy boot code
#
sudo cp ../grub/device.map /mnt/remote/boot/grub/
sudo cp ../grub/grub.cfg /mnt/remote/boot/grub/
sudo cp ../grub/menu.lst /mnt/remote/boot/grub/
sudo cp ../../boot/kernel.raw /mnt/remote/boot/
sudo cp ../../boot/kernel.elf /mnt/remote/boot/

#
# Sync FS
#
sudo sync

#
# Dump FS statistic
#
#sudo dumpe2fs -x /dev/loop1
#sudo stat /mnt/remote/boot/grub/grub.cfg
#sudo stat /mnt/remote/boot/grub/device.map

#
# Bind host's /dev FS to the target
#
sudo mount --bind /dev /mnt/remote/dev

#
# Install Grub2
#
#sudo grub-mkimage -p /mnt/remote/boot/grub -O i386-pc -o /mnt/remote/boot/grub/core.img ext2 multiboot normal
#sudo grub-setup -d /mnt/remote/boot/grub /dev/loop0
#sudo grub-install --boot-directory=/mnt/remote/boot --no-floppy --recheck --modules="part_msdos ext2 multiboot" /dev/loop0
sudo grub-install --root-directory=/mnt/remote/ --no-floppy --recheck --modules="part_msdos ext2 elf multiboot normal" /dev/loop0

#
# Unbind /dev & target partition
#
sudo umount /mnt/remote/dev
sudo umount /mnt/remote

#
# Wait to unlock loopbacks
#
sleep 3

#
# Update partitions
#
sudo partprobe

#
# Remove loopbacks
#
sudo losetup -d /dev/loop1 || true
sudo losetup -d /dev/loop0 || true

#
# Create disk distribution
#
rm -f ../../kernel-image.hdd.tgz || true
tar czf ../../kernel-image.hdd.tgz ./kernel-image.hdd

#
# Done
#
echo "Done."

