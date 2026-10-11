#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct styles
{
  unsigned char *stroke;
  unsigned char *fill;
  unsigned float stroke_opacity;
  unsigned float fill_opacity;
  // retirer les slash si j'ai implementer la fonction de la forme de fin de lignes et de jonctions de lignes
  // unsigned char *stroke-linecap;
  // unsigned char *stroke line-join;

  // tx et ty, sont les coordonnées de translation et angle de rotation
  unsigned int tx;
  unsigned int ty;
  unsigned int angle;
};

int main(void)
{

  // choisir une couleur pour la bordure et pour l'interieur

<rect x="10" y="10" width="100" height="100"
       stroke="blue" fill="purple"
       stroke-opacity="0.8" fill-opacity="0.5"/>

      // forme de la fin de la ligne 

       <svg width="160" height="140" xmlns="http://www.w3.org/2000/svg" version="1.1">
  <line x1="40"
    x2="120"
    y1="20"
    y2="20"
    stroke-linecap="butt"
    stroke="black"
    stroke-width="20" />
  <line x1="40"
    x2="120"
    y1="60"
    y2="60"
    stroke-linecap="square"
    stroke="black"
    stroke-width="20" />
  <line x1="40"
    x2="120"
    y1="100"
    y2="100"
    stroke-linecap="round"
    stroke="black"
    stroke-width="20" />
</svg>

      //jonction entre deux lignes

<svg width="160" height="280" xmlns="http://www.w3.org/2000/svg" version="1.1">
  <polyline
    points="40 60 80 20 120 60"
    stroke="black"
    stroke-width="20"
    stroke-linecap="butt"
    fill="none"
    stroke-linejoin="miter" />

  <polyline
    points="40 140 80 100 120 140"
    stroke="black"
    stroke-width="20"
    stroke-linecap="round"
    fill="none"
    stroke-linejoin="round" />

  <polyline
    points="40 220 80 180 120 220"
    stroke="black"
    stroke-width="20"
    stroke-linecap="square"
    fill="none"
    stroke-linejoin="bevel" />
</svg>

      //translater 

<svg width="40" height="50" style="background-color:#bff;">
  <rect x="0" y="0" width="10" height="10" transform="translate(30,40)" />
</svg>

      // rotation 

<svg width="31" height="31">
  <rect x="12" y="-10" width="20" height="20" transform="rotate(45)" />
</svg>