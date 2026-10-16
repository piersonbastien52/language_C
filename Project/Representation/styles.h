#ifndef STYLE_H
#define STYLE_H
#include <stdbool.h>

typedef struct Styles_s
{
  char *stroke;
  char *fill;
  float stroke_opacity;
  float fill_opacity;
  float stroke_width;
  int tx;
  int ty; // tx et ty, sont les coordonnées de translation et angle de rotation
  int angle;
  bool flip_x;
  bool flip_y;

} Styles_t;

#endif
