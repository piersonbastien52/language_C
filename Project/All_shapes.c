#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Representation/color.h"
#include "Representation/apply_style.h"
#include "Representation/color.h"
#include "Representation/ask_for_a_flint.h"
#include "Representation/Points.h"
#include "Representation/point.h"
#include "Representation/styles.h"
#include "Representation/rectangle.h"
#include "Representation/circle.h"
#include "Representation/ellipse.h"
#include "Representation/line.h"
#include "Representation/square.h"
#include "Representation/polylines.h"
#include "Representation/enum.h"

Point_t *create_point(void)
{
    Point_t *point = malloc(sizeof(Point_t));
    point->x = ask_for_int("quelle est la valeur x de la coordonée du centre ?\n");
    point->y = ask_for_int("quelle est la valeur y de la coordonée du centre ?\n");
    return point;
}

Circle_t *create_circle(void)
{
    Circle_t *circle = malloc(sizeof(Circle_t));
    circle->r = ask_for_int("quel est le rayon de ton cercle ?\n");
    circle->center = create_point();
    return circle;
}

Styles_t *circle_styles(void)
{
    Styles_t *circle = malloc(sizeof(Styles_t));

    if (circle == NULL)
    {
        return NULL;
    }

    create_outline(circle);
    create_fill(circle);
    create_stroke_opacity(circle);
    create_fill_opacity(circle);
    create_stroke_width(circle);
    create_translate(circle);
    circle->angle = create_rotation();
}

void print_circle(Circle_t *circle)
{
    printf(" La valeur du rayon du cercle est de : %d\n", circle->r);
    printf("la valeur de la coordonée x du centre est de : %d\n", circle->center->x);
    printf("la valeur de la coordonée y du centre est de :%d\n", circle->center->y);
    printf("la couleur appliqué pour le contour est : %s\n", );
}
