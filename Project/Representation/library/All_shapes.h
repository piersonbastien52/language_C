#ifndef ALL_SHAPES_H
#define ALL_SHAPES_H
#include "circle.h"
#include "styles.h"
#include "enum.h"

Circle_t *create_circle(void);
Styles_t *circle_styles(void);
void modify_circle(Circle_t *circle);
void print_circle(Circle_t *circle, Shape_t *shape);
void delete_circle(Circle_t *circle, Shape_t *shape);

Ellipse_t *create_ellipse(void);
Styles_t *ellipse_styles(void);
void modify_ellipse(Ellipse_t *ellipse);
void print_ellipse(Ellipse_t *ellipse, Shape_t *shape);
void delete_ellipse(Ellipse_t *ellipse, Shape_t *shape);

Rectangle_t *create_rectangle(void);
Styles_t *rectangle_styles(void);
void modify_rectangle(Rectangle_t *rectangle);
void print_rectangle(Rectangle_t *rectangle, Shape_t *shape);
void delete_rectangle(Rectangle_t *rectangle, Shape_t *shape);

Square_t *create_square(void);
Styles_t *square_styles(void);
void modify_square(Square_t *square);
void print_square(Square_t *square, Shape_t *shape);
void delete_square(Square_t *square, Shape_t *shape);

Line_t *create_ligne(void);
Line_t *line_styles(void);
void modify_line(Line_t *line);
void print_line(Line_t *line, Shape_t *shape);
void delete_line(Line_t *line, Shape_t *shape);

#endif