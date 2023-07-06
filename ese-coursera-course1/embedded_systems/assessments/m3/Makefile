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
# displays memory location, followed by type
	nm -v $(TARGET)

.PHONY: objd 
objd:
# Use: make objd FILE=main.o FLAG = "-S | -t | -d "

# objdump displays information from objfile
# -S mixes disassemble code with source code
# -d displays assembler code for all executable sections
# -t displays contents of symbol table

# Typical appearance for -t:
# https://stackoverflow.com/questions/6666805/what-does-each-column-of-objdumps-symbol-table-mean
# 0000000000000000  w      *UND*  0000000000000000              __gmon_start__
# First column: is memory location
# 2nd: flags to indicate info - g/l global/local, d debuggin symbol, F/f File/function 
# 3rd: location e.g. .bss / .text
# 4rd: Size
# 5th: Name

# Typical appearance for -S:
# 48 0f54	adds r3, #0
# '48' refers to location in memory (hex)
# following four '0f65' refer to two bytes of code (hex)
# Instruction in native assembly follows
	$(CC:gcc=objdump) $(FLAG) $(FILE)

# Clear non source files 
.PHONY: clean
clean:
	rm $(OBJS) $(MAP_FILE) $(ASMFILES) $(TARGET)