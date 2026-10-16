#include "styles.h"

int create_fill(Styles_t *style)
{
    style->fill = ask_color("quelle couleur souhaitez-vous pour le remplissage ?\n");
}

int create_outline(Styles_t *style)
{
    style->stroke = ask_color("quelle couleur souhaitez-vous pour le contour?\n");
}

int create_stroke_opacity(Styles_t *style)
{
    style->stroke_opacity = ask_for_limited_float("quelle est l'opacité désiré pour le contour ?\n", 0, 1);
}

int create_fill_opacity(Styles_t *style)
{
    style->fill_opacity = ask_for_limited_float("quelle est l'opacité désiré pour le fond ?\n", 0, 1);
}

int create_stroke_width(Styles_t *style)
{
    style->stroke_width = ask_for_limited_float("quelle épaisseur souhaitez vous pour le contour ?\n", 0, 1);
}

Styles_t *create_translate(void)
{
    Styles_t *move = malloc(sizeof(Styles_t));
    if (move == NULL)
    {
        return NULL;
    }
    move->tx = ask_for_int("definissez la valeur de la translation sur l'axe x\n");
    move->ty = ask_for_int("définissez la valeur de la translation sur l'axe y\n");
    return move;
}

int create_rotation(void)

{

    return ask_for_limited_int("quel angle souhaitez-vous appliquer ? ", -360, 360);
}

void print_rotation(Styles_t *style)

{
    printf("l'angle de la rotation est de : %d\n", style->angle);
    printf("Flip X : %s\n", style->flip_x ? "true" : "false");
    printf("Flip Y : %s\n", style->flip_y ? "true" : "false");
}

void modify_rotation(Styles_t *style) // à revérifier

{

    printf("l'angle précédemment saisi est : %d\n", style->angle);

    style->angle = create_rotation();

    printf("la nouvelle valeur de l'angle est : %d\n", style->angle);
}

void delete_angle(Styles_t *style)

{

    style->angle = 0;
}
