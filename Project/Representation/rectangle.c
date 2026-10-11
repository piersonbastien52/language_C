
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct rectangle
{
  unsigned int x;
  unsigned int y;
  unsigned int width;
  unsigned int height;
  unsigned char *stroke;
};

int main(void)
{
  struct rectangle my_rectangle;
  my_rectangle.stroke = "black";
  my_rectangle.x = 10;
  my_rectangle.y = 20;
  my_rectangle.width = 30;
  my_rectangle.height = 40;

  FILE *file = fopen("/home/bastien/Documents/Coda_/language_C /Project/Representation/rectangle.html", "w");
  if (file == NULL)
  {
    perror("Erreur fopen");
    return 1;
  }

  fprintf(file, "<svg viewBox=\"0 0 100 100\" xmlns=\"http://www.w3.org/2000/svg\"><rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" stroke=\"%s\" />\"\n",
          my_rectangle.x, my_rectangle.y, my_rectangle.height, my_rectangle.width, my_rectangle.stroke);

  // pour stroke ici tu peux mettre un code en héxadécimal avec %x

  fclose(file);

  return EXIT_SUCCESS;
}
// une fonction qui écrit dans le fichier
