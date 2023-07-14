CC := clang++
FLAGS :=                \
	-target i686-elf    \
	-ffreestanding      \
	-std=c++20			\
	-O0                 \
	-fno-exceptions 	\
	-fno-rtti 			\
	-Wall -Wextra
CFLAGS := $(FLAGS)      \
	-masm=att           \
	-fno-threadsafe-statics\
	-mcmodel=large      \
	-mno-red-zone       \
	-mno-mmx            \
	-mno-sse            \
	-mno-sse2 
LDFLAGS := $(FLAGS)     \
	-T source/linker.ld \
	-nostdlib           \
	-lgcc

bbos.bin: build/kernel.o build/vga.o build/boot.o
	$(CC) $(LDFLAGS) -o $@ $^

build/kernel.o: source/kernel.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/vga.o: source/vga.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

build/boot.o: source/boot.s
	$(CC) $(CFLAGS) -o $@ -c $^

.PHONY: qemu
qemu: bbos.bin
	qemu-system-x86_64 -kernel bbos.bin

.PHONY: clean
clean:
	@rm bbos.bin build/* 

