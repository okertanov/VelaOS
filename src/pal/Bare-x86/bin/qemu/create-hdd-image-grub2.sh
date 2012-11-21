#!/bin/sh

set -e -u

# Cleanup
rm -f kernel-image.hdd
sudo losetup -d /dev/loop1 || true
sudo losetup -d /dev/loop0 || true

# Create image
dd if=/dev/zero of=./kernel-image.hdd bs=512 count=8192

# Setup loopback for the disk
sudo losetup /dev/loop0 kernel-image.hdd
sudo dd if=/dev/zero of=/dev/loop0 || true

# Partitions
sudo echo "x
c
261
r
n
p
1
32
261
a
1
w
" |sudo fdisk /dev/loop0 || true

# Update partitions
sudo partprobe

# Setup loopback for the partition
#sudo losetup -o 32256 /dev/loop1 /dev/loop0
sudo losetup -o 305235 /dev/loop1 /dev/loop0

# Update partitions
sudo partprobe

# Create filesystem
sudo mkfs.ext2 -m0 -b 1024 -L Zeno /dev/loop1
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

sudo cp ../grub/grub.cfg /mnt/remote/boot/grub
sudo cp ../../boot/kernel.raw /mnt/remote/boot
sudo sync

sudo dumpe2fs -x /dev/loop1
sudo stat /mnt/remote/boot/grub/stage2

sudo grub-install --root-directory=/mnt/remote --no-floppy --force /dev/loop0

sudo umount /dev/loop1
sudo losetup -d /dev/loop1
sudo losetup -d /dev/loop0

echo "Done."

tar czf ../../kernel-image.hdd.tgz ./kernel-image.hdd

