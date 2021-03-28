#include <stdio.h>

#include "MapInterface.h"
#include "ZoneCountInterface.h"

int main()
{
    struct zone_counter_interface* pzci = create_new_counter_interface();

    struct map_interface* pmi = create_map_interface();

    set_size(pmi, 10, 7);
    
    for (int i = 0; i < 7; ++i)
    {
        set_border(pmi, 1, i);
    }    

    for (int i = 2; i < 10; ++i)
    {
        set_border(pmi, i, 3);
    }

    for (int i = 0; i < 3; ++i)
    {
        set_border(pmi, 2 + i, i);
    }

    for (int i = 0;  i < 3; ++i)
    {
        set_border(pmi, 5, 4 + i);
    }
    
    init(pzci, pmi);
    
    printf("\r\n %i", solve(pzci));
}