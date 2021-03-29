#include <stdio.h>
#include "stdint.h"

int main()
{
    uint32_t u32_val[2] = {0x12349978, 0x87654321};
    
    uint8_t* u8_val = (uint8_t*)&u32_val;
    
    u8_val++;
    
    printf("\r\n %x", *u8_val);

    return 0;
}
