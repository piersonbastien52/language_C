/**
 * @file line.h
 * @brief Definition of the Line structure.
 */

#include "point.h"
#ifndef LINE_H
#define LINE_H

/**
 * @struct Line_s
 * @brief Represents a line segment connecting two points.
 */

typedef struct Line_s
{
    Point_t *point1;
    Point_t *point2;

} Line_t;

#endif