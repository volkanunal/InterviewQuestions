#include "MapInterface.h"
#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#include "string.h"

typedef struct 
{
    struct map_interface* self;

}zone_counter_interface;

zone_counter_interface* create_new_counter_interface(void)
{
    zone_counter_interface* ret = (zone_counter_interface*)malloc(sizeof(zone_counter_interface));

    if (ret == NULL)
    {
        return NULL;
    }

    ret -> self = NULL;

}

void init (zone_counter_interface* self_zone, struct map_interface* self_map)
{
    if (self_zone == NULL || self_map == NULL)
    {
        exit(0);
    }

    self_zone -> self = self_map;

    show(self_zone -> self);
}


//https://en.wikipedia.org/wiki/Flood_fill 
static void Search (const zone_counter_interface* self_zone , int x, int y, int width, int height, bool* visited) {

    if(!is_border(self_zone -> self, x, y) && !visited[y * width + x] && x >= 0 && y >= 0 && x < width && y < height) {
        visited[y * width + x] = true;
        Search(self_zone, x - 1, y, width, height, visited);
        Search(self_zone, x + 1, y, width, height, visited);
        Search(self_zone, x, y - 1, width, height, visited);
        Search(self_zone, x, y + 1, width, height, visited);
    }
}

int solve (const zone_counter_interface* self_zone)
{   
    if (self_zone == NULL)
    {
        return 0;
    }

    int x = 0;
    int y = 0;
    int zone_count = 0;

    get_size(self_zone -> self, &x, &y);

    bool* is_visited = (bool*)malloc(x * y * sizeof(bool));

    memset(is_visited, false, x * y * sizeof(bool));

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < x; ++j)
        {
            if (!is_border(self_zone -> self, j, i) && !is_visited[i * x + j])
            {  
                Search(self_zone, j, i, x, y, is_visited);

                zone_count++;
            }
        }
    }

    printf("\r\n");

    for (int _y = 0; _y <  y; ++_y)
    {
        printf("\r\n");

        for (int _x = 0; _x < x; ++_x)
        {           
            printf("%i", is_visited[(_y * x) + _x]);
        }        
    }

    free(is_visited);

    return zone_count;
}

