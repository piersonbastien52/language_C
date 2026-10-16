#include "point.h"
#include <stdio.h>

int ask_navigation(char *menu, int min, int max)
{
    return ask_for_limited_int(menu, min, max);
}

Point_t *create_point(char *message) // reverifier
{
    Point_t *point = malloc(sizeof(Point_t));
    if (point == NULL)
    {
        return NULL;
    }
    point->x = ask_for_int(message);
    point->y = ask_for_int(message);

    return point;
}

void modify_point(char *message, Point_t *point) // le format des paramètres à input est :("Rectangle_s.x", Rectangle_s.x )
{
    printf("Ancienne valeur est %s: (%d, %d)\n", message, point->x, point->y);
    point->x = ask_for_int("Quelle est la nouvelle valeur ?\n");
    point->y = ask_for_int("Quelle est la nouvelle valeur ?\n");
    printf("la nouvelle valeur de x est %d\n", point->x);
    printf("la nouvelle valeur de y est %d\n", point->y);
}

void print_a_point(Point_t *point)
{
    printf("la valeur de x est : %d\n", point->x);
    printf(" la valeur de y est : %d\n", point->y);
}

void delete_point(Point_t *point)
{
    free(point);
}