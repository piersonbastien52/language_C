/**
 * @file apply_style.c
 * @brief Interactive configuration and management of graphical styles.
 */

#include "Points.h"
#include "apply_style.h"
#include "styles.h"
#include "color.h"
#include "ask_for_a_flint.h"
#include "apply_style.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Prompts user for translation coordinates and sets them in the style structure.
 * @param style Pointer to the target Styles_t instance.
 * @return Pointer to the modified Styles_t structure.
 */

Styles_t *create_translate(Styles_t *style)
{
    style->translation = create_point("what is the tx and ty value of translation ?\n");
    return style;
}

/**
 * @brief Interactively populates all style fields (colors, opacity, stroke, rotation, translation).
 * @param style Pointer to the Styles_t structure to initialize.
 */

void create_style(Styles_t *style)
{
    style->fill = ask_color("what is the filling color ?\n");
    style->stroke = ask_color("what is the stroke color ?\n");
    style->stroke_opacity = ask_for_limited_float("what is the stroke opacity (0 to 1) ?\n", 0, 1);
    style->fill_opacity = ask_for_limited_float("what is the fill opacity (0 to 1) ?\n", 0, 1);
    style->stroke_width = ask_for_limited_float("what is the stroke width (0 to 1) ?\n", 0, 1);
    style->angle = ask_for_limited_int("what angle apply (-360° to 360) ?\n", -360, 360);
    create_translate(style);
}

/**
 * @brief Interactively updates existing style fields with user feedback.
 * @param style Pointer to the Styles_t structure to modify.
 */

void modify_style_filling(Styles_t *style)
{
    printf("the filling color is : %s\n", style->fill);
    free(style->fill);
    style->fill = ask_color("what is the new filling color ?\n");
    printf("the new filling color is : %s\n", style->fill);
}

void modify_style_stroke(Styles_t *style)
{
    printf("the stroke color is : %s\n", style->stroke);
    free(style->stroke);
    style->stroke = ask_color("what is the new stroke color ?\n");
    printf("the new stroke color is : %s\n", style->stroke);
}

void modify_style_stroke_opacity(Styles_t *style)
{
    printf("the stroke opacity is : %f\n", style->stroke_opacity);
    style->stroke_opacity = ask_for_limited_float("what is the new stroke opacity (0 to 1) ?\n", 0, 1);
    printf("the new stroke opacity is : %f\n", style->stroke_opacity);
}

void modify_style_filling_opacity(Styles_t *style)
{
    printf("the filling opacity is : %f\n", style->fill_opacity);
    style->fill_opacity = ask_for_limited_float("what is the new filling opacity (0 to 1) ?\n", 0, 1);
    printf("the new filling opacity is : %f\n", style->fill_opacity);
}

void modify_style_stroke_width(Styles_t *style)
{
    printf("the stroke width is : %f\n", style->stroke_width);
    style->stroke_width = ask_for_limited_float("what is the new stroke width (0 to 1) ?\n", 0, 1);
    printf("the new stroke width is: %f\n", style->stroke_width);
}

void modify_style_angle(Styles_t *style)
{
    printf("the applied angle is : %d\n", style->angle);
    style->angle = ask_for_limited_int("enter a new angle? (-360 to 360)", -360, 360);
    printf("the new applied angle is : %d\n", style->angle);
}

void modify_style_translation(Styles_t *style)
{
    printf("the old value of tx translation: %d\n", style->translation->x);
    printf("the old value of ty translation: %d\n", style->translation->y);
    style->translation->x = ask_for_int("what is the new value of tx ?\n");
    style->translation->y = ask_for_int("what is the new value of ty ?\n");
    printf("the new value of tx is %d\n", style->translation->x);
    printf("the new value of ty is %d\n", style->translation->y);
}

/**
 * @brief Prints current style values to standard output.
 * @param style Pointer to the Styles_t structure to display.
 */

void print_style(Styles_t *style)
{
    printf("the filling color is : %s\n", style->fill);
    printf("the stroke color is : %s\n", style->stroke);
    printf("the stroke opacity is : %f\n", style->stroke_opacity);
    printf("the filling opacity is : %f\n", style->fill_opacity);
    printf("the stroke width is : %f\n", style->stroke_width);
    printf("the applied angle is : %d\n", style->angle);
    printf("the tx translation value is : %d\n", style->translation->x);
    printf("the ty translation value is : %d\n", style->translation->y);
}

/**
 * @brief Deallocates memory associated with fill and stroke strings and the style structure itself.
 * @param style Pointer to the Styles_t structure to delete.
 */

void delete_style(Styles_t *style)
{
    if (style == NULL)
    {
        return;
    }
    if (style->fill != NULL)
    {
        free(style->fill);
    }

    if (style->stroke != NULL)
    {
        free(style->stroke);
    }
    if (style != NULL)
    {
        free(style);
    }
}
