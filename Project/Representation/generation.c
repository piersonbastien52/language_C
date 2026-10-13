
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "styles.c"
#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "line.h"
#include "square.h"

typedef struct Polylines_s Polylines_t;

struct Polylines_s
{

  Polylines_t *next;
  unsigned int x;
  unsigned int y;
};

typedef struct List_polylines_s
{

  Polylines_t *start;
  unsigned int length;

} List_polylines_t;

List_polylines_t *add_node(List_polylines_t *chain, Polylines_t *link)
{
  if (chain == NULL)
  {
    List_polylines_t *new_chain = malloc(sizeof(List_polylines_t));
    new_chain->start = link;
    if (link == NULL)
    {
      new_chain->length = 0;
    }
    else
    {
      new_chain->length = 1;
    }
    return new_chain;
  }

  if (link == NULL)
  {
    return link;
  }

  if (chain->start == NULL)
  {
    chain->start = link;
    chain->length++;
    return chain;
  }

  Polylines_t *temp = chain->start;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = link;
  chain->length++;
  return chain;
}

int get_value(List_polylines_t *chain, unsigned int index)
{
  if (chain == NULL)
    return -1;
  int i = 0;
  Polylines_t *temp = chain->start;
  while (i != index && temp != NULL)
  {
    temp = temp->next;
    i++;
  }

  if (temp == NULL)
    return -1;

  return temp->next;
}

typedef enum
{
  FORM_RECTANGLE,
  FORM_SQUARE,
  FORM_CIRCLE,
  FORM_ELLIPSE,
  FORM_LINE,
  FORM_POLYLINES,
} Shape_e;

typedef struct
{
  Shape_e type;
  union
  {
    Circle_s *circle;
    Ellipse_s *ellipse;
    Rectangle_s *rectangle;
    Square_s *square;
    Line_s *lines;
    Polylines_t *polylines;
    Styles_s *style;
  } data;
} Shape_s;

typedef struct List_shape_s List_shape_t;

struct List_shape_s
{
  List_shape_t *next;
  List_shape_t *previous;
  Shape_s shape;
};

typedef struct Landmark_s
{
  List_shape_t *start;
  unsigned int length;

} Landmark_t;

Landmark_t *add_node(Landmark_t *chain, List_shape_t *link)
{
  if (chain == NULL)
  {
    Landmark_t *new_chain = malloc(sizeof(Landmark_t));
    new_chain->start = link;
    if (link == NULL)
    {
      new_chain->length = 0;
    }
    else
    {
      new_chain->length = 1;
    }
    return new_chain;
  }

  if (link == NULL)
  {
    return link;
  }

  if (chain->start == NULL)
  {
    chain->start = link;
    chain->length++;
    return chain;
  }

  List_shape_t *temp = chain->start;

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  temp->next = link;
  chain->length++;
  return chain;
}

void free_node(List_shape_t *node) // libère la mémoire contenu dans le maillon de shape
{
  free_form(node->shape);
  free(node);
}

int supp_node(Landmark_t *chain, unsigned int index) // supression d'un maillon dans la liste chainée
{
  if (chain == NULL)
    return -1;

  List_shape_t *current = chain->start;

  unsigned int i = 0;

  while (current != NULL && i < index)
  {
    current = current->next;
    i++;
  }

  if (current == NULL)
  {
    return -1;
  }

  List_shape_t *previous = current->previous;
  List_shape_t *next = current->next;

  if (previous == NULL)
  {

    chain->start == next;

    if (next != NULL)
      next->previous = NULL;
  }
  else
  {
    previous->next = next;

    if (next != NULL)
      next->previous = previous;
  }

  previous->next = next;

  if (next != NULL)
    next->previous = previous;

  free_node(current);

  chain->length--;
  return chain;
}

int main(void)
{

  struct Styles_t my_style;

  FILE *file = fopen("/home/bastien/Documents/Coda_/language_C /Project/Representation/nom_du_fichier.html", "w");
  fprintf(file, "<svg viewBox=\"0 0 1000 1000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
  // modifier le chemin lorsque le dossier de sauvegarde est implémenté
  if (file == NULL)
  {
    perror("Erreur fopen");
    return 1;
  }

  fclose(file);

  return EXIT_SUCCESS;
}
