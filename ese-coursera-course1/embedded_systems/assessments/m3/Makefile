# Source files
SCRS = 	./misc.c \
		./main.c

# Output files
TARGET = program.out
OBJS = $(SCRS:.c=.o)
MAP_FILE = $(TARGET:.out=.map)
ASMFILES = $(SRCS:.c=.asm)

CFLAGS = 	-Wall	\
		 	-Werror	\
			-g		\
			-O0		\
			-std=c99

CPU := cortex-m4
ARCH := armv7e-m
SPECS := nosys.specs

# Linker file
LD = ./msp432p401r.lds

CFLAGS_SPEC = -T $(LD)	\
				-mcpu=$(CPU)		\
				-mthumb				\
				-march=$(ARCH)		\
				-mfloat-abi=hard	\
				-mfpu=fpv4-sp-d16	\
				--specs=$(SPECS)

# Added 
# LDFLAGS = -L /lib/x86_64-linux-gnu/libgcc_s.so.1

# Compiler
CC = arm-none-eabi-gcc

# To create .o objectfiles 
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CFLAGS_SPEC) -o $@

# To create .map file

.PHONY: build
build: $(TARGET)
$(TARGET): $(OBJS)
# -Wl passes comma separated arguments to 'ld' (linker binary)
	$(CC) -v $^ $(CFLAGS) $(CFLAGS_SPEC) -Xlinker -Map=$(MAP_FILE) -o $@

.PHONY: memory
memory:
# -v will order by numberic address value (default is -n order by name)
	nm -v $(TARGET)

.PHONY: objd 
objd:
# Use: make objd FILE=main.o
# objdump displays information from objfile
# -S mixes disassemble code with source code
# -d displays assembler code for all executable sections
# -t displays contents of symbol table
	objdump -S $(FILE)

# Clear non source files 
.PHONY: clean
clean:
	rm $(OBJS) $(MAP_FILE) $(ASMFILES) $(TARGET)