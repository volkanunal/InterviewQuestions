#ifndef INCLUDED_MAP_INTERFACE
#define INCLUDED_MAP_INTERFACE

#include "stdbool.h"

struct map_interface;

struct map_interface* create_map_interface(void);

void set_size(struct map_interface* self, const int width, const int height);

void get_size(const struct map_interface* self, int* width, int* height);

void set_border(struct map_interface* self, const int x, const int y);

void clear_border(struct map_interface* self, const int x, const int y);

bool is_border(const struct map_interface* self, const int x, const int y);

void show(const struct map_interface* self);


#endif