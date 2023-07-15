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
 * @file stats.c
 * @brief Basic statistic and array manipulation functions
 *
 *
 * @author William Chaundy
 * @date 30-05-2023
 *
 */

// #include <stdio.h>
// PRINTF defined to override printf
#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

// arrays are pointers - specific definition of pointer not required
unsigned char sort_array(unsigned char array[], unsigned int array_size)
{
  for (int i = 0; i < array_size; ++i)
  {
    int max_idx = i;
    for (int j = i; j < array_size; ++j)
    {
      if (array[j] > array[max_idx])
      {
        max_idx = j;
      }
    }
    int temp = array[i];
    array[i] = array[max_idx];
    array[max_idx] = temp;
  }

  return 0;
}

float mean(unsigned char array[], unsigned int array_size)
{
  int sum = 0;
  for (int i = 0; i < array_size; ++i)
  {
    sum += array[i];
  }
  return (float)sum / array_size;
}

float median(unsigned char array[], unsigned int array_size)
{
  int idx_0 = SIZE / 2;
  unsigned char sort_array(unsigned char array[], unsigned int array_size);
  sort_array(array, array_size);
  // printf("float div: %i\n", SIZE % 2);
  if (SIZE % 2 == 0)
  {
    // printf("index: %i Number: %i\n", idx_0, array[idx_0]);
    // printf("index: %i Number: %i\n", idx_0 + 1, array[idx_0 + 1]);
    return (float)(array[idx_0] + array[idx_0 + 1]) /
           2;
  }
  else
  {
    // printf("index: %i Number: %i\n", idx_0 + 1, array[idx_0 + 1]);
    return (float)array[idx_0 + 1];
  }
}

unsigned char max(unsigned char array[], unsigned int array_size)
{
  int max = array[0];
  for (int i = 1; i < array_size; ++i)
  {
    if (array[i] > max)
    {
      max = array[i];
    }
  }
  return max;
}

unsigned char min(unsigned char array[], unsigned int array_size)
{
  int min = array[0];
  for (int i = 1; i < array_size; ++i)
  {
    if (array[i] < min)
    {
      min = array[i];
    }
  }
  return min;
}

void print_array(unsigned char array[], unsigned int array_size)
{
#ifdef VERBOSE
  PRINTF("[");
  for (int i = 0; i < array_size; ++i)
  {
    PRINTF("%i ", array[i]);
  }
  PRINTF("]\n");
#endif
}

void print_statistics(unsigned char array[], unsigned int array_size)
{
  float mean_val = mean(array, array_size);
  float median_val = median(array, array_size);
  int max_val = max(array, array_size);
  int min_val = min(array, array_size);

#ifdef VERBOSE
  PRINTF("The mean of this array is: %f\n", mean_val);
  PRINTF("The median of this array is: %f\n", median_val);
  PRINTF("The maximum value of this array is: %i\n", max_val);
  PRINTF("The minimum value of this array is: %i\n", min_val);
#endif
}

void main()
{

  unsigned char test[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
                              114, 88, 45, 76, 123, 87, 25, 23,
                              200, 122, 150, 90, 92, 87, 177, 244,
                              201, 6, 12, 60, 8, 2, 5, 67,
                              7, 87, 250, 230, 99, 3, 100, 90};

  /* Other Variable Declarations Go Here */

  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  sort_array(test, SIZE);
  print_array(test, SIZE);
  print_statistics(test, SIZE);
}

/* Add other Implementation File Code Here */
