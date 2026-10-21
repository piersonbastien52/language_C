#include "Representation/library/enum.h"
#include <stdio.h>

void print_shapes_list(Landmark_t *chain)
{
    if (chain == NULL || chain->start == NULL)
    {
        printf("No shape saved.\n");
        return;
    }

    List_shape_t *current = chain->start;
    unsigned int index = 0;

    while (current != NULL)
    {
        printf("[%u] ", index);

        switch (current->shape.type)
        {
        case FORM_RECTANGLE:
            printf("Rectangle\n");
            break;

        case FORM_SQUARE:
            printf("Square\n");
            break;

        case FORM_CIRCLE:
            printf("Circle\n");
            break;

        case FORM_ELLIPSE:
            printf("Ellipse\n");
            break;

        case FORM_LINE:
            printf("Line\n");
            break;
        default:
            printf("Unknown shape\n");
            break;
        }

        current = current->next;
        index++;
    }
}