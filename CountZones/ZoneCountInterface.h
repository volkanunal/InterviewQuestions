#ifndef INCLUDED_ZONE_COUNTER_INTERFACE
#define INCLUDED_ZONE_COUNTER_INTERFACE

#include "MapInterface.h"

struct zone_counter_interface;

struct zone_counter_interface* create_new_counter_interface(void);

void init(struct zone_counter_interface* self_zone, struct map_interface* self_map);

int solve(const struct zone_counter_interface* self_zone);


#endif