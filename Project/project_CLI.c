#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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
        printf("définir la couleur du contour en héxadécimal:\n");
        clear_stdin();
        printf("contour :");
        fgets(temp_stroke, sizeof(temp_stroke), stdin);
        trim(temp_stroke);

        while (temp_stroke[i] != '\0')
        {
            clear_stdin();

            if (temp_stroke[0] != '#')
            {
                printf("wrong input, missing #");
            }

            if ((temp_stroke[i] >= '0' && temp_stroke[i] <= '9') ||
                (temp_stroke[i] >= 'A' && temp_stroke[i] <= 'F') ||
                (temp_stroke[i] >= 'a' && temp_stroke[i] <= 'f'))
            {
                i++;
            }
            else
            {
                printf("wrong input");
                break;
            }
        }
    }
    strcpy(style.stroke, temp_stroke);
};

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