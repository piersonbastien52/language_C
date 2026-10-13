#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Representation/styles.h"
#include "Representation/rectangle.h"
#include "Representation/circle.h"
#include "Representation/ellipse.h"
#include "Representation/line.h"
#include "Representation/square.h"
#include "Representation/polylines.h"
#include "Representation/enum.h"

int create(void);
// int editing(void);
// int charge(void);
// int visualize(void);

void clear_stdin(void)
{
    char c = 'a';
    while (c != '\n' && c != EOF)
        c = getc(stdin);
}

int menu(void)
{
    int choice;
    float num1, num2, result;
    int user_input;

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
                break;
            };
        }
        else
        {
            printf("wrong input\n");
        };
    }
}

int main(void)
{
    menu();
}

int create(void)
{
    int choice;
    float num1, num2, result;
    int user_input;

    printf("1.Rectangle\n");
    printf("2.Carré\n");
    printf("3.Cercle\n");
    printf("4.Ellipse\n");
    printf("5.Line\n");
    printf("6.Polyline\n");
    printf("7.retour\n");
    printf("Enter your choice (1-7): \n");

    while (1)
    {
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
                menu;
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
        scanf("x = %d\n", &temp_x);

        if (temp_x >= 1 && temp_x <= 1000)
        {
            rectangle.x = temp_x;
            break;
        }
        else
        {
            printf("wrong input");
            temp_x = 2;
        };
    }
    while (1)
    {
        printf("définir y:\n");
        scanf("y = %d\n", &temp_y);

        if (temp_y >= 1 && temp_y <= 1000)
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
        scanf("hauteur = %d\n", &temp_height);

        if (temp_height >= 1 && temp_height <= 1000)
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
        scanf("largeur = %d\n", &temp_width);

        if (temp_width >= 1 && temp_width <= 1000)
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
