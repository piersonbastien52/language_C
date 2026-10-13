#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Representation/styles.h"
#include "Representation/rectangle.h"
#include "Representation/circle.h"
#include "Representation/ellipse.h"
#include "Representation/line.h"
#include "Representation/square.h"
#include "Representation/polylines.h"
#include "Representation/enum.h"

int switch_shape_choice(int shape_choice, Shape_e Shape_v)
{
    Rectangle_s rect;
    Styles_s style;
    Circle_s circle;
    Ellipse_s ellipse;
    Square_s square;
    Line_s line;

    switch (shape_choice)
    {
    case 1: /*rectangle*/
        printf("rect, x = %u, y = %u, height = %u, width = %u\n", rect.x, rect.y, rect.width, rect.height);
        break;
    case 2: /*square*/
        printf("square, x = %u, y = %u, height = %u\n", square.x, square.y, rect.height);
        break;
    case 3: /*circle*/
        printf("circle, r = %u, cx = %u, cy = %u\n", circle.r, circle.cx, circle.cy);
        break;
    case 4: /*ellipse*/
        printf("ellipse, rx = %u, ry = %u, cx = %u, cy = %u\n", ellipse.rx, ellipse.ry, ellipse.cx, ellipse.cy);
        break;
    case 5: /*line*/
        printf("line, x1 = %u, y1 = %u, x2 = %u, y2 = %u\n", line.x1, line.y1, line.x2, line.y2);
        break;
    case 6: /*style*/
        printf("styles, stroke = %s, fill = %s, stroke_opacity = %s, fill_opacity = %s, stroke_width = %s, tx =, ty = %u, angle = %u\n", style.stroke, style.fill, style.stroke_opacity, style.fill_opacity, style.stroke_width, style.tx, style.ty, style.angle);
        break;

    default:
        break;
    }
}
void print_polylines(List_polylines_t *chain)
{
    if (chain == NULL)
    {
        printf("polyline n'a pas été défini\n");
        return;
    }
    Polylines_t *temp = chain->start;
    while (temp != NULL)
    {
        printf("x = %u, y = %u \n", temp->x, temp->y);
        temp = temp->next;
    }
};