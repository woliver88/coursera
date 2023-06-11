#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------

# Platform Overrides
# HOST / MSP432
PLATFORM = HOST

# General Compiler Flags
CPPFLAGs = -E

CFLAGS = 	-Wall	\
		 	-Werror	\
			-g		\
			-O0		\
			-std=c99

# Platform / Architecture Specific Flags
ifeq ($(PLATFORM),HOST)
	CC = gcc

else ifeq ($(PLATFORM),MSP432)
	CC = arm-none-eabi-gcc
	
	CPU := cortex-m4
	ARCH := armv7e-m
	SPECS := nosys.specs

	LD = msp432p401r.lds
	CFLAGS_SPEC = -T $(LD)	\
				-mcpu=$(CPU)		\
				-mthumb				\
				-march=$(ARCH)		\
				-mfloat-abi=hard	\
				-mfpu=fpv4-sp-d16	\
				--specs=$(SPECS)	
endif

# Bring in source files
include sources.mk

# Define Object / Intermediate files
OBJS = $(SRCS:.c=.o)
ASMFILES = $(SRCS:.c=.asm)
DFILES = $(SRCS:.c=.d)
IFILES = $(SRCS:.c=.i)

TARGET = c1m2.out
MAP_FILE = $(TARGET:.out=.map)

# -E only runs the pre processor
%.i: %.c
	$(CC) $(CPPFLAGs) $< $(CFLAGS) $(CFLAGS_SPEC) -o $@

# Dump the assemble code -S includes source code alongside
# -d specifies that this is an object file
%.asm: %.o
# $(CC) -S $< $(CFLAGS) $(CFLAGS_SPEC) $(INCLUDES) -o $
# $(CC:gcc=objdump) -d -S %.o > $@
	$(CC:gcc=objdump) -S $< > $@

%.o: %.c
	$(CC) -c -MMD $< $(CFLAGS) $(CFLAGS_SPEC) -D$(PLATFORM) $(INCLUDES) -o $@

# Compile all object files
.PHONY: compile-all
compile-all: $(OBJS)
# $(OBJS): $(SRCS)
# 	$(CC) -c -MMD $< $(CFLAGS) $(CFLAGS_SPEC) -D$(PLATFORM) $(INCLUDES) -o $@

# Complete build from object files generating map file
.PHONY: build
build: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -D$(PLATFORM) $(INCLUDES) $^ $(CFLAGS) $(CFLAGS_SPEC) -Xlinker -Map=$(MAP_FILE) -o $@
	$(CC:gcc=size) $@

# Remove all generated files
.PHONY: clean
clean: 
	rm $(OBJS) $(MAP_FILE) $(DFILES) $(ASMFILES) $(IFILES) $(TARGET)
