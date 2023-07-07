/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

// why file includes its own header file
// Not essential but validates declarations match definitions etc
// https://stackoverflow.com/questions/30817570/whats-the-benefit-for-a-c-source-file-include-its-own-header-file#:~:text=You%20don't%20have%20to,an%20implementation%20before%20finishing%20compilation.
#include "memory.h"
#include <stdint.h>

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char *ptr, unsigned int index, char value)
{
  ptr[index] = value;
}

void clear_value(char *ptr, unsigned int index)
{
  set_value(ptr, index, 0);
}

char get_value(char *ptr, unsigned int index)
{
  return ptr[index];
}

void set_all(char *ptr, char value, unsigned int size)
{
  unsigned int i;
  for (i = 0; i < size; i++)
  {
    set_value(ptr, i, value);
  }
}

void clear_all(char *ptr, unsigned int size)
{
  set_all(ptr, 0, size);
}

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length)
{
}
