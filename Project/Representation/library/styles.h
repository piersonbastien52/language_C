/**
 * @file styles.h
 * @brief Definition of graphical attributes for shapes.
 */

#ifndef STYLE_H
#define STYLE_H
#include "point.h"

/**
 * @struct Styles_s
 * @brief Defines style attributes such as colors, opacity, line width, and transformation.
 */

typedef struct Styles_s
{
  char *stroke;         /**< Hexadecimal string for border color */
  char *fill;           /**< Hexadecimal string for fill color */
  float stroke_opacity; /**< Opacity of the border (0.0 to 1.0) */
  float fill_opacity;   /**< Opacity of the fill (0.0 to 1.0) */
  float stroke_width;   /**< Width of the stroke line */
  Point_t *translation; /**< Translation vector (tx, ty) */
  int angle;            /**< Rotation angle in degrees (-360 to 360) */

} Styles_t;

#endif
