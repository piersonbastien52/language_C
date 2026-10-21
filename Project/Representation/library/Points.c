/**
 * @file Points.c
 * @brief Point creation, modification, and output helpers.
 */

#include "ask_for_a_flint.h"
#include "point.h"
#include "Points.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Allocates Point_t and prompts user for x and y integer values.
 * @param message Message to display during input prompts.
 * @return Pointer to newly allocated Point_t.
 */

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

/**
 * @brief Displays old point coordinates and prompts user for new values.
 * @param message Name or descriptor of the point being modified.
 * @param point Pointer to Point_t to modify.
 */

void modify_point(char *message, Point_t *point) // le format des paramètres à input est :("Rectangle_s.x", Rectangle_s.x )
{
    printf("The old coordonates are %s: (%d, %d)\n", message, point->x, point->y);
    point->x = ask_for_int("What is the new x coordonate ?\n");
    point->y = ask_for_int("What is the nex y coordonate ?\n");
    printf("The new x coordonate is : %d\n", point->x);
    printf("The new y coordonate is : %d\n", point->y);
}

/**
 * @brief Displays X and Y coordinates of a Point_t to standard output.
 * @param point Pointer to target Point_t.
 */

void print_a_point(Point_t *point)
{
    printf("The coordonate x is : %d\n", point->x);
    printf("The coordonate y is : %d\n", point->y);
}

/**
 * @brief Deallocates Point_t memory.
 * @param point Pointer to Point_t to free.
 */

void delete_point(Point_t *point)
{
    free(point);
}