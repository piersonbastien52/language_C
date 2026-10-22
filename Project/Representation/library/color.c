/**
 * @file color.c
 * @brief Functions for validating, reading, modifying, and printing hexadecimal colors.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
#include "styles.h"

/**
 * @brief Prompts the user until a valid hexadecimal color (#RRGGBB) is provided.
 * @param message Description string used in prompt.
 * @return Pointer to dynamically allocated 8-byte string containing validated color.
 */

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
        printf("Define the color of %s in hexadecimal (#FF0000):\n", message);

        if (fgets(input_color, sizeof(input_color), stdin) == NULL)
        {
            continue;
        }

        input_color[strcspn(input_color, "\n")] = '\0'; // permet dans inpout color de supprimer le \n si il existe

        if (strlen(input_color) != 7) // l'opérateur strlen permet de compter le nombre de caractères
        {
            printf("Wrong input: the input have to be 7 letters long (#FF0000)\n");
            continue;
        }

        if (input_color[0] != '#')
        {
            printf("Wrong input: missing the '#'\n");
            continue;
        }

        int valid = 1;
        for (int idx = 1; idx < 7; idx++)
        {
            char c = input_color[idx];
            if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f')))
            {
                printf("Invalid input\n");
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

/**
 * @brief Frees previous color string and requests a new color string from user.
 * @param message Prompt text.
 * @param old_color Pointer to dynamically allocated string of old color.
 * @return Pointer to newly allocated validated color string.
 */

char *modify_color(char *message, char *old_color)

{
    printf("The old color is : %s", old_color);
    free(old_color);
    return ask_color(message);
}

/**
 * @brief Prints fill and stroke colors of a style structure.
 * @param style Pointer to Styles_t structure.
 */

void print_color(Styles_t *style)
{

    printf("The old filling color is :%s\n", style->fill);
    printf("The new filling color is :%s\n", style->stroke);
}

/**
 * @brief Deallocates color string buffer.
 * @param color Pointer to allocated string.
 */

void delete_color(char *color)
{
    free(color);
}