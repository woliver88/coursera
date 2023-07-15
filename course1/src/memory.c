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

ptrdiff_t my_memdiff(uint8_t *src, uint8_t *dst)
{
  // ptdiff_t objects are 8 bytes in length
  ptrdiff_t memdif = src - dst;
  return memdif;
}

uint8_t abs_uint8_t(ptrdiff_t value)
{
  // arithmetic right shift https://open4tech.com/logical-vs-arithmetic-shift/
  ptrdiff_t mask = value >> 63;
  value = value ^ mask;
  value = value - mask;
  return value;
}

// uint8_t *my_memmove_wrong(uint8_t *src, uint8_t *dst, size_t length)
// {
//   // check difference between pointer start locations is greater than 'length'
//   // this function is incorrect - should still complete copy
//   ptrdiff_t memdif = my_memdiff(src, dst);
//   ptrdiff_t abs = abs_uint8_t(memdif);
//   if (abs < length)
//   {
//     PRINTF("Length of array: %lu\n", length);
//     PRINTF("Distance between pointers: %lu\n", abs);
//   }
//   else
//   {
//     for (int i = 0; i < length; i++)
//     {
//       *dst = *src;
//       dst++;
//       src++;
//     }
//   }
//   // return dst;
// }

uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length)
{
  // Copy to an array and then from array to destination
  uint8_t temp_array[length];
  for (int i = 0; i < length; i++)
  {
    *(temp_array + i) = *src;
    src++;
  }

  for (int i = 0; i < length; i++)
  {
    *(dst + i) = *(temp_array + i);
  }
  // return dst;
}

uint8_t *my_memcopy(uint8_t *src, uint8_t *dst, size_t length)
{
  for (int i = 0; i < length; i++)
  {
    *(dst + i) = *(src + i);
  }
  return dst;
}

uint8_t *my_memset(uint8_t *src, size_t length, uint8_t value)
{
  for (int i = 0; i < length; i++)
  {
    *(src + i) = value;
  }
  return src;
}

uint8_t *my_memzero(uint8_t *src, size_t length)
{
  for (int i = 0; i < length; i++)
  {
    *(src + i) = *(src + i) & 0;
  }
  return src;
}

uint8_t *my_reverse(uint8_t *src, size_t length)
{
  uint8_t buffer[length];
  for (int i = 0; i < length; i++)
  {
    buffer[(length - 1) - i] = *(src + i);
  }
  for (int i = 0; i < length; i++)
  {
    *(src + i) = buffer[i];
  }
  return src;
}

int32_t *reserve_words(size_t length)
{
  int32_t *mem_pointer;
  // calloc returns a void pointer by default until it is cast
  mem_pointer = (int32_t *)calloc(length, sizeof(int32_t));
  return mem_pointer;
}

void free_words(int32_t *src)
{
  free(src);
}
