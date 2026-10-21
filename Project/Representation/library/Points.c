#include "ask_for_a_flint.h"
#include "point.h"
#include "Points.h"
#include <stdio.h>
#include <stdlib.h>

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
    printf("The old coordonates are %s: (%d, %d)\n", message, point->x, point->y);
    point->x = ask_for_int("What is the new x coordonate ?\n");
    point->y = ask_for_int("What is the nex y coordonate ?\n");
    printf("The new x coordonate is : %d\n", point->x);
    printf("The new y coordonate is : %d\n", point->y);
}

void print_a_point(Point_t *point)
{
    printf("The coordonate x is : %d\n", point->x);
    printf("The coordonate y is : %d\n", point->y);
}

void delete_point(Point_t *point)
{
    free(point);
}