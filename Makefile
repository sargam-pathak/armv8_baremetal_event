CC = arm-none-eabi-gcc
MACH = cortex-m33
CFLAGS = -mcpu=$(MACH) -mthumb -std=c99 -Wall -O0 -g
LDFLAGS = -mcpu=cortex-m33 -mthumb --specs=nosys.specs -nostartfiles -T src/linker.ld -Wl,-Map=kernel.map


all: kernel.elf

kernel.elf: src/startup.c src/mpu_config.c src/scheduler.c src/main.c src/syscalls.c src/linker.ld
	$(CC) $(CFLAGS) src/startup.c src/mpu_config.c src/scheduler.c src/main.c src/syscalls.c $(LDFLAGS) -o kernel.elf

clean:
	rm -f *.elf