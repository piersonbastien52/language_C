#include "../Representation/library/generation.h"
#include <stdio.h>
#include <string.h>
#include "export.h"

int export_svg(Landmark_t *landmark)
{
    if (landmark == NULL)
    {
        printf("Any shape to export\n");
        return -1;
    }

    FILE *file = fopen("file_name.svg", "w");

    if (file == NULL)
    {
        printf("error during file opening\n");
        return -1;
    }

    fprintf(file, "<svg viewBox=\"-1000 -1000 2000 2000\" xmlns=\"http://www.w3.org/2000/svg\">\n");

    List_shape_t *current = landmark->start;

    while (current != NULL)
    {
        Shape_t *shape = &current->shape;
        if (shape == NULL)
        {
            current = current->next;
            continue;
        }
        if (shape->styles == NULL)
        {
            printf("non-defined styles\n");
            current = current->next;
            continue;
        }

        switch (shape->type)
        {
        case FORM_RECTANGLE:
            fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\"\n", shape->data.rectangle->point->x, shape->data.rectangle->point->y, shape->data.rectangle->width, shape->data.rectangle->height);
            fprintf(file, "stroke=\"%s\" fill=\"%s\" stroke-opacity=\"%f\" fill-opacity=\"%f\" stroke-width=\"%f\" transform=\"translate(%d,%d) rotate(%d)\"/>\n", shape->styles->stroke, shape->styles->fill, shape->styles->stroke_opacity, shape->styles->fill_opacity, shape->styles->stroke_width, shape->styles->translation->x, shape->styles->translation->y, shape->styles->angle);
            break;

        case FORM_SQUARE:
            fprintf(file, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\"/\n", shape->data.square->point->x, shape->data.square->point->y, shape->data.square->height, shape->data.square->height);
            fprintf(file, "stroke=\"%s\" fill=\"%s\" stroke-opacity=\"%f\" fill-opacity=\"%f\" stroke-width=\"%f\" transform=\"translate(%d,%d) rotate(%d)\"/>\n", shape->styles->stroke, shape->styles->fill, shape->styles->stroke_opacity, shape->styles->fill_opacity, shape->styles->stroke_width, shape->styles->translation->x, shape->styles->translation->y, shape->styles->angle);
            break;

        case FORM_CIRCLE:
            fprintf(file, "<circle cx=\"%d\" cy=\"%d\" r=\"%d\"\n", shape->data.circle->center->x, shape->data.circle->center->y, shape->data.circle->r);
            fprintf(file, "stroke=\"%s\" fill=\"%s\" stroke-opacity=\"%f\" fill-opacity=\"%f\" stroke-width=\"%f\" transform=\"translate(%d,%d) rotate(%d)\"/>\n", shape->styles->stroke, shape->styles->fill, shape->styles->stroke_opacity, shape->styles->fill_opacity, shape->styles->stroke_width, shape->styles->translation->x, shape->styles->translation->y, shape->styles->angle);
            break;

        case FORM_ELLIPSE:
            fprintf(file, "<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\"\n", shape->data.ellipse->center->x, shape->data.ellipse->center->y, shape->data.ellipse->rx, shape->data.ellipse->ry);
            fprintf(file, "stroke=\"%s\" fill=\"%s\" stroke-opacity=\"%f\" fill-opacity=\"%f\" stroke-width=\"%f\" transform=\"translate(%d,%d) rotate(%d)\"/>\n", shape->styles->stroke, shape->styles->fill, shape->styles->stroke_opacity, shape->styles->fill_opacity, shape->styles->stroke_width, shape->styles->translation->x, shape->styles->translation->y, shape->styles->angle);
            break;

        case FORM_LINE:
            fprintf(file, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\"\n", shape->data.line->point1->x, shape->data.line->point1->y, shape->data.line->point2->x, shape->data.line->point2->y);
            fprintf(file, "stroke=\"%s\" fill=\"%s\" stroke-opacity=\"%f\" fill-opacity=\"%f\" stroke-width=\"%f\" transform=\"translate(%d,%d) rotate(%d)\"/>\n", shape->styles->stroke, shape->styles->fill, shape->styles->stroke_opacity, shape->styles->fill_opacity, shape->styles->stroke_width, shape->styles->translation->x, shape->styles->translation->y, shape->styles->angle);
            break;
        }
        current = current->next;
    }
    fprintf(file, "</svg>");
    fclose(file);

    return 0;
}
