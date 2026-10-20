#include "point.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H

typedef struct Rectangle_s
{
    Point_t *point;
    int height;
    int width;

} Rectangle_t;

#endif