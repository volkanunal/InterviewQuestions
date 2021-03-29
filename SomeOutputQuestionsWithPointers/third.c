/* C program to check little vs big endian */

#include "stdint.h"
#include "stdio.h"

int main()
{
    uint32_t u32_val = 1;
    uint8_t* u8_val = (uint8_t*)&u32_val;

    if (*u8_val == 1) printf("\r\n Little Endian");
    else printf("\r\n Big endian");
}