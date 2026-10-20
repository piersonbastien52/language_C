#include "styles.h"
#include <stdio.h>
#include <stdlib.h>

void create_fill(Styles_t *style)
{
    style->fill = ask_color("quelle couleur souhaitez-vous pour le remplissage ?\n");
}

int modify_fill(Styles_t *style)
{
    printf("la couleur du remplissage est: %s\n", style->fill);
    free(style->fill);
    style->fill = ask_color("quelle est la nouvelle couleur ?\n");
    printf("la nouvelle couleur de remplissage est : %s\n", style->fill);
}

void print_fill(Styles_t *style)
{
    printf("la couleur du remplissage est : %s\n", style->fill);
}

void delete_fill(Styles_t *style)
{
    free(style->fill);
}

int create_outline(Styles_t *style)
{
    style->stroke = ask_color("quelle couleur souhaitez-vous pour le contour?\n");
}

int modify_outline(Styles_t *style)
{
    printf("la couleur du contour est: %s\n", style->stroke);
    free(style->stroke);
    style->stroke = create_outline(style);
    printf("la nouvelle couleur de contour est : %s\n", style->stroke);
}

void print_outline(Styles_t *style)
{
    printf("la couleur du contour est : %s\n", style->stroke);
}

void delete_outline(Styles_t *style)
{
    free(style->stroke);
}

int create_stroke_opacity(Styles_t *style)
{
    style->stroke_opacity = ask_for_limited_float("quelle est l'opacité désiré pour le contour ?\n", 0, 1);
}

int modify_stroke_opacity(Styles_t *style)
{
    printf("l'opacité de la ligne est: %d\n", style->stroke_opacity);
    style->stroke_opacity = create_stroke_opacity(style);
    printf("la nouvelle opacité de la ligne est : %d\n", style->stroke_opacity);
}

void print_stroke_opacity(Styles_t *style)
{
    printf("l'opacité de la ligne est : %d\n", style->stroke_opacity);
}

void delete_stroke_opacity(Styles_t *style)

{
    style->stroke_opacity = 1.0;
}

int create_fill_opacity(Styles_t *style)
{
    style->fill_opacity = ask_for_limited_float("quelle est l'opacité désiré pour le fond ?\n", 0, 1);
}

int modify_fill_opacity(Styles_t *style)
{
    printf("l'opacité du remplissage est: %d\n", style->fill_opacity);
    style->fill_opacity = create_fill_opacity(style);
    printf("la nouvelle opacité du remplssage est : %d\n", style->fill_opacity);
}

void print_fill_opacity(Styles_t *style)
{
    printf("l'opacité du remplissage est : %d\n", style->fill_opacity);
}

void delete_fill_opacity(Styles_t *style)

{
    style->fill_opacity = 1.0;
}

int create_stroke_width(Styles_t *style)
{
    style->stroke_width = ask_for_limited_float("quelle épaisseur souhaitez vous pour le contour ?\n", 0, 1);
}

int modify_stroke_width(Styles_t *style)
{
    printf("l'épaisseur de la ligne est: %f\n", style->stroke_width);
    style->stroke_width = create_stroke_width(style);
    printf("la nouvelle épaisseur de la ligne est : %f\n", style->stroke_width);
}

void print_stroke_width(Styles_t *style)
{
    printf("l'épaisseur de la ligne est : %d\n", style->stroke_width);
}

void delete_stroke_opacity(Styles_t *style)

{
    style->stroke_width = 1.0;
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

Styles_t *create_translate(Styles_t *style)
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

void modify_translate(char *message, Styles_t *style) // le format des paramètres à input est :("Rectangle_s.x", Rectangle_s.x )
{
    printf("Ancienne valeur est %s: (%d, %d)\n", message, style->tx, style->ty);
    style->tx = ask_for_int("Quelle est la nouvelle valeur ?\n");
    style->ty = ask_for_int("Quelle est la nouvelle valeur ?\n");
    printf("la nouvelle valeur de tx est %d\n", style->tx);
    printf("la nouvelle valeur de ty est %d\n", style->ty);
}

void print_translate(Styles_t *style)
{
    printf("la valeur de tx est : %d\n", style->tx);
    printf(" la valeur de ty est : %d\n", style->ty);
}

void delete_translate(Styles_t *style)
{
    free(style->tx);
    free(style->ty);
}