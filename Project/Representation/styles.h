#ifndef STYLE_H
#define STYLE_H

typedef struct Styles_t
{
  char *stroke;
  char *fill;
  float stroke_opacity;
  float fill_opacity;
  float stroke_width;
  int tx;
  int ty; // tx et ty, sont les coordonnées de translation et angle de rotation
  int angle;

  // il manque l'effet mirroir

} Styles_s;

#endif