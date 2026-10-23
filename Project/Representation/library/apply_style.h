#ifndef APPLY_STYLE_H
#define APPLY_STYLE_H
#include "styles.h"

Styles_t *create_translate(Styles_t *style);
void create_style(Styles_t *style);
void modify_style_filling(Styles_t *style);
void modify_style_stroke(Styles_t *style);
void modify_style_stroke_opacity(Styles_t *style);
void modify_style_filling_opacity(Styles_t *style);
void modify_style_stroke_width(Styles_t *style);
void modify_style_angle(Styles_t *style);
void modify_style_translation(Styles_t *style);
void print_style(Styles_t *style);
void delete_style(Styles_t *style);

#endif