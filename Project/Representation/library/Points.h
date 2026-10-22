#ifndef POINTS_H
#define POINTS_H
#include <stdio.h>
#include "point.h"

Point_t *create_point(char *message);
void modify_point(char *message, Point_t *point);
void print_a_point(Point_t *point);
void delete_point(Point_t *point);

#endif