#include "project.h"

int create(void);
int editing(void);
int charge(void);
int visualize(void);

int menu(int user_input)
{
    int choice;
    float num1, num2, result;

    printf("1.Créer\n");
    printf("2.Editer\n");
    printf("3.Charger\n");
    printf("4.Visualiser\n");
    printf("5.quitter\n");
    printf("Enter your choice (1-5): \n");

    while (1)
    {
        scanf("%d", user_input);
        if (user_input >= 1 && user_input <= 5)
        {
            switch (user_input)
            {
            case 1:
                create;
                break;
            case 2:
                editing;
                break;
            case 3:
                charge;
                break;
            case 4:
                visualize;
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
            printf("wrong input");
        };
    }
}

int create(void)
{
    int choice;
    float num1, num2, result;

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
        scanf("%d", user_input);
        if (user_input >= 1 && user_input <= 5)
        {
            switch (user_input)
            {
            case 1:
                input_rectangle;
                break;
            case 2:
                input_square;
                break;
            case 3:
                input_circle;
                break;
            case 4:
                input_ellipse;
                break;
            case 5:
                input_line;
                break;
            case 7:
            input_polylines case 6:
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