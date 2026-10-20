
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

typedef enum
{
    FORM_RECTANGLE,
    FORM_SQUARE,
    FORM_CIRCLE,
    FORM_ELLIPSE,
    FORM_LINE,
} Shape_e;

typedef struct
{
    Shape_e type;
    union
    {
        Circle_t *circle;
        Ellipse_t *ellipse;
        Rectangle_t *rectangle;
        Square_t *square;
        Line_t *lines;

    } data;
    Styles_t *styles;
} Shape_t;

#endif