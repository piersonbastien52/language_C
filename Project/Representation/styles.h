#ifndef STYLE_H
#define STYLE_H

typedef struct Styles_t
{
  unsigned char *stroke;
  unsigned char *fill;
  float stroke_opacity;
  float fill_opacity;
  float stroke_width;
  unsigned int tx, ty; // tx et ty, sont les coordonnées de translation et angle de rotation
  unsigned int angle;

  // il manque l'effet mirroir

} Styles_s;

#endif