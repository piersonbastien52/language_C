#include <stdio.h>
#include "styles.h"

char *ask_color(char *message)
{
    char input_color[20];
    char *verified_color = malloc(sizeof(char) * 8);
    int i;

    while (1)
    {
        i = 1;
        printf("définir la couleur du %s en héxadécimal:\n", message);
        fgets(input_color, sizeof(input_color), stdin); // ici, il n'y a plus de trim, il va falloir le refaire

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
int print_color(Styles_t *style)
{

    printf(" la couleur actuelle du fond est :%s\n", style->fill);
    printf("la couleur actuelle du contour est :%s\n", style->stroke);
}
void delete_color(char *color)
{
    free(color);
}
