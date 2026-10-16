#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

int ask_for_int(char *message)
{
    int input_user;

    while (1)
    {
        printf("%s\n", message);
        if (scanf("%d", &input_user) == 1)
        {
            clear_stdin();
            return input_user;
        }
        else
        {
            printf("wrong input\n");
        }
    }
}

int ask_for_limited_int(char *message, int min, int max)
{
    int input_user;

    while (1)
    {
        printf("%s\n", message);
        if (scanf("%d", &input_user) == 1)
        {
            clear_stdin();
            if (input_user >= min && input_user <= max)
            {
                return input_user;
            }
            else
            {
                printf("wrong input\n");
            }
        }
    }
}

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

char *ask_color(char *message)
{
    char input_color[20];
    char *verified_color = malloc(sizeof(char) * 8);
    int i;

    while (1)
    {
        i = 1;
        printf("définir la couleur du %s en héxadécimal:\n", message);
        fgets(input_color, sizeof(input_color), stdin);
        trim(input_color);

        while (input_color[i] != '\0')
        {

            if (input_color[0] != '#')
            {
                printf("wrong input, missing #");
                break;
            }
            if (strlen(input_color) != 7)
            {
                printf("wrong input");
            }
            if ((input_color[i] >= '0' && input_color[i] <= '9') ||
                (input_color[i] >= 'A' && input_color[i] <= 'F') ||
                (input_color[i] >= 'a' && input_color[i] <= 'f'))
            {
                i++;
            }
            else
            {
                printf("wrong input");
                break;
            }
            if (input_color[i] == '\0')
            {
                strcpy(verified_color, input_color);
                return verified_color;
            }
        }
    }
}

char *modify_color(char *message, char *old_color)

{
    printf("L'ancienne couleur est : %s", old_color);
    free(old_color);
    return ask_color("quelle est la nouvelle couleur ?\n");
}

void delete_color(char *color)
{
    free(color);
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
            create();
            break;
        default:
            printf("wrong input");
            break;
        }
    }
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
// il faut ici que je clear les valeur des angles défini puis un free self!

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