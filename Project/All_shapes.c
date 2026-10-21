#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Representation/library/Points.h"
#include "Representation/library/apply_style.h"
#include "Representation/library/color.h"
#include "Representation/library/ask_for_a_flint.h"
#include "Representation/library/Points.h"
#include "Representation/library/point.h"
#include "Representation/library/styles.h"
#include "Representation/library/rectangle.h"
#include "Representation/library/circle.h"
#include "Representation/library/ellipse.h"
#include "Representation/library/line.h"
#include "Representation/library/square.h"
#include "Representation/library/enum.h"

Circle_t *create_circle(void)
{
    Circle_t *circle = malloc(sizeof(Circle_t));
    if (circle == NULL)
    {
        return NULL;
    }
    circle->r = ask_for_int("what is the circle's radius ?\n");
    circle->center = create_point("whats is the center's coordonates ?\n");
    return circle;
}

Styles_t *circle_styles(void)
{
    Styles_t *circle = malloc(sizeof(Styles_t));

    if (circle == NULL)
    {
        return NULL;
    }
    else
    {
        create_style(circle);
        return circle;
    }
}

void modify_circle(Circle_t *circle)
{
    printf("The center's coordonates are :(%d, %d)\n", circle->center->x, circle->center->y);
    free(circle->center);
    circle->center = create_point();
    printf("the new coordonates are : (%d, %d)\n", circle->center->x, circle->center->y);

    printf("The old value of the radius is %d\n", circle->r);
    circle->r = ask_for_int("what is the new radius ?\n");
    printf("the new radius is : %d\n", circle->r);
}

void print_circle(Circle_t *circle, Shape_t *shape)
{
    printf("---Parameters of Circle---\n");
    printf("The value of the radius is : %d\n", circle->r);
    printf("The value of the coordonate x of the center is : %d\n", circle->center->x);
    printf("The value of the coordonate x of the center is :%d\n", circle->center->y);
    print_style(shape->styles);
}

void delete_circle(Circle_t *circle)
{
    if (circle == NULL)
    {
        return;
    }
    else
    {
        free(circle->center);
        free(circle);
    }
}

Ellipse_t *create_ellipse(void)

{

    Ellipse_t *ellipse = malloc(sizeof(Ellipse_t));
    if (ellipse == NULL)
    {
        return NULL;
    }
    ellipse->rx = ask_for_int("what is the first radius of your ellipse ?\n");
    ellipse->ry = ask_for_int("what is the second radius of your ellipse ?\n");
    ellipse->center = create_point("What is the center's coordonates ?\n");
    return ellipse;
}

Styles_t *ellipse_styles(void)

{

    Styles_t *ellipse = malloc(sizeof(Styles_t));
    if (ellipse == NULL)
    {
        return NULL;
    }
    else
    {
        create_style(ellipse);
        return ellipse;
    }
}

void modify_ellipse(Ellipse_t *ellipse)

{
    printf("The center's coordonates are :(%d, %d)\n", ellipse->center->x, ellipse->center->y);
    free(ellipse->center);
    ellipse->center = create_point();
    printf("the new coordonates are : (%d, %d)\n", ellipse->center->x, ellipse->center->y);

    printf("The old value of the first radius is %d\n", ellipse->rx);
    ellipse->rx = ask_for_int("what is the new radius ?\n");
    printf("the new radius is : %d\n", ellipse->rx);

    printf("The old value of the second radius is %d\n", ellipse->ry);
    ellipse->ry = ask_for_int("what is the new radius ?\n");
    printf("the new radius is : %d\n", ellipse->ry);
}

void print_ellipse(Ellipse_t *ellipse, Shape_t *shape)

{
    printf("---Parameters of ellipse---\n");
    printf("The value of the first radius is : %d\n", ellipse->rx);
    printf("The value of the second radius is : %d\n", ellipse->ry);
    printf("The value of the coordonate x of the center is : %d\n", ellipse->center->x);
    printf("The value of the coordonate y of the center is :%d\n", ellipse->center->y);
    print_style(shape->styles);
}

void delete_ellipse(Ellipse_t *ellipse)
{
    if (ellipse == NULL)
    {
        return;
    }
    else
    {
        free(ellipse->center);
        free(ellipse);
    }
}

Rectangle_t *create_rectangle(void)
{
    Rectangle_t *rectangle = malloc(sizeof(Rectangle_t));
    if (rectangle == NULL)
    {
        return NULL;
    }
    rectangle->point = create_point("What is the origin's coordonate of the rectangle ?\n");
    rectangle->height = ask_for_int("what is the height of the rectangle ?\n");
    rectangle->width = ask_for_int("what is the width of the rectangle ?\n");
    return rectangle;
}

Styles_t *rectangle_styles(void)
{

    Styles_t *rectangle = malloc(sizeof(Styles_t));
    if (rectangle == NULL)
    {
        return NULL;
    }
    else
    {
        create_style(rectangle);
        return rectangle;
    }
}

void modify_rectangle(Rectangle_t *rectangle)
{
    printf("The old coordonates of the origin are (%d, %d)\n", rectangle->point->x, rectangle->point->y);
    free(rectangle->point);
    rectangle->point = create_point();
    printf("the new coordopnates are : (%d, %d)\n", rectangle->point->x, rectangle->point->y);

    printf("The old value of the height is %d\n", rectangle->height);
    rectangle->height = ask_for_int("what is the new height ?\n");
    printf("the new height is : %d\n", rectangle->height);

    printf("The old value of the width is : %d\n", rectangle->width);
    rectangle->width = ask_for_int("what is the new width ?\n");
    printf("the new width is : %d\n", rectangle->width);
}

void print_rectangle(Rectangle_t *rectangle, Shape_t *shape)

{

    printf("---Parameters of rectangle---\n");
    printf("The value of the origin's coordonates are :(%d, %d)\n", rectangle->point->x, rectangle->point->y);
    printf("the height of the rectangle is : %d\n", rectangle->height);
    printf("The width of the rectangle is  :%d\n", rectangle->width);
    print_style(shape->styles);
}

void delete_rectangle(Rectangle_t *rectangle)
{
    if (rectangle == NULL)
    {
        return;
    }
    else
    {
        free(rectangle->point);
        free(rectangle);
    }
}

Square_t *create_square(void)
{
    Square_t *square = malloc(sizeof(Square_t));
    if (square == NULL)
    {
        return NULL;
    }
    square->point = create_point("What is the origin's coordonates of the square ?\n");
    square->height = ask_for_int("what is the height of the square ?\n");
    return square;
}

Styles_t *square_styles(void)
{

    Styles_t *square = malloc(sizeof(Styles_t));
    if (square == NULL)
    {
        return NULL;
    }
    else
    {
        create_style(square);
        return square;
    }
}

void modify_square(Square_t *square)
{
    printf("The old coordonates of the origin are (%d, %d)\n", square->point->x, square->point->y);
    free(square->point);
    square->point = create_point();
    printf("the new coordopnates are : (%d, %d)\n", square->point->x, square->point->y);

    printf("The old value of the height is %d\n", square->height);
    square->height = ask_for_int("what is the new height ?\n");
    printf("the new height is : %d\n", square->height);
}

void print_square(Square_t *square, Shape_t *shape)

{
    printf("---Parameters of square---\n");
    printf("The value of the origin's coordonates are :(%d, %d)\n", square->point->x, square->point->y);
    printf("The height if the square is : %d\n", square->height);
    print_style(shape->styles);
}

void delete_square(Square_t *square)
{
    if (square == NULL)
    {
        return;
    }
    else
    {
        free(square->point);
        free(square);
    }
}

Styles_t *create_line(void)

{

    Line_t *line = malloc(sizeof(Line_t));
    if (line == NULL)
    {
        return NULL;
    }
    line->point1 = create_point("What is the coordonates of the first point ?\n");
    line->point2 = create_point("what is the coordonatesof the second point ?\n");

    return line;
}

Styles_t *line_styles(void)
{
    Styles_t *line = malloc(sizeof(Styles_t));
    if (line == NULL)
    {
        return NULL;
    }
    else
    {
        create_style(line);
        return line;
    }
}

void modify_line(Line_t *line)

{
    printf("The old coordonates of the origin are (%d, %d)\n", line->point1->x, line->point2->y);
    free(line->point1);
    line->point1 = create_point();
    printf("the new coordonates are : (%d, %d)\n", line->point1->x, line->point2->y);

    printf("The coordonates of the second point are : (%d, %d)\n", line->point2->x, line->point2->y);
    free(line->point2);
    line->point2 = create_point();
    printf("the new coordonates are : (%d, %d)\n", line->point2->x, line->point2->y);
}

void print_line(Line_t *line, Shape_t *shape)

{

    printf("---Parameters of line---\n");

    printf("The value of the origin's coordonates are :(%d, %d)\n", line->point1->x, line->point1->y);
    printf("The coordonates of the second point are :(%d, %d)\n", line->point2->x, line->point2->y);
    print_style(shape->styles);
}

void delete_line(Line_t *line)

{
    if (line == NULL)
    {
        return;
    }
    else
    {
        free(line->point1);
        free(line->point2);
        free(line);
    }
}
