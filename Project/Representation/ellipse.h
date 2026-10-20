#include "point.h"
#ifndef ELLIPSE_H
#define ELLIPSE_H

typedef struct Ellipse_s
{
    int rx;
    int ry;
    Point_t *center;

} Ellipse_t;

#endif