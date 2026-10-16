
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
#include "polylines.h"

typedef enum
{
    FORM_RECTANGLE,
    FORM_SQUARE,
    FORM_CIRCLE,
    FORM_ELLIPSE,
    FORM_LINE,
    FORM_POLYLINES,
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
        Polylines_t *polylines;
        Styles_t *style;
    } data;
} Shape_s;

#endif