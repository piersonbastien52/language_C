#ifndef APPLY_STYLE_H
#define APPLY_STYLE_H
#include "styles.h"

int create_fill(Styles_t *style);
int create_outline(Styles_t *style);
int create_stroke_opacity(Styles_t *style);
int create_fill_opacity(Styles_t *style);
int create_stroke_width(Styles_t *style);
Styles_t *create_translate(void);
int create_rotation(void);
void print_rotation(Styles_t *style);
void modify_rotation(Styles_t *style); // à revérifier
void delete_angle(Styles_t *style);

#endif