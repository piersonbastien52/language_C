/**
 * @file enum.h
 * @brief Unified Shape data structures and linked list containers.
 */

#ifndef ENUM_H
#define ENUM_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "styles.h"
#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "line.h"
#include "square.h"

/**
 * @enum Shape_e
 * @brief Enumeration of supported geometric shape types.
 */

typedef enum
{
    FORM_RECTANGLE,
    FORM_SQUARE,
    FORM_CIRCLE,
    FORM_ELLIPSE,
    FORM_LINE,
} Shape_e;

/**
 * @struct Shape_t
 * @brief Generic shape wrapper storing shape type, pointer data, and applied styles.
 */

typedef struct
{
    Shape_e type; /**< Type of the shape */
    union
    {
        Circle_t *circle;
        Ellipse_t *ellipse;
        Rectangle_t *rectangle;
        Square_t *square;
        Line_t *line;

    } data;           /**< Polymorphic union holding the specific shape structure pointer */
    Styles_t *styles; /**< Associated graphical styles */
} Shape_t;

typedef struct List_shape_s List_shape_t;

/**
 * @struct List_shape_s
 * @brief Doubly-linked list node holding a single Shape_t.
 */

struct List_shape_s
{
    List_shape_t *next;     /**< Pointer to the next node */
    List_shape_t *previous; /**< Pointer to the previous node */
    Shape_t shape;          /**< Embedded shape structure */
};

/**
 * @struct Landmark_s
 * @brief Container head for the shape linked list.
 */

typedef struct Landmark_s
{
    List_shape_t *start; /**< Pointer to the first node */
    unsigned int length; /**< Number of items in the list */

} Landmark_t;

#endif