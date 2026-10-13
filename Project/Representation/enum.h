
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
        Circle_s *circle;
        Ellipse_s *ellipse;
        Rectangle_s *rectangle;
        Square_s *square;
        Line_s *lines;
        Polylines_t *polylines;
        Styles_s *style;
    } data;
} Shape_s;

#endif