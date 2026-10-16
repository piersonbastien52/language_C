#include "point.h"
#ifndef POLYLINES_H
#define POLYLINES_H

typedef struct Polylines_s Polylines_t;

struct Polylines_s
{
  Polylines_t *next;
  Point_t point;
};

typedef struct List_polylines_s
{
  Polylines_t *start;
  unsigned int length;
} List_polylines_t;

List_polylines_t *add_node(List_polylines_t *chain, Polylines_t *link);
int get_value(List_polylines_t *chain, unsigned int index);
void print_polylines(List_polylines_t *chain);

#endif