#include "stdio.h"
#include "stdint.h"

int main()
{
    unsigned x=1;
    signed char y=-1;

    if(x>y){
        printf("x>y");
    }
    else {
        printf("y>x");
    }
}

