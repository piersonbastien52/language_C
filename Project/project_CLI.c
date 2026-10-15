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
    int verified_input;

    while (1)
    {
        printf("%s\n", message);
        if (scanf("%d", &input_user) == 1)
        {
            clear_stdin();
            if (input_user > min && input_user < max)
            {
                return input_user;
            }
            else
            {
                print("wrong input\n");
            }
        }
    }
}

int ask_navigation(char *menu, int min, int max)
{
    return ask_for_limited_int(menu, min, max);
}

Point_s *create_point(char *message)
{
    Point_s *point = malloc(sizeof(Point_s));
    point->x = ask_for_int(message);
    point->y = ask_for_int(message);
    return point;
}

void modify_point(char *message, Point_s *point) // le format des paramètres à input est :("Rectangle_s.x", Rectangle_s.x )
{
    printf("Ancienne valeur est %s: (%d, %d)\n", message, point->x, point->y);
    point->x = ask_for_int("Quelle est la nouvelle valeur ?\n");
    point->y = ask_for_int("Quelle est la nouvelle valeur ?\n");
}

void print_a_point(char *message, Point_s *point)
{
    printf("la valeur de x est ; %d\n", point->x);
    printf(" la valeur de y est : %d\n", point->y);
}

void delete_point(Point_s *point)
{
    free(point);  // point dispose d'une adresse invalide
    point = NULL; // ainsi point peut de nouveau accueillir des données
}

char *ask_color(char *message)
{
    char input_color[20];
    char *verified_color = malloc(sizeof(verified_color));
    int i;

    while (1)
    {
        i = 1;
        printf("définir la couleur du %s en héxadécimal:\n", message);
        clear_stdin();
        fgets(input_color, sizeof(input_color), stdin);
        trim(input_color);

        while (input_color[i] != '\0')
        {

            if (input_color[0] != '#')
            {
                printf("wrong input, missing #");
            }
            if (strlen(input_color != 7))
            {
                print("wrong input");
            }
            if ((input_color[i] >= '0' && input_color[i] <= '9') ||
                (input_color[i] >= 'A' && input_color[i] <= 'F') ||
                (input_color[i] >= 'a' && input_color[i] <= 'f'))
            {
                i++;
                snprintf(verified_color, sizeof verified_color, "%s", input_color);
                return verified_color;
            }
            else
            {
                printf("wrong input");
                break;
            }
        }
    }
}

void modify_color(char *message, char *old_color)
{
    char *new_color;
    printf("L'ancienne couleur est : %s", old_color);
    old_color = ask_color("quelle est la nouvelle couleur ?\n");
    return new_color = old_color;
}
int create(void);
// int editing(void);
// int charge(void);
// int visualize(void);

int menu(void)
{
    unsigned int choice;
    float num1, num2, result;
    unsigned int user_input;

    while (1)
    {
        printf("1.Créer\n");
        printf("2.Editer\n");
        printf("3.Charger\n");
        printf("4.Visualiser\n");
        printf("5.quitter\n");
        printf("Enter your choice (1-5): \n");
        scanf("%d", &user_input);
        clear_stdin();
        if (user_input >= 1 && user_input <= 5)
        {
            switch (user_input)
            {
            case 1:
                create();
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
                ("wrong input");
                break;
            };
        }
    }
}

int main(void)
{

    modify_point("Rectangle_s.x", Rectangle_s.x);
    menu();
}

int create(void)
{
    unsigned int choice;
    float num1, num2, result;
    unsigned int user_input;

    while (1)
    {
        printf("1.Rectangle\n");
        printf("2.Carré\n");
        printf("3.Cercle\n");
        printf("4.Ellipse\n");
        printf("5.Line\n");
        printf("6.Polyline\n");
        printf("7.retour\n");
        printf("Enter your choice (1-7): \n");
        clear_stdin();
        scanf("%d", &user_input);
        if (user_input >= 1 && user_input <= 5)
        {
            switch (user_input)
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
                menu();
                break;
            default:
                break;
            };
        }
        else
        {
            printf("wrong input");
        };
    }
}

int input_rectangle(Rectangle_s rectangle)
{
    int temp_x;
    int temp_y;
    int temp_height;
    int temp_width;

    while (1)
    {
        printf("définir x:\n");
        clear_stdin();
        scanf("x = %d\n", &temp_x);

        if (temp_x >= -1000 && temp_x <= 1000)
        {
            rectangle.x = temp_x;
            break;
        }
        else
        {
            printf("wrong input");
        };
    }
    while (1)
    {
        printf("définir y:\n");
        clear_stdin();
        scanf("y = %d\n", &temp_y);

        if (temp_y >= -1000 && temp_y <= 1000)
        {
            rectangle.y = temp_y;
            break;
        }
        else
        {
            printf("wrong input");
        };
    }
    while (1)
    {
        printf("définir la hauteur :\n");
        clear_stdin();
        scanf("hauteur = %d\n", &temp_height);

        if (temp_height >= -1000 && temp_height <= 1000)
        {
            rectangle.height = temp_height;
            break;
        }
        else
        {
            printf("wrong input");
        };
    }
    while (1)
    {
        printf("définir la largeur :\n");
        clear_stdin();
        scanf("largeur = %d\n", &temp_width);

        if (temp_width >= -1000 && temp_width <= 1000)
        {
            rectangle.width = temp_width;
            break;
        }
        else
        {
            printf("wrong input");
        };
    }
}

int style_shape(Styles_s style)
{

    char temp_stroke[20];
    char temp_fill[20];
    float temp_stroke_opacity;
    float temp_fill_opacity;
    float temp_stroke_width;
    int temp_tx;
    int temp_ty;
    int temp_angle;

    while (1)
    {
        printf("définir la valeur de la translation:\n");
        clear_stdin();
        scanf("x = %d\n", &temp_tx);
        scanf("x = %d\n", &temp_tx);

        if ((temp_tx >= -1000 && temp_tx <= 1000) ||
            (temp_ty >= -1000 && temp_ty <= 1000))
        {
            style.tx = temp_tx;
            style.ty = temp_ty;
            break;
        }
        else
        {
            printf("wrong input");
        };
    }

    while (1)
    {
        printf("définir la valeur de la rotation :\n");
        clear_stdin();
        scanf("rotation = %d\n", &temp_angle);

        if (temp_angle >= -360 && temp_angle <= 360)
        {
            style.angle = temp_angle;
            break;
        }
        else
        {
            printf("wrong input, la valeur doit être comprise entre -360° et 360°");
        };
    }
}
strcpy(style.stroke, temp_stroke);
}
;

int trim(char *sentence)
{
    int a = strlen(sentence);
    int i = 0; // lecture
    int j = 0; // écriture

    while (sentence[i] != '\0')
    {
        if (sentence[i] != ' ')
        {
            sentence[j] = sentence[i];
            j++;
        }
        i++;
    }
    sentence[j] = '\0';
}