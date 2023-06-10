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

# Platform Specific Source and Includes
ifeq ($(PLATFORM),HOST)
	SOURCES = 	./main.c 	\
				./memory.c	\
	
	INCLUDES =	-I./common 	

else ifeq ($(PLATFORM),MSP432)
	SOURCES = 	./main.c 	\
				./memory.c	\
				./interrupts_msp432p401r_gcc.c	\
				./startup_msp432p401r_gcc		\
				./system_msp432p401r.c			\

	INCLUDES = 	-I../common		\
				-I../msp432		\
				-I../CMSIS
endif

