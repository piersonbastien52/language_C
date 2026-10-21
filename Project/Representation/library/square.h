/**
 * @file square.h
 * @brief Definition of the Square structure.
 */

#include "point.h"
#ifndef SQUARE_H
#define SQUARE_H

typedef struct Square_s

/**
 * @struct Square_s
 * @brief Represents a square defined by an origin point and side length.
 */

{
    Point_t *point;
    int height;

} Square_t;

#endif
