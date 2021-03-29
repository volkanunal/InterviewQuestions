// Write a program to count number of 1s in the binary representation of an integer.

#include "stdint.h"
#include "stdio.h"

int count_of_set_bits(uint32_t u32_val)
{
    int ret = 0;
    for (int i = 0; i < 32; ++i)
    {
        if ((u32_val >> i) & 1)
        {
            ret++;
        }
    }

    return ret;
}

int main()
{
    printf("\r\n %i", count_of_set_bits(15));
}
