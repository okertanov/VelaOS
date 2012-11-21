#!/bin/sh

set -e -u

rm -f kernel-image.hdd
dd if=/dev/zero of=./kernel-image.hdd bs=512 count=8192
sudo losetup -d /dev/loop0 || true
sudo partprobe
sudo losetup /dev/loop0 kernel-image.hdd
sudo dd if=/dev/zero of=/dev/loop0 || true

sudo echo "x
c
261
r
n
p
1
1
261
a
1
w
" |sudo fdisk /dev/loop0 || true
sudo dd if=../grub/stage1 of=/dev/loop0 bs=512 count=1

sudo partprobe
sudo losetup -d /dev/loop0

sudo losetup -d /dev/loop1 || true
sudo losetup -o 32256 /dev/loop1 kernel-image.hdd

sudo partprobe
sudo mkfs.ext2 -m0 -b 1024 -L Zeno /dev/loop1
sudo tune2fs -c 0 -i 0 -m 0 -r 0 -T now -U random /dev/loop1

sudo mkdir -p /mnt/remote
sudo mount /dev/loop1 /mnt/remote
ls /mnt/remote

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

sudo cp ../grub/menu.lst /mnt/remote/boot/grub
sudo cp ../grub/stage1 /mnt/remote/boot/grub
sudo cp ../grub/stage2 /mnt/remote/boot/grub
sudo cp ../../boot/kernel.raw /mnt/remote/boot
sudo sync

sudo dumpe2fs -x /dev/loop1
sudo stat /mnt/remote/boot/grub/stage2
sudo umount /dev/loop1
sudo dd if=../grub/stage1 of=/dev/loop1 bs=512 count=1
sudo losetup -d /dev/loop1

