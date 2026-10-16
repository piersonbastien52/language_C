#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Representation/color.h"
#include "Representation/ask_for_a_flint.h"
#include "Representation/Points.h"
#include "Representation/point.h"
#include "Representation/styles.h"
#include "Representation/rectangle.h"
#include "Representation/circle.h"
#include "Representation/ellipse.h"
#include "Representation/line.h"
#include "Representation/square.h"
#include "Representation/polylines.h"
#include "Representation/enum.h"

void clear_stdin(void)
{
    char c = 'a';
    while (c != '\n' && c != EOF)
        c = getc(stdin);
}

int create_rotation(void)
{
    return ask_for_limited_int("quel angle souhaitez-vous appliquer ? ", -360, 360);
}

int create_flip_x(void)
{
    int choice = ask_navigation(
        "1.Oui\n"
        "2.Non\n"
        "3.Retour\n"
        "Enter your choice (1-3): \n",
        1, 3);
    {
        switch (choice)
        {
        case 1:
            return 90; // faire correspondre return 1 flip_x=90° ? utiliser un bool ?
        case 2:
            menu_create_rotate();
            return 0;
            break;
        case 3:
            menu_create_rotate();
            return 0;
            break;
        }
    }
}

int create_flip_y(void)
{
    int choice = ask_navigation(
        "1.Oui\n"
        "2.Non\n"
        "3.Retour\n"
        "Enter your choice (1-3): \n",
        1, 3);
    {
        switch (choice)
        {
        case 1:
            return 180; // faire correspondre return 1 flip_y=180° ? utiliser un bool ?
        case 2:
            menu_create_rotate();
            return 0;
            break;
        case 3:
            menu_create_rotate();
            return 0;
            break;
        }
    }
}

void menu_modify_rotate(void)
{
    int choice = ask_navigation(
        "1.Modifier la rotation\n"
        "2.modifier l'inversion la structure sur l'axe x\n"
        "3.modifier l'inversion la structure sur l'axe y\n"
        "4.Retour\n"
        "Enter your choice (1-4): \n",
        1, 4);
    {
        switch (choice)
        {
        case 1:
            create_rotation();
            break;
        case 2:
            create_flip_x();
            break;
        case 3:
            create_flip_y();
            break;
        case 4:
            menu_create_rotate();
            break;
        default:
            printf("wrong input");
            break;
        }
    }
}

void modify_rotation(Styles_t *style) // à revérifier

{
    printf("l'angle précédemment saisi est : %d\n", style->angle);
    style->angle = create_rotation();
    printf("la nouvelle valeur de l'angle est : %d\n", style->angle);
}

void modify_flip_x(Styles_t *style)
{
    printf("une inversiond de %d° à été appliqué\n", style->flip_x);
    style->flip_x = create_flip_x();
    printf("la nouvelle valeur de l'angle est : %d\n", style->flip_x);
}

void modify_flip_y(Styles_t *style)
{
    printf("une inversiond de %d° à été appliqué\n", style->flip_y);
    style->flip_y = create_flip_y();
    printf("la nouvelle valeur de l'angle est : %d\n", style->flip_y);
}

void delete_angle(Styles_t *style)
{
    style->angle = 0;
}

void delete_flip_x(Styles_t *style)
{
    style->flip_x = 0;
}

void delete_flip_y(Styles_t *style)
{
    style->flip_y = 0;
}

// créer une fonction qui regroupe tous les paramètres de style, comme ca il n'est nécessaire d'appeler qu'une seule focntion pour définir le style d'une forme

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

int create(void);
// int editing(void);
// int charge(void);
// int visualize(void);

int main(void)
{

    int choice = ask_navigation(
        "1.Créer\n"
        "2.Editer\n"
        "3.Charger\n"
        "4.Visualiser\n"
        "5.quitter\n"
        "Enter your choice (1-5): \n",
        1, 5);

    switch (choice)
    {
    case 1:
        menu_create();
        break;
    case 2:
        // editing();
        break;
    case 3:
        // charge();
        break;
    case 4:
        // visualize();
        break;
    case 5:
        return 0;
        break;
    default:
        printf("wrong input");
        break;
    }
    return 0;
}

void menu_create(void)
{
    int choice_1 = ask_navigation(
        "1.Rectangle\n"
        "2.Carré\n"
        "3.Cercle\n"
        "4.Ellipse\n"
        "5.Line\n"
        "6.Polyline\n"
        "7.Retour\n"
        "Enter your choice (1-7): \n",
        1, 7);

    switch (choice_1)
    {
    case 1:
        // input_rectangle;
        break;
    case 2:
        // input_square;
        break;
    case 3:
        // input_circle;
        break;
    case 4:
        // input_ellipse;
        break;
    case 5:
        // input_line;
        break;
    case 7:
    // input_polylines
    case 6:
        // menu();  //où est menu ??
        break;
    default:
        printf("wrong input");
        break;
    }
}

void menu_create_rotate(void)

{

    int choice_2 = ask_navigation(

        "1.Effectuer une rotation\n"

        "2.inverser la structure sur l'axe x\n"

        "3.inverser la structure sur l'axe y\n"

        "4.modifier une rotation\n"

        "5.Retour\n"

        "Enter your choice (1-5): \n",

        1, 5);

    {

        switch (choice_2)

        {

        case 1:

            create_rotation();

            break;

        case 2:

            create_flip_x();

            break;

        case 3:

            create_flip_y();

            break;

        case 4:

            menu_modify_rotate();

            break;

        case 5:

            menu_create();

            break;

        default:

            printf("wrong input");

            break;
        }
    }
}
