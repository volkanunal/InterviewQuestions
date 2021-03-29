#include "stdio.h"
#include "stdint.h"

int main()
{
    int ival = 10;
    char cval = 7;
    unsigned short usval = 3;

    printf("\r\n %d, %d, %d", sizeof(ival), sizeof(cval), sizeof(cval + usval));
    
}