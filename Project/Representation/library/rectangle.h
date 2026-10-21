/**
 * @file rectangle.h
 * @brief Definition of the Rectangle structure.
 */

#include "point.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H

/**
 * @struct Rectangle_s
 * @brief Represents a rectangle defined by top-left origin, height, and width.
 */

typedef struct Rectangle_s
{
    Point_t *point;
    int height;
    int width;

} Rectangle_t;

#endif