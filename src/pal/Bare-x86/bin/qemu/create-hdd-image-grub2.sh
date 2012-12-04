#!/bin/bash

#
# http://wiki.osdev.org/Loopback_Device
#

set -e -u

# Cleanup
sudo umount /mnt/remote/dev || true
sudo umount /mnt/remote || true
sudo losetup -d /dev/loop1 || true
sudo losetup -d /dev/loop0 || true
rm -f kernel-image.hdd

#
# Variables
#


# CHS
DSK_BYTES_PER_SECTOR=512
DSK_CYLINDERS=256
DSK_HEADS=16
DSK_SECTORS=63
let DSK_SIZE_BYTES="$DSK_BYTES_PER_SECTOR * $DSK_SECTORS * $DSK_HEADS * $DSK_CYLINDERS"
let DSK_SIZE_BLOCKS="$DSK_SIZE_BYTES / $DSK_BYTES_PER_SECTOR"
let FS_OFFSET="2048 * $DSK_BYTES_PER_SECTOR"

echo "$DSK_SIZE_BYTES - $FS_OFFSET"

# Create image
dd if=/dev/zero of=kernel-image.hdd bs=$DSK_BYTES_PER_SECTOR count=$DSK_SIZE_BLOCKS

# Setup loopback for the disk
sudo losetup /dev/loop0 kernel-image.hdd

# Partitions
sudo echo "
n
p
1
2048

w
" |sudo fdisk -u -C$DSK_CYLINDERS -H$DSK_HEADS -S$DSK_SECTORS /dev/loop0 || true

# Update partitions
sudo partprobe

# Setup loopback for the partition
sudo losetup -o $FS_OFFSET /dev/loop1 /dev/loop0

# Update partitions
sudo partprobe

# Create filesystem
sudo mkfs.ext2 -m0 -L Zeno /dev/loop1
sudo tune2fs -c 0 -i 0 -m 0 -r 0 -T now -U random /dev/loop1

# Update partitions
sudo partprobe

# Mount new fs
sudo mkdir -p /mnt/remote
sudo mount /dev/loop1 /mnt/remote

# Create unix fs structure
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
ls /mnt/remote

sudo chmod 700 /mnt/remote/root
sudo chmod 777 /mnt/remote/tmp
sudo chmod +t /mnt/remote/tmp

sudo cp ../grub/grub.cfg /mnt/remote/boot/grub/
sudo cp ../grub/device.map /mnt/remote/boot/grub/
sudo cp ../../boot/kernel.raw /mnt/remote/boot/
sudo sync

#sudo dumpe2fs -x /dev/loop1
#sudo stat /mnt/remote/boot/grub/grub.cfg
#sudo stat /mnt/remote/boot/grub/device.map

sudo mount --bind /dev /mnt/remote/dev

#sudo grub-mkimage -p /mnt/remote/boot/grub -O i386-pc -o /mnt/remote/boot/grub/core.img ext2 multiboot normal
#sudo grub-setup -d /mnt/remote/boot/grub /dev/loop0
#sudo grub-install --boot-directory=/mnt/remote/boot --no-floppy --recheck --modules="part_msdos ext2 multiboot" /dev/loop0
sudo grub-install --root-directory=/mnt/remote/ --no-floppy --recheck --modules="part_msdos ext2 multiboot" /dev/loop0

sudo umount /mnt/remote/dev
sudo umount /mnt/remote

sudo losetup -d /dev/loop1 || true
sudo losetup -d /dev/loop0 || true

tar czf ../../kernel-image.hdd.tgz ./kernel-image.hdd

echo "Done."

