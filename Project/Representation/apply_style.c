#include "styles.h"
#include <stdio.h>
#include <stdlib.h>
#include "Representation/Points.h"

Styles_t *create_translate(Styles_t *style)
{
    style->translation = create_point("what is the tx and ty value of translation ?\n");
}

void create_style(Styles_t *style)
{
    style->fill = ask_color("what is the filling color ?\n");
    style->stroke = ask_color("what is the stroke color ?\n");
    style->stroke_opacity = ask_for_limited_float("what is the stroke opacity ?\n", 0, 1);
    style->fill_opacity = ask_for_limited_float("what is the fill opacity ?\n", 0, 1);
    style->stroke_width = ask_for_limited_float("what is the stroke width ?\n", 0, 1);
    style->angle = ask_for_limited_int("what angle apply ? ", -360, 360);
    create_translate(style);
}

void modify_style(Styles_t *style) // voir si oil n'y a pas un moyen de modifierqu'une seule valeur et pas toute, pas besoin de boucle ??
{
    printf("the filling color is : %s\n", style->fill);
    free(style->fill);
    style->fill = ask_color("what is the new filling color ?\n");
    printf("the new filling color is : %s\n", style->fill);

    printf("the stroke color is : %s\n", style->stroke);
    free(style->stroke);
    style->stroke = ask_color("what is the new stroke color ?\n");
    printf("the new stroke color is : %s\n", style->stroke);

    printf("the stroke opacity is : %f\n", style->stroke_opacity);
    style->stroke_opacity = ask_for_limited_float("what is the new stroke opacity ?\n", 0, 1);
    printf("the new stroke opacity is : %f\n", style->stroke_opacity);

    printf("the filling opacity is : %f\n", style->fill_opacity);
    style->fill_opacity = ask_for_limited_float("what is teh new filling opacity  ?\n", 0, 1);
    printf("the new filling opacity is : %f\n", style->fill_opacity);

    printf("the stroke width is : %f\n", style->stroke_width);
    style->stroke_width = ask_for_limited_float("whst is the new stroke width ?\n", 0, 1);
    printf("the new stroke width is: %f\n", style->stroke_width);

    printf("the applied angle is : %d\n", style->angle);
    style->angle = ask_for_limited_int("enter a new angle? ", -360, 360);
    printf("the new applied angle is : %d\n", style->angle);

    printf("the old value of tx translation: %d\n", style->tx);
    printf("the old value of ty translation: %d\n", style->ty);
    style->tx = ask_for_int("what is the new value of tx ?\n");
    style->ty = ask_for_int("what is the new value of ty ?\n");
    printf("the new value of tx is %d\n", style->tx);
    printf("the nex value of ty is %d\n", style->ty);
}

void print_style(Styles_t *style)
{
    printf("the filling color is : %s\n", style->fill);
    printf("the stroke color is : %s\n", style->stroke);
    printf("the stroke opacity is : %f\n", style->stroke_opacity);
    printf("the filling opacity is : %f\n", style->fill_opacity);
    printf("the stroke width is : %f\n", style->stroke_width);
    printf("the applied angle is : %d\n", style->angle);
    printf("the tx translation value is : %d\n", style->tx);
    printf("the ty translation value is : %d\n", style->ty);
}

void delete_style(Styles_t *style)
{
    if (style->fill != NULL)
    {
        free(style->fill);
    }

    if (style->stroke != NULL)
    {
        free(style->stroke);
    }
    if (style != NULL)
    {
        free(style);
    }
}
