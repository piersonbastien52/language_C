#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "styles.h"
#include "rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "line.h"
#include "square.h"
#include "polylines.h"
#include "enum.h"

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
  link->previous = temp;
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

    chain->start = next;

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
  return 1;
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

// idée de con : dépalcer les maillons arrière plan, premier plan