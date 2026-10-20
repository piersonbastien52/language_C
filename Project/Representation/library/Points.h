#ifndef POINTS_H
#define POINTS_H
#include <stdio.h>
#include "point.h"

int ask_navigation(char *menu, int min, int max);
void modify_point(char *message, Point_t *point);
void print_a_point(Point_t *point);
void delete_point(Point_t *point);

#endif