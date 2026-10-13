#include "h.h"

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
    printf("7.retour\n"); // ATTENTION, implémenter le retour arrière
    printf("Enter your choice (1-7): \n");
    scanf("%d", &choice);
    if (choice > 7 || choice == NULL)
    {
        return ("wrong input number");
    }
    if (choice == 7)
        ;
    {
        return main;
    }
    int num1, num 2 switch (choice)
    {
    case 1:
        printf("Entrez la valeur de \"x\"");
        scanf("%d", num1);
        printf("Entrez la valeur de \"y\"");
        scanf("%d", num2);
        ;
        break;

    case 2:;
        break;
    case 3:;
        break;
    case 4:;
        break;
    case 5:;
        break;
    case 6:;
        break;
    default:;
        break;
    }
}

int coordonates(void)
{
}