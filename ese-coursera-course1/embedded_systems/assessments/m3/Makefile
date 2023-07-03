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
# -N - do not page align data, do not make text read only unsure what this mean - throws error without due to space limits
# -Wl passes comma separated arguments to 'ld' (linker binary)
	$(CC) -v $^ -T $(LD) $(LDFLAGS) -Wl,-Map=$(MAP_FILE),-N -o $@

# Clear non source files 
.PHONY: clean
clean:
	rm $(OBJS) $(MAP_FILE) $(ASMFILES) *.d