x86 stdlibs, static, not stripped
-rw-r--r-- 1 okertanov Administrators 1813085 Nov 16 09:51 test-init.hex
-rw-r--r-- 1 okertanov Administrators 1791861 Nov 16 09:51 test-leds.hex
-rw-r--r-- 1 okertanov Administrators   12031 Nov 16 09:51 test-micro.hex
-rw-r--r-- 1 okertanov Administrators   12031 Nov 16 09:51 test-mini.hex

ARM DEBUG w/o stdlibs, static, not stripped
-rw-r--r-- 1 okertanov Administrators  307613 Nov 16 09:21 test-init.hex
-rw-r--r-- 1 okertanov Administrators  300392 Nov 16 09:21 test-leds.hex
-rw-r--r-- 1 okertanov Administrators     125 Nov 16 09:21 test-micro.hex
-rw-r--r-- 1 okertanov Administrators     434 Nov 16 09:21 test-mini.hex

ARM DEBUG w/o stdlibs, static, not stripped (some code in main() of micro/mini)
-rw-r--r-- 1 okertanov Administrators 307613 Nov 16 09:57 test-init.hex
-rw-r--r-- 1 okertanov Administrators 300392 Nov 16 09:57 test-leds.hex
-rw-r--r-- 1 okertanov Administrators    125 Nov 16 09:57 test-micro.hex
-rw-r--r-- 1 okertanov Administrators    434 Nov 16 09:57 test-mini.hex

ARM RELEASE w/o stdlibs, static, not stripped (some code in main() of micro/mini)
-rw-r--r-- 1 okertanov Administrators 298735 Nov 16 14:15 bin/test-init.hex
-rw-r--r-- 1 okertanov Administrators 292361 Nov 16 14:15 bin/test-leds.hex
-rw-r--r-- 1 okertanov Administrators     72 Nov 16 14:15 bin/test-micro.hex
-rw-r--r-- 1 okertanov Administrators    381 Nov 16 14:15 bin/test-mini.hex

ARM RELEASE w/o stdlibs, static, not stripped with -fno-stack-protector
-rw-r--r-- 1 okertanov Administrators 298735 Nov 16 16:02 test-init.hex
-rw-r--r-- 1 okertanov Administrators 292361 Nov 16 16:02 test-leds.hex
-rw-r--r-- 1 okertanov Administrators     72 Nov 16 16:02 test-micro.hex
-rw-r--r-- 1 okertanov Administrators    381 Nov 16 16:02 test-mini.hex

ARM RELEASE -Os
-rw-r--r-- 1 okertanov Administrators 293806 Nov 16 16:05 test-init.hex
-rw-r--r-- 1 okertanov Administrators 288062 Nov 16 16:05 test-leds.hex
-rw-r--r-- 1 okertanov Administrators     72 Nov 16 16:05 test-micro.hex
-rw-r--r-- 1 okertanov Administrators    381 Nov 16 16:05 test-mini.hex

ADM RELEASE custom dso and fini
-rw-r--r-- 1 okertanov Administrators 293796 Nov 21 16:47 test-init.hex
-rw-r--r-- 1 okertanov Administrators 288049 Nov 21 16:47 test-leds.hex
-rw-r--r-- 1 okertanov Administrators     72 Nov 21 16:47 test-micro.hex
-rw-r--r-- 1 okertanov Administrators    101 Nov 21 16:47 test-mini.hex

ARM DEBUG
-rw-r--r-- 1 okertanov Administrators 307468 Nov 22 10:12 test-init.hex
-rw-r--r-- 1 okertanov Administrators  20727 Nov 22 10:12 test-leds.hex
-rw-r--r-- 1 okertanov Administrators    125 Nov 22 10:12 test-micro.hex
-rw-r--r-- 1 okertanov Administrators    154 Nov 22 10:12 test-mini.hex

ARM DEBUG GNUC removed
-rw-r--r-- 1 okertanov Administrators 306380 Nov 22 11:16 test-init.hex
-rw-r--r-- 1 okertanov Administrators  20727 Nov 22 11:16 test-leds.hex
-rw-r--r-- 1 okertanov Administrators    125 Nov 22 11:16 test-micro.hex
-rw-r--r-- 1 okertanov Administrators    154 Nov 22 11:16 test-mini.hex

ARM DEBUG bin-files
-rw-r--r-- 1 okertanov Administrators 108904 Nov 22 11:36 test-init.elf.bin
-rw-r--r-- 1 okertanov Administrators   7348 Nov 22 11:36 test-leds.elf.bin
-rw-r--r-- 1 okertanov Administrators     24 Nov 22 11:37 test-micro.elf.bin
-rw-r--r-- 1 okertanov Administrators     32 Nov 22 11:37 test-mini.elf.bin

ARM DEBUG W/O Logger::~Logger()
-rw-r--r-- 1 okertanov Administrators 25296 Nov 22 16:04 ../bin/test-leds.hex
-rw-r--r-- 1 okertanov Administrators   125 Nov 22 16:04 ../bin/test-micro.hex
-rw-r--r-- 1 okertanov Administrators   154 Nov 22 16:04 ../bin/test-mini.hex

And bin-files
-rw-r--r-- 1 okertanov Administrators 8976 Nov 22 16:04 ../bin/test-leds.elf.bin
-rw-r--r-- 1 okertanov Administrators   24 Nov 22 16:04 ../bin/test-micro.elf.bin
-rw-r--r-- 1 okertanov Administrators   32 Nov 22 16:04 ../bin/test-mini.elf.bin

With Try-Catch and -fno-exceptions
-rw-r--r-- 1 okertanov Administrators 263958 Nov 22 16:27 ../bin/test-leds.hex
-rw-r--r-- 1 okertanov Administrators  93816 Nov 22 16:27 ../bin/test-leds.elf.bin

1: RELEASE C++ class and getter
test-leds.hex       485
2: RELEASE C++ class and Base class
test-leds.hex       485
3: RELEASE C++ class and virtual Base class
test-leds.hex       18686
4: RELEASE C++ class and virtual Base class and try-catch
test-leds.hex       18686
5: RELEASE C++ class and virtual Base class and try-catch and a template
test-leds.hex       18702
6: DEBUG C++ class and virtual Base class and try-catch and a template
test-leds.hex       20727


Final HW opt for the empty project - DEBUG
-rw-r--r-- 1 okertanov Administrators 1316 Nov 22 18:02 ../bin/test-init.hex
-rw-r--r-- 1 okertanov Administrators 1316 Nov 22 18:02 ../bin/test-leds.hex
-rw-r--r-- 1 okertanov Administrators 1316 Nov 22 18:02 ../bin/test-log.hex
-rw-r--r-- 1 okertanov Administrators  125 Nov 22 18:02 ../bin/test-micro.hex
-rw-r--r-- 1 okertanov Administrators  154 Nov 22 18:02 ../bin/test-mini.hex
-rw-r--r-- 1 okertanov Administrators 1316 Nov 22 18:02 ../bin/test-tasks.hex

Final HW opt for the empty project - RELEASE
-rw-r--r-- 1 okertanov Administrators 281 Nov 22 18:05 ../bin/test-init.hex
-rw-r--r-- 1 okertanov Administrators 281 Nov 22 18:05 ../bin/test-leds.hex
-rw-r--r-- 1 okertanov Administrators 281 Nov 22 18:05 ../bin/test-log.hex
-rw-r--r-- 1 okertanov Administrators  72 Nov 22 18:05 ../bin/test-micro.hex
-rw-r--r-- 1 okertanov Administrators 101 Nov 22 18:05 ../bin/test-mini.hex
-rw-r--r-- 1 okertanov Administrators 281 Nov 22 18:05 ../bin/test-tasks.hex

