# Source files
INCLUDES = ./misc.h
SCRS = 	./misc.c \
		./main.c

# Output files
TARGET = program.OUT
OBJS = $(SCRS:.c=.o)
MAP_FILE = $(TARGET:.out=.map)
ASMFILES = $(SRCS:.c=.asm)

# Linker file
LD = ./msp432p401r.lds
# Added 
LDFLAGS = -L /lib/x86_64-linux-gnu/libgcc_s.so.1


# Compiler
CC=gcc

# To create .o objectfiles 
%.o: %.c
	$(CC) -c -MMD $< -o $@

# To create .map file

.PHONY: build
build: $(TARGET)
$(TARGET): $(OBJS)
# $(CC) -v $^  -T $(LD) -Xlinker -Map=$(MAP_FILE) -o $@ - This is for VM gcc compiler - if submit use this
	$(CC) -v $^ -T $(LD) $(LDFLAGS) -Xlinker -Map=$(MAP_FILE) -o $@

# Clear non source files 
.PHONY: clean
clean:
	rm $(OBJS) $(MAP_FILE) $(ASMFILES) *.d