#ifndef COLOR_H
#define COLOR_H
#include "styles.h"

char *ask_color(char *message);

char *modify_color(char *message, char *old_color);

void print_color(Styles_t *style);

void delete_color(char *color);

#endif