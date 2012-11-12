ARM/STM32 embedded development
==============================

[Terms]
-------
EABI - Embedded ABI
VFP - Vector Floating Point
hf - Hard Float
le - Little-endian
be - Big-endian
armel - arm new platform(EABI, not OABI), little-endian
dcv1 -

[Hardware]
----------
ARM Cortex M4

[ARM Core versions]
-------------------
ARMv4 - StrongARM, ARM7TDMI, ARM9TDMI
ARMv5 - ARM7EJ, ARM9E, ARM10E, XScale
ARMv6 - ARM11
ARMv7 - Cortex
ARMv8 - Will support 64-bit

[Toolsets]
----------
### Posix-based
* Vim
* GNU Make
* ARM toolchain

### NetBeans-based
* NetBeans 7.1
* NetBeans git plugin
* Ubuntu ARM toolchain
* ST-Link github project

### Eclipse-based
* Eclipse CDT
* eGit
* ARM Eclipse Plugin
* OpenOCD
* ARM toolchain

[BSP && Libraries]
------------------
* CMSIS
* STM32F4x Firmware package
* RedHat NewLib

[Ubuntu ARM toolchain]
----------------------
* pbuilder
* pdebuild-cross
* gcc-arm-linux-gnueabi
* g++-arm-linux-gnueabi
* binutils-arm-linux-gnueabi
* gdb-multiarch
* gdbserver
* libc-dev-armel-cross
* libstdc++-dev-armel-cross
* linux-kernel-headers-armel-cros

[Links]
-------

### ARM in general
[Wikipedia: Arm Architecture](http://en.wikipedia.org/wiki/ARM_architecture)

[Wikipedia: List of ARM cores](http://en.wikipedia.org/wiki/List_of_applications_of_ARM_cores)

### Operating Systems
[OSDev.org](http://wiki.osdev.org/Main_Page)

### GCC Tricks
[The most useful GCC options and extensions](http://www.antoarts.com/the-most-useful-gcc-options-and-extensions/)

[GCC Extensions to the C Language Family](http://gcc.gnu.org/onlinedocs/gcc/C-Extensions.html)

[GCC code block ({})](http://www.parashift.com/c++-faq-lite/dtors.html#faq-11.7)

``gcc -Q --help=target or optimisers or warnings``  
``gcc -E -dM - < /dev/null``  
``gcc -dumpspecs``  
``gcc -### program.c``  
``arm-elf-objdump -b binary -m arm -EL --prefix-addresses -D test.bin``  


### BSP && Libraries
[STMicroelectronics STM32F4 Discovery Firmware](http://www.st.com/internet/evalboard/product/252419.jsp)

[GitHub: Modified STM32F4 Discovery Firmware from ST](https://github.com/nabilt/STM32F4-Discovery-Firmware)

[Libopencm3 a free/libre/open-source firmware library for ARM Cortex-M3](http://www.libopencm3.org/wiki/Main_Page)

[GitHub: Mcucpp by Konstantin Chizhov](https://github.com/KonstantinChizhov/Mcucpp)

[onARM CMSIS Downloads](http://www.onarm.com/cmsis/download/)

[NewLib](http://sourceware.org/newlib/)

[uClibc a C library for embedded Linux](http://uclibc.org/)

[Kernel.org ARM Lib](http://git.kernel.org/?p=linux/kernel/git/torvalds/linux-2.6.git;a=tree;f=arch/arm/lib;hb=HEAD)

[Android Bionic](http://developer.android.com/index.html)

[EGLIBC](http://www.eglibc.org/cgi-bin/viewvc.cgi/trunk/ports/sysdeps/arm/)

[Diet LibC](http://www.fefe.de/dietlibc/)


### Programming
[Open On-Chip Debugger](http://openocd.sourceforge.net/)

[Using the STM32F4 DISCOVERY Board in OSX Lion](http://www.nabiltewolde.com/2011/10/using-stm32f4-discovery-board-in-osx.html)

[Programming the STM32F4 DISCOVERY with the Bus Blaster](http://www.nabiltewolde.com/2011/10/programming-stm32f4discovery-board-with.html)

[STM32 ist ein Mikrocontroller-Familie von ST](http://www.mikrocontroller.net/articles/STM32)

[Внутрисхемная отладка через Eclipse на примере платы stm32discovery](http://radiokot.ru/articles/34/)

[Getting to grips with Eclipse: cross compiling](http://www.embedded-linux.co.uk/tutorial/eclipse-cross-compile)

[EMBEDDED ARM DEVELOPMENT USING ECLIPSE AND GCC - PART1](http://embeddedcraft.org/freearmtools1.html)

[STM32/ARM Cortex-M3 HOWTO: Development under Ubuntu](http://fun-tech.se/stm32/index.php)

[Настройка связки Eclipse и ARM GCC в Linux](http://www.levap.ru/300)

[Part 1: Mac OS + Eclipse + OpenOCD + STM32 (ARM Cortex M3)](http://salvatoremenendez.blogspot.com/2011/08/mac-os-eclipse-openocd-stm32-arm-cortex.html)

[easyelectronics.ru ARM. Учебный Курс.](http://easyelectronics.ru/category/arm-uchebnyj-kurs)

[easyelectronics.ru ARM. Учебный Курс. STM32 tag](http://we.easyelectronics.ru/blog/STM32/)

[easyelectronics.ru ARM. Учебный Курс. Keil + CMSIS. Создание проекта](http://easyelectronics.ru/arm-uchebnyj-kurs-keil-cmsis-sozdanie-proekta.html)

[Работа с портами ввода-вывода микроконтроллеров на Си++](http://easyelectronics.ru/rabota-s-portami-vvoda-vyvoda-mikrokontrollerov-na-si.html)

[Пример использования CMSIS в Eclipse](http://cxemotexnika.org/2010/11/%D0%BF%D1%80%D0%B8%D0%BC%D0%B5%D1%80-%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F-cmsis-%D0%B2-eclipse/)

[CMSIS Doulos Tutorial PDF](http://www.doulos.com/knowhow/arm/CMSIS/CMSIS_Doulos_Tutorial.pdf)

[Run to Completion (RTC) scheduler](http://www.mentor.com/embedded-software/blog/post/the-one-line-rtos-0aad7b67-fc22-444d-b3da-67ad42a352e0)

[Embedded Programming with the GNU Toolchain](http://www.bravegnu.org/gnu-eprog/)

[ARMFlasher - программа для прошивки платы Disсovery в Kubuntu](http://we.easyelectronics.ru/STM32/armflasher---programma-dlya-proshivki-platy-dissovery-v-kubuntu.html)

[Template для STM32 (IAR+PHYDriver+CMSIS+FreeRTOS)](http://we.easyelectronics.ru/STM32/template-dlya-stm32-iarphydrivercmsisfreertos.html)

[STM32F1xx — Инструменты разработчика и FreeRTOS](http://habrahabr.ru/post/139601/)

[ST-LINK + Eclipse на Ubuntu ](http://we.easyelectronics.ru/CADSoft/st-link-eclipse-na-ubuntu.html)

[Ключики компилятора avr-gcc для уменьшения бинарника](http://we.easyelectronics.ru/AVR/klyuchiki-kompilyatora-avr-gcc-dlya-umensheniya-binarnika.html)

[prattmic / stm32f4-templates](https://github.com/prattmic/stm32f4-templates)


### Debian amd Ubuntu cross-compilation
[Debian: ARM Port](http://www.debian.org/ports/arm/)

[Debian: ArmEabiPort](http://wiki.debian.org/ArmEabiPort)

[Debian: Setting up a Cross Development Environment on Debian GNU/Linux](http://people.debian.org/~debacle/cross/)

[Debian: Building a Cross Compiler](http://wiki.debian.org/BuildingCrossCompilers)

[Debian: ToolChainCross](http://wiki.debian.org/ToolChain/Cross)

[Debian: Cross-development toolchains](http://www.emdebian.org/crosstools.html)

[Debian: old Cross Toolchains](http://www.emdebian.org/tools/crosstools.html)

[Debian: Emdebian Toolchain](http://wiki.debian.org/EmdebianToolchain)

[Ubuntu: ARM Project](https://wiki.ubuntu.com/ARM)

[Ubuntu: Linaro Toolchain](https://launchpad.net/linaro-toolchain)

[Installing and running Debian armel on an emulated ARM machine on Windows (QEMU)](http://cronicasredux.blogspot.com/2011/09/installing-and-running-debian-armel-on.html)


### Cross-build projects
[Buildroot: making Embedded Linux easy](http://www.buildroot.net/)

[Embedded Linux Wiki](http://elinux.org/Main_Page)

[Embedded Linux ARMCompilers](http://www.elinux.org/ARMCompilers)

[Embedded Linux Toolchains List](http://elinux.org/Toolchains)

[scratchbox.org, the cross-compilation toolkit project.](http://www.scratchbox.org/)

[Angstrom userfriendly distribution for embedded devices](http://www.angstrom-distribution.org/)

[Openmoko Toolchain](http://wiki.openmoko.org/wiki/Toolchain)

[OpenEmbedded offers a best-in-class cross-compile environment.](http://www.openembedded.org/wiki/Main_Page)

[OpenBricks is an embedded Linux framework](http://git.openbricks.org/)

[Android NDK](http://developer.android.com/sdk/ndk/)


### Other Toolchains
[GNU ARM toolchain for Cygwin, Linux and MacOS](http://www.gnuarm.com/)

[Mentor Graphics Embedded Sourcery Tools](http://www.mentor.com/embedded-software/sourcery-tools/support)

[YAGARTO GNU ARM toolchain](http://www.yagarto.de/)

[Crosstool-NG](http://crosstool-ng.org/)

[Original kegel.com/crosstool](http://kegel.com/crosstool/)

[GitHub: ARM EABI Toolchain Builder](https://github.com/jsnyder/arm-eabi-toolchain)

[GitHub: A very simple build script for bare metal arm toolchain](https://github.com/esden/summon-arm-toolchain)

[OSELAS.Toolchain() at pengutronix.de](http://www.pengutronix.de/oselas/toolchain/index_en.html)

[ARM-Projects by Martin THOMAS](http://www.siwawi.arubi.uni-kl.de/avr_projects/arm_projects/)

[Toolchain for ARM on OSX (ARM Cortex-M3)](http://www.jroller.com/maded/entry/toolchain_for_arm_on_osx)

[devkitPro: provider of homebrew toolchains for wii, gamecube, ds, gba, gp32 and psp](http://devkitpro.org/wiki/Getting_Started)

[Free and Open Source (FOSS) Tools for ARM](http://www.state-machine.com/arm/)

[Building bare-metal ARM with GNU PDF](http://www.state-machine.com/arm/Building_bare-metal_ARM_with_GNU.pdf)

[Setting up a GCC Development Environment for the Cortex M0/M3](http://www.microbuilder.eu/projects/LPC1343ReferenceDesign/LPC1343Toolchain.aspx)

[GitHub: The fun tech build scripts to get gcc for ARM Cortex based MCU:s to work on Ubuntu](https://github.com/jsiei97/FunTechCortexMX_gcc)

[Compiling a toolchain for ARM7 under Ubuntu](http://www.madox.net/blog/2008/11/26/compiling-a-toolchain-for-arm7-under-ubuntu/)

[arm.com Software Tools > DS-5 > ARM Compiler](http://www.arm.com/products/tools/software-tools/ds-5/arm-compiler.php)

[Chumby toolchain](http://wiki.chumby.com/index.php/GNU_Toolchain)

[Building the GNU ARM Toolchain for Bare Metal](http://www.kunen.org/uC/gnu_tool.html)

[FriendlyARM Downloads](http://friendlyarm.net/downloads)

[GitHub: STM32 Discovery Line Linux Programmer](https://github.com/texane/stlink)

[Ubuntu + Eclipse + Code Sourcery + OpenOCD + j-link + ARM](http://we.easyelectronics.ru/CADSoft/ubuntu-eclipse-code-sourcery-openocd-j-link-arm-ili-bystryy-start-dlya-somnevayuschihsya.html)


### Free IDEs
[GNU ARM Eclipse Plug-in](http://sourceforge.net/projects/gnuarmeclipse/)


### Embedded OSes
[eCos is a free open source real-time operating system](http://ecos.sourceware.org/)

[ChibiOS/RT Homepage](http://www.chibios.org/)

[The FreeRTOS Project](http://www.freertos.org/)


### #Embedded Languages
[GitHub: Embedded Lua](https://github.com/elua/elua)

[TinyScheme](http://tinyscheme.sourceforge.net/download.html)

[A Scheme Interpreter for ARM Microcontrollers](http://armpit.sourceforge.net/)


### Commercial IDEs
[IAR](http://www.iar.com/)

[Keil](http://www.keil.com/)

[Atollic](http://www.atollic.com/index.php/truestudio)

[CooCox](http://www.coocox.org/)


### ST Microelectronics
[STM32 F4 Hi-Performance & DSP](http://www.st.com/internet/mcu/subclass/1521.jsp)


### sourcery.mentor.com
[Mentor Graphics Sourcery G++ Lite 2011.03-42 for ARM EABI](https://sourcery.mentor.com/sgpp/lite/arm/portal/release1802)

[Mentor Graphics Resource Center](http://www.mentor.com/embedded-software/resources)

[Mentor Graphics Nucleus RTOS](http://www.mentor.com/embedded-software/nucleus/kernel)


### Hardware
[Futurlec STM32F103 Development Board](http://www.futurlec.com/STM32_Development_Board.shtml)

[Futurlec Sensors](http://www.futurlec.com/Sensors.shtml)

[Linaro SoC](http://www.linaro.org/)

[Low Cost Development Boards](http://www.linaro.org/engineering/getting-started/low-cost-development-boards/)

