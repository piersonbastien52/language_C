#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Representation/library/apply_style.h"
#include "Representation/library/color.h"
#include "Representation/library/ask_for_a_flint.h"
#include "Representation/library/Points.h"
#include "Representation/library/point.h"
#include "Representation/library/styles.h"
#include "Representation/library/rectangle.h"
#include "Representation/library/circle.h"
#include "Representation/library/ellipse.h"
#include "Representation/library/line.h"
#include "Representation/library/square.h"
#include "Representation/library/enum.h"
#include "Representation/library/generation.h"

int main(void)
{
    main_menu();
}

int ask_navigation(char *menu, int min, int max)
{
    return ask_for_limited_int(menu, min, max);
}

void main_menu(Landmark_t **chain)
{
    int choice = ask_navigation(
        "--- SHAPE MANAGER ---"
        "1.Create a shape\n"
        "2.Editing\n"
        "3.Loading\n"
        "4.Visualize\n"
        "5.Delete shape\n"
        "6.Leave\n"
        "Enter your choice (1-6): \n",
        1, 6);

    switch (choice)
    {
    case 1:
        menu_create_shape(chain);
        break;
    case 2:
        editing();
        break;
    case 3:
        loading();
        break;
    case 4:
        visualize();
        break;
    case 5:
        delete_shape();
        break;
    case 6:
        return 0;
        break;
    default:
        printf("wrong input");
        break;
    }
    return;
}

void menu_create_shape(Landmark_t **chain)
{
    int choice = ask_navigation(
        "--- CHOOSE A SHAPE ---"
        "1.Rectangle\n"
        "2.Square\n"
        "3.Circle\n"
        "4.Ellipse\n"
        "5.Line\n"
        "6.Return\n"
        "Enter your choice (1-6): \n",
        1, 6);

    List_shape_t *new_node = malloc(sizeof(List_shape_t));
    if (new_node == NULL)
    {
        printf("Error during the creation of a new link\n");
        return;
    }

    new_node->next = NULL;
    new_node->previous = NULL;

    switch (choice)
    {
    case 1:
    {
        new_node->shape.type = FORM_RECTANGLE;
        new_node->shape.data.rectangle = create_rectangle();
        new_node->shape.styles = rectangle_styles();
        break;
    }
    case 2:
    {
        new_node->shape.type = FORM_SQUARE;
        new_node->shape.data.square = create_square();
        new_node->shape.styles = square_styles();
        break;
    }
    case 3:
    {
        new_node->shape.type = FORM_CIRCLE;
        new_node->shape.data.circle = create_circle();
        new_node->shape.styles = circle_styles();
        break;
    }
    case 4:
    {
        new_node->shape.type = FORM_ELLIPSE;
        new_node->shape.data.ellipse = create_ellipse();
        new_node->shape.styles = ellipse_styles();
        break;
    }
    case 5:
    {
        new_node->shape.type = FORM_LINE;
        new_node->shape.data.line = create_line();
        new_node->shape.styles = line_styles();
        break;
    }
    case 6:
    {
        return;
    }
    default:
        free(new_node);
        return;
    }

    *chain = add_node(*chain, new_node);

    printf("The shape is created with success!\n");
}

void editing(Landmark_t **chain)
{
    int choice = ask_navigation(
        "--- MODIFYING ---"
        "1.Modify coordonates\n"
        "2.modify styles (colors and angle)\n"
        "3.Return\n"
        "Enter your choice (1-3): \n",
        1, 3);

    switch (choice)
    {
    case 1:
    {
        modify_coordonates(chain);
        break;
    }
    case 2:
    {
        modify_styles_applied(chain);
        break;
    }
    case 3:
    {
        return;
    }
    default:
    {
        printf("wrong input");
        break;
    }
    }
}

void modify_coordonates(Landmark_t *chain)

{
    if (chain == NULL || chain->start == NULL)
    {
        printf("Any shape saved\n");
        return;
    }
    print_shapes_list(chain);
    unsigned int index = ask_for_limited_int(
        "Which shape would you modify ?\n",
        0,
        chain->length - 1);

    List_shape_t *current = chain->start;

    for (unsigned int i = 0; i < index; i++)
    {
        current = current->next;
    }

    Shape_t *shape = &current->shape;

    switch (shape->type)
    {
    case FORM_RECTANGLE:
        modify_rectangle(shape->data.rectangle);
        break;

    case FORM_SQUARE:
        modify_square(shape->data.square);
        break;

    case FORM_CIRCLE:
        modify_circle(shape->data.circle);
        break;

    case FORM_ELLIPSE:
        modify_ellipse(shape->data.ellipse);
        break;

    case FORM_LINE:
        modify_line(shape->data.line);
        break;
    }
}

void modify_styles_applied(Landmark_t *chain) // il sera important de verifier de savoir si l'user sait quel index trouver les formes !!
{
    if (chain == NULL || chain->start == NULL)
    {
        printf("Any shape saved\n");
        return;
    }
    print_shapes_list(chain);
    unsigned int index = ask_for_limited_int(
        "which shape would you modify ?\n",
        0,
        chain->length - 1);

    List_shape_t *current = chain->start;

    for (unsigned int i = 0; i < index; i++)
    {
        current = current->next;
    }

    modify_style(current->shape.styles);
}

void visualize(void)
{
}

/*
Cette option permet de parcourir la liste chaînée (Landmark_t)
du premier au dernier élément pour afficher toutes les formes enregistrées :
 Parcourir les maillons via chain->start.
 Pour chaque maillon, vérifier le type (shape.type) grâce au switch :
 Si FORM_RECTANGLE : appeler print_rectangle(shape.data.rectangle, &shape).
 Si FORM_CIRCLE : appeler print_circle(shape.data.circle, &shape).
 (Idem pour les autres formes et pour afficher le style associé).
 */

void delete_shape()
{
}
/*
Pour supprimer proprement une forme de la liste :
Afficher la liste des formes existantes avec leurs indices.
Demander l'index de la forme à supprimer via ask_for_limited_int.
Appeler la fonction supp_node(chain, index) que vous avez déjà écrite dans generation.c,
qui se chargera de libérer la mémoire de la forme, de ses styles et du maillon associé (free_node).
*/