#include <stdio.h>
#include "stdint.h"

int main()
{
    uint32_t test[2] = {0x12349978, 0x87654321};
    
    uint8_t* ptr = (uint8_t*)&test;
    
    ptr++;
    
    printf("\r\n %x", *ptr);

    return 0;
}
