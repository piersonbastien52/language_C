#include <stdio.h>

void clear_stdin(void)
{
    char c = 'a';
    while (c != '\n' && c != EOF)
        c = getc(stdin);
}

int ask_navigation(char *menu, int min, int max)
{
    return ask_for_limited_int(menu, min, max);
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
            }
        }
    }
}