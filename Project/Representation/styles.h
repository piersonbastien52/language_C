#ifndef STYLE_H
#define STYLE_H
#include "point.h"

typedef struct Styles_s
{
  char *stroke;
  char *fill;
  float stroke_opacity;
  float fill_opacity;
  float stroke_width;
  Point_t *translation;
  int angle;

} Styles_t;

#endif
