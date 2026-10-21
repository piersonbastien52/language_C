/**
 * @file circle.h
 * @brief Definition of the Circle structure.
 */

#include "point.h"
#ifndef CIRCLE_H
#define CIRCLE_H

/**
 * @struct Circle_s
 * @brief Represents a geometric circle with a radius and center point.
 */

typedef struct Circle_s
{
    int r;
    Point_t *center;
} Circle_t;

#endif