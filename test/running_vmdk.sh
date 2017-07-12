#!/bin/bash

excute_name=dedup.real.write_time.cache100000.pthread6
file_suffix=vmdk.realwritetime.cache100000.pthread6
excute_name_nocache=dedup.real.write_time.cache100000.pthread6.nocache


sudo ./${excute_name} /mnt/cdrom/vmdk/ /dev/sdh1 0 > ecc.ssd500G.${file_suffix} ##ecc mode, vmdk data set and the time of write is real write time
sudo ./${excute_name} /mnt/cdrom/vmdk/ /dev/sdh1 1 > md5.ssd500G.${file_suffix} ##md5 mode, vmdk data set and the time of write is real write time
sudo ./${excute_name} /mnt/cdrom/vmdk/ /dev/sdh1 2 > sha256.ssd500G.${file_suffix} ##sha256 mode, vmdk data set and the time of write is real write time

sudo ./${excute_name} /mnt/cdrom/vmdk/ /dev/sdi1 0 > ecc.hdd.${file_suffix} ##ecc mode, vmdk data set and the time of write is real write time
sudo ./${excute_name} /mnt/cdrom/vmdk/ /dev/sdi1 1 > md5.hdd.${file_suffix} ##md5 mode, vmdk data set and the time of write is real write time
sudo ./${excute_name} /mnt/cdrom/vmdk/ /dev/sdi1 2 > sha256.hdd.${file_suffix} ##sha256 mode, vmdk data set and the time of write is real write time

sudo ./${excute_name} /mnt/cdrom/vmdk/ /dev/nvme0n1 0 > ecc.nvme.${file_suffix} ##ecc mode, vmdk data set and the time of write is real write time
sudo ./${excute_name} /mnt/cdrom/vmdk/ /dev/nvme0n1 1 > md5.nvme.${file_suffix} ##md5 mode, vmdk data set and the time of write is real write time
sudo ./${excute_name} /mnt/cdrom/vmdk/ /dev/nvme0n1 2 > sha256.nvme.${file_suffix} ##sha256 mode, vmdk data set and the time of write is real write time

sudo ./${excute_name_nocache} /mnt/cdrom/vmdk/ /dev/sdh1 0 > ecc.ssd500G.${file_suffix} ##ecc mode, vmdk data set and the time of write is real write time
sudo ./${excute_name_nocache} /mnt/cdrom/vmdk/ /dev/sdi1 0 > ecc.hdd.${file_suffix} ##ecc mode, vmdk data set and the time of write is real write time
sudo ./${excute_name_nocache} /mnt/cdrom/vmdk/ /dev/nvme0n1 0 > ecc.nvme.${file_suffix} ##ecc mode, vmdk data set and the time of write is real write time

