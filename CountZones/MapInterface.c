#include "stdlib.h"
#include "stdint.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

typedef struct
{
    uint8_t* map;
    int x;
    int y;

}map_interface;

map_interface* create_map_interface(void)
{   
    map_interface* ret = malloc(sizeof(map_interface));
    if (ret == NULL)
        return NULL;

    ret -> x = 0;
    ret -> y = 0;
}

void set_size(map_interface* self, const int width, const int height)
{
    if (self == NULL)
    {
        exit(0);
    }
       
    self -> x = width;
    self -> y = height;
    self -> map = (uint8_t*)malloc(self -> x *  self -> y * sizeof(uint8_t));
    memset(self -> map, 0, self -> x * self -> y);
}

void get_size(const  map_interface* self, int* width, int* height)
{
    if (self == NULL)
    {
        exit(0);
    }

    *width = self -> x;
    *height = self -> y;
}

void set_border(map_interface* self, const int x, const int y)
{
    if (self == NULL)
    {
        exit(0);
    }

    self -> map[(self -> x * y) + x] = 'X';
}

void clear_border(map_interface* self, const int x, const int y)
{
    if (self == NULL)
    {
        exit(0);
    }

    self -> map[(self -> x * y) + x] = 0;
}

bool is_border(const map_interface* self, const int x, const int y)
{
    if (self == NULL)
    {
        exit(0);
    }

    if (self -> map[(self -> x * y) + x] == 'X')
    {
        return true;
    }

        return false;
}

void show(const map_interface* self)
{
    if (self == NULL)
    {
        exit(0);
    }
    
    for (int i = 0; i < (self -> x ) + 2 ; ++i)
    {
        printf("X");
    }
    
    for (int y = 0; y < self -> y; ++y)
    {
        printf("\r\nX");

        for (int x = 0; x < self -> x; ++x)
        {           
            printf("%c", self -> map[(y * self -> x) + x]);
        }

        printf("X");
    }

    printf("\r\n");
    
    for (int i = 0; i < (self -> x) + 2; ++i)
    {
        printf("X");
    }    
}

