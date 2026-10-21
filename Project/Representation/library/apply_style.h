#ifndef APPLY_STYLE_H
#define APPLY_STYLE_H
#include "styles.h"

Styles_t *create_translate(Styles_t *style);
void create_style(Styles_t *style);
void modify_style(Styles_t *style);
void print_style(Styles_t *style);
void delete_style(Styles_t *style);

#endif