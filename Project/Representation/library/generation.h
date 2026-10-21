#ifndef GENERATION_H
#define GENERATION_H
#include "enum.h"

Landmark_t *add_node(Landmark_t *chain, List_shape_t *link);
void free_node(List_shape_t *node);
void free_shape(Shape_t *shape);
int supp_node(Landmark_t *chain, unsigned int index);

#endif