#ifndef APPLY_STYLE_H
#define APPLY_STYLE_H
#include "styles.h"

int create_fill(Styles_t *style);
int modify_fill(Styles_t *style);
void print_fill(Styles_t *style);
void delete_fill(Styles_t *style);

int create_outline(Styles_t *style);
int modify_outline(Styles_t *style);
void print_outline(Styles_t *style);
void delete_outline(Styles_t *style);

int create_stroke_opacity(Styles_t *style);
int modify_stroke_opacity(Styles_t *style);
void print_stroke_opacity(Styles_t *style);
void delete_stroke_opacity(Styles_t *style);

int create_fill_opacity(Styles_t *style);
int modify_fill_opacity(Styles_t *style);
void print_fill_opacity(Styles_t *style);
void delete_fill_opacity(Styles_t *style);

int create_stroke_width(Styles_t *style);
int modify_stroke_width(Styles_t *style);
void print_stroke_width(Styles_t *style);
void delete_stroke_opacity(Styles_t *style);

int create_rotation(void);
void print_rotation(Styles_t *style);
void modify_rotation(Styles_t *style);
void delete_angle(Styles_t *style);

Styles_t *create_translate(Styles_t *style);
void modify_translate(char *message, Styles_t *style);
void print_translate(Styles_t *style);
void delete_translate(Styles_t *style);

#endif