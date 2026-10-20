#ifndef APPLY_STYLE_H
#define APPLY_STYLE_H
#include "styles.h"

Styles_t *create_translate(Styles_t *style);
void create_style(Styles_t *style);
void modify_style(Styles_t *style); // voir si oil n'y a pas un moyen de modifierqu'une seule valeur et pas toute, pas besoin de boucle ??
void print_style(Styles_t *style);
void delete_style(Styles_t *style);

#endif