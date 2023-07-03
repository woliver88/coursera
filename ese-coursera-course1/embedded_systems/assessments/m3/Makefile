# Source files
SCRS = 	./misc.c \
		./main.c

# Output files
TARGET = program.OUT
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
# $(CC) -v $^  -T $(LD) -Xlinker -Map=$(MAP_FILE) -o $@ - This is for VM gcc compiler - if submit use this	
# -N - do not page align data, do not make text read only unsure what this mean - throws error without due to space limits
# -Wl passes comma separated arguments to 'ld' (linker binary)
	$(CC) -v $^ $(CFLAGS) $(CFLAGS_SPEC) -Xlinker -Map=$(MAP_FILE) -o $@

# Clear non source files 
.PHONY: clean
clean:
	rm $(OBJS) $(MAP_FILE) $(ASMFILES) *.dm