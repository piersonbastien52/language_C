
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// il faut que je mette un chemin
#ifndef "styles"
#define "styles"

struct form
{
  unsigned int x1;
  unsigned int x2;
  unsigned int y1;
  unsigned int y2;
};

int main(void)
{
  struct form my_form;

  my_form.x1 = 10;
  my_form.x2 = 20;
  my_form.y1 = 30;
  my_form.y2 = 40;

  struct style my_style

      my_style.stroke = "black";
  my_style.fill = "red";
  my_style.stroke_opacity = "1";
  my_style.fill_opacity = "1";

  // tx et ty, sont les coordonnées de translation et angle de rotation

  my_style.tx = "0";
  my_style.ty = "0";
  my_style.angle = "0";

  // retirer les slash si j'ai implementer la fonction de la forme de fin de lignes et de jonctions de lignes
  //  my_style.*stroke_linecap;
  //  my_style.*stroke_linejoin;

  FILE *file = fopen("/home/bastien/Documents/Coda_/language_C /Project/Representation/nom_du_fichier.html", "w");
  if (file == NULL)
  {
    perror("Erreur fopen");
    return 1;
  }

  fprintf(file, "<svg viewBox=\"0 0 100 100\" xmlns=\"http://www.w3.org/2000/svg\"><line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" />\"\n", my_line.x1, my_line.x2, my_line.y1, my_line.y2, my_line.stroke);

  // pour stroke ici tu peux mettre un code en héxadécimal avec %x

  fclose(file);

  return EXIT_SUCCESS;
}