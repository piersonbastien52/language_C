/**
 * @file ellipse.h
 * @brief Definition of the Ellipse structure.
 */

#include "point.h"
#ifndef ELLIPSE_H
#define ELLIPSE_H

/**
 * @struct Ellipse_s
 * @brief Represents an ellipse with horizontal/vertical radii and center point.
 */

typedef struct Ellipse_s
{
    int rx;
    int ry;
    Point_t *center;

} Ellipse_t;

#endif