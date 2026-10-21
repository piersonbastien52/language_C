#include <stdio.h>
#include "styles.h"

char *ask_color(char *message)
{
    char input_color[20];
    char *verified_color = malloc(sizeof(char) * 8);
    if (verified_color == NULL)
    {
        return NULL;
    }

    while (1)
    {
        printf("définir la couleur du %s en héxadécimal (ex: #FF0000):\n", message);

        if (fgets(input_color, sizeof(input_color), stdin) == NULL)
        {
            continue;
        }

        input_color[strcspn(input_color, "\n")] = '\0'; // permet dans inpout color de supprimer le \n si il existe

        if (strlen(input_color) != 7) // l'opérateur strlen permet de compter le nombre de caractères
        {
            printf("wrong input: the input have to be 7 letters long  (ex: #FF0000)\n");
            continue;
        }

        if (input_color[0] != '#')
        {
            printf("wrong input: manquement du caractère '#'\n");
            continue;
        }

        int valid = 1;
        for (int idx = 1; idx < 7; idx++)
        {
            char c = input_color[idx];
            if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')))
            {
                printf("wrong input: caractères hexadécimaux invalides\n");
                valid = 0;
                break;
            }
        }

        if (valid)
        {
            strcpy(verified_color, input_color);
            return verified_color;
        }
    }
}

char *modify_color(char *message, char *old_color)

{
    printf("L'ancienne couleur est : %s", old_color);
    free(old_color);
    return ask_color("quelle est la nouvelle couleur ?\n");
}

void print_color(Styles_t *style)
{

    printf(" la couleur actuelle du fond est :%s\n", style->fill);
    printf("la couleur actuelle du contour est :%s\n", style->stroke);
}

void delete_color(char *color)
{
    free(color);
}