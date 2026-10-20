#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Representation/library/apply_style.h"
#include "Representation/library/color.h"
#include "Representation/library/ask_for_a_flint.h"
#include "Representation/library/Points.h"
#include "Representation/library/point.h"
#include "Representation/library/styles.h"
#include "Representation/library/rectangle.h"
#include "Representation/library/circle.h"
#include "Representation/library/ellipse.h"
#include "Representation/library/line.h"
#include "Representation/library/square.h"
#include "Representation/library/enum.h"

int create(void);
int editing(void);
int charge(void);
int visualize(void);

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
        editing();
        break;
    case 3:
        charge();
        break;
    case 4:
        visualize();
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
        input_rectangle();
        break;
    case 2:
        input_square();
        break;
    case 3:
        input_circle();
        break;
    case 4:
        input_ellipse();
        break;
    case 5:
        input_line();
        break;
    case 6:
        menu();
        break;
    default:
        printf("wrong input");
        break;
    }
}

void menu_create_rotate(void)
{
    int choice = ask_navigation(
        "1.Effectuer une rotation\n"
        "2.modifier une rotation\n"
        "3.Retour\n"
        "Enter your choice (1-3): \n",
        1, 3);
    {
        switch (choice)
        {
        case 1:
            create_rotation();
            break;
        case 2:
            menu_modify_rotate();
            break;
        case 3:
            menu_create();
            break;
        default:
            printf("wrong input");
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

int ask_navigation(char *menu, int min, int max)
{
    return ask_for_limited_int(menu, min, max);
}