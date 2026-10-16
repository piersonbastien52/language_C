#ifndef ASK_FOR_H
#define ASK_FOR_H

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

#endif
