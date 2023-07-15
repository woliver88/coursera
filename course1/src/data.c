#include "data.h"
int32_t abs_int32_t_v2(int32_t value)
{
    if (value >= 0)
    {
        return value;
    }
    else
    {
        value = ~(value - 1);
        return value;
    }

    int32_t mask = value >> 31;
    value = value ^ mask;
    value = value - mask;
    return value;
}

uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base)
{
    // 1. Convert to appropriate base form
    // 2. convert these to appropriate ASCII numbers (adding '0' for decimal numberes etc)

    uint8_t fin_idx = 0;            // length of buffer array
    uint8_t buffer[MAX_SIZE] = {0}; // max size of buffer defined at head of file
    uint8_t NEG = data < 0 ? 1 : 0;

    if (NEG)
    {
        data = abs_int32_t_v2(data);
        *ptr = 45;
    }

    // Algorithm to generate corresponding base characters in
    // uint8_t chunks (buffer variable)
    // buffer digits will be in reverse order
    while (data)
    {
        int digit = data % base;
        data = data / base;
        buffer[fin_idx] = digit;
        fin_idx++;
    }

#ifdef VERBOSE_TWO
    // prints full buffer
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d", buffer[i]);
    }
    printf("\n");
#endif

    uint8_t *new_ptr = my_reverse(buffer, MAX_SIZE);

#ifdef VERBOSE_TWO
    // prints numeric representation (ASCII character numeric values)
    for (int i = 0; i < fin_idx; i++)
    {
        printf("%d ", new_ptr[(MAX_SIZE - fin_idx) + i]);
    }
    printf("\n");
#endif

    // Places correct ascii charecters in pointer
    for (int i = (0); i < fin_idx; i++)
    {
        char next;
        int addon = new_ptr[(MAX_SIZE - fin_idx) + i] < 10 ? 48 : 87;
        next = new_ptr[(MAX_SIZE - fin_idx) + i] + addon;
        *(ptr + i + NEG) = next;
    }
    // terminate string with null ASCII char 0
    *(ptr + fin_idx + NEG) = 0;

#ifdef VERBOSE_TWO
    // print the alpha numeric character string of speified base
    for (int i = 0; i < (fin_idx + NEG); i++)
    {
        printf("%c ", *(ptr + i));
    }
    printf("\n");
#endif

    return (fin_idx);
}

int exponent(uint8_t value, int exp)
{
    // for this use case unit8_t is adequate as
    // max value will be 16 (hex)
    int ret = 1;
    for (int i = 0; i < exp; i++)
    {
        ret *= value;
    }

    return ret;
}

int32_t my_atoi(uint8_t *ptr, uint8_t digits, uint32_t base)
{
    int NEG = 0;
    if (*ptr == 45)
    {
        int NEG = 1;
        ptr++;
    }

    int32_t sum = 0;
    for (int i = 0; i < digits; i++)
    {
        uint8_t takeoff = *ptr < 58 ? 48 : 87;
        uint8_t val = (*ptr - takeoff);
        int exp = digits - 1 - i;
        sum = (sum + (val * exponent(base, exp)));
        ptr++;

#ifdef VERBOSE_TWO
        printf("takeoff: %d\n", takeoff);
        printf("val: %d\n", val);
        printf("exp: %d\n", exp);
        printf("Sum: %d\n", sum);
        printf("Value to add %d\n", val * exponent(base, exp));
        printf("Sum + Value %d\n", (sum + (val * exponent(base, exp))));
#endif

        if (NEG)
        {
            sum = (~sum) + 1;
        }
    }
    return sum;
}