#ifndef GENERATION_H
#define GENERATION_H
#include "enum.h"

typedef struct List_shape_s List_shape_t;
struct List_shape_s;
typedef struct Landmark_s;
Landmark_t *add_node(Landmark_t *chain, List_shape_t *link);
void free_node(List_shape_t *node);                   // libère la mémoire contenu dans le maillon de shape
void free_shape(Shape_t *shape);                      // double itération de free, ici et dans all_shapes, trouver comment appeler une des deux fonctions
int supp_node(Landmark_t *chain, unsigned int index); // supression d'un maillon dans la liste chainée

#endif