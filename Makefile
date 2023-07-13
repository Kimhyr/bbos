TARGET := kernel

PREFIX := ~/opt/cross/bin
CC := $(PREFIX)/i686-elf-gcc
CXXC := $(PREFIX)/i686-elf-g++
CFLAGS := \
	-std=c++20 \
	-ffreestanding \
	-Wall -Wextra -pedantic
CXXFLAGS := $(CFLAGS)
LDFLAGS := $(CFLAGS) -nostdlib -T linker.ld -lgcc
CLEAN :=

CFLAGS += -g

#
# Kernel
#
KERNEL := kernel.elf
KERNEL_OBJECTS := start.o vga.o kernel.o

CLEAN += $(KERNEL) $(KERNEL_OBJECTS)

$(KERNEL): $(KERNEL_OBJECTS)
	$(CXXC) $(LDFLAGS) -o $@ $^ 

$(KERNEL_OBJECTS):
	$(CXXC) $(CFLAGS) -c start.s -o start.o
	$(CXXC) $(CFLAGS) -c vga.cpp -o vga.o
	$(CXXC) $(CFLAGS) -c kernel.cpp -o kernel.o

clean:
	rm $(CLEAN)

