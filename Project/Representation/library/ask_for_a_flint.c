/**
 * @file ask_for_a_flint.c
 * @brief Input reading utilities with bounds validation and buffer flushing.
 */

#include <stdio.h>
#include "ask_for_a_flint.h"

/**
 * @brief Clears standard input stream up to newline or EOF.
 */

void clear_stdin(void)
{
    char c = 'a';
    while (c != '\n' && c != EOF)
        c = getc(stdin);
}

/**
 * @brief Prompts for an integer until valid integer input is received.
 * @param message Custom prompt message.
 * @return Validated integer input.
 */

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
            clear_stdin();
        }
    }
}

/**
 * @brief Prompts for an integer within a bounded range [min, max].
 * @param message Custom prompt message.
 * @param min Minimum acceptable integer value.
 * @param max Maximum acceptable integer value.
 * @return Validated integer within range.
 */

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
        else
        {
            clear_stdin();
            printf("wrong input (letters are not allowed)\n");
        }
    }
}

/**
 * @brief Prompts for a float within a bounded range [min, max].
 * @param message Custom prompt message.
 * @param min Minimum acceptable float value.
 * @param max Maximum acceptable float value.
 * @return Validated float within range.
 */

float ask_for_limited_float(char *message, float min, float max)
{
    float input_user;
    while (1)
    {
        printf("%s\n", message);
        if (scanf("%f", &input_user) == 1)
        {
            clear_stdin();
            if (input_user >= min && input_user <= max)
            {
                return input_user;
            }
            else
            {
                printf("wrong input\n");
                clear_stdin();
            }
        }
    }
}