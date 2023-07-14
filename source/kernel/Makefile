OBJECTS := \
	kernel.o \
	terminal.o  
CFLAGS := \
	$(CFLAGS)
LFLAGS := \
	-T linker.ld \
	-nostdlib \
	-lgcc
TARGET :=  

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

