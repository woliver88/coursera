#ifndef __DATA_H__
#define __DATA_H__

#define MAX_SIZE (sizeof(int32_t) * 8)
#include <stdint.h>
#include "memory.h"

int32_t abs_int32_t_v2(int32_t value);

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

int exponent(uint8_t value, int exp);

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base);

#endif