#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "library/enum.h"

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
    return chain;
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

void free_node(List_shape_t *node)
{
  if (node == NULL)
  {
    return;
  }
  free_shape(&node->shape);
  free(node);
}

void free_shape(Shape_t *shape)
{
  if (shape == NULL)
  {
    return;
  }
  delete_style(shape->styles);

  switch (shape->type)
  {
  case FORM_CIRCLE:
    delete_circle(shape->data.circle);
    break;

  case FORM_ELLIPSE:
    delete_ellipse(shape->data.ellipse);
    break;

  case FORM_RECTANGLE:
    delete_rectangle(shape->data.rectangle);
    break;

  case FORM_SQUARE:
    delete_square(shape->data.square);
    break;

  case FORM_LINE:
    delete_line(shape->data.line);
    break;
  }
}

int supp_node(Landmark_t *chain, unsigned int index)
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
    {
      next->previous = previous;
    }
  }
  free_node(current);

  chain->length--;
  return 1;
}
#include "library/styles.h"
#include "library/rectangle.h"
#include "circle.h"
#include "ellipse.h"
#include "line.h"
#include "square.h"
