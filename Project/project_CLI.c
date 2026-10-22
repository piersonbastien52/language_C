/**
 * @file project_CLI.c
 * @brief Command Line Interface (CLI) implementation for managing geometric shapes and their styles.
 */

#include <stdio.h>
#include "export/export.h"
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

void main_menu(Landmark_t **chain);
void menu_create_shape(Landmark_t **chain);
void editing(Landmark_t **chain);
void loading(void); // ou à implémenter selon vos besoins
void visualize(Landmark_t *chain);
void delete_shape(Landmark_t *chain);
void modify_coordonates(Landmark_t *chain);
void modify_styles_applied(Landmark_t *chain);
void print_shapes_list(Landmark_t *chain);

/**
 * @brief Main entry point of the CLI application.
 * @details Initializes the shape list container and launches the interactive main menu loop.
 * @return 0 on successful application termination.
 */

int main(void)
{
    Landmark_t *chain = NULL; // initialisation de la liste chainée

    main_menu(&chain);
}

int ask_navigation(char *menu, int min, int max)
{
    return ask_for_limited_int(menu, min, max);
}

/**
 * @brief Displays the main navigation menu and routes user selections to corresponding submenus.
 * @param chain Pointer to the Landmark_t linked list container managing all active shapes.
 */

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
        editing(*chain);
        break;
    case 3:
        loading();
        break;
    case 4:
        visualize(*chain);
        break;
    case 5:
        delete_shape(*chain);
        break;
    case 6:
        return;
        break;
    default:
        printf("wrong input");
        break;
    }
    return;
}

/**
 * @brief Displays the shape creation menu and handles insertion of new shapes into the list.
 * @param chain Pointer to the Landmark_t linked list container.
 */

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

/**
 * @brief Displays the shape modification menu allowing users to edit shape attributes or styles.
 * @param chain Pointer to the Landmark_t linked list container.
 */

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
        printf("No shape saved\n");
        return;
    }
    print_shapes_list(chain); // permet au user de voir la liste des formes contenu dans la liste chainée
    unsigned int index = ask_for_limited_int(
        "Which shape would you modify ?\n",
        0,
        chain->length - 1);

    List_shape_t *current = chain->start;
    /**
     * @brief Displays the shape modification menu allowing users to edit shape attributes or styles.
     * @param chain Pointer to the Landmark_t linked list container.
     */
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

void modify_styles_applied(Landmark_t *chain)
{
    if (chain == NULL || chain->start == NULL)
    {
        printf("No shape saved\n");
        return;
    }
    print_shapes_list(chain); // permet au user de voir la liste des formes contenu dans la liste chainée
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

/**
 * @brief Displays details and style properties of a selected shape from the linked list.
 * @param chain Pointer to the Landmark_t linked list container.
 */

void visualize(Landmark_t *chain)
{
    if (chain == NULL || chain->start == NULL)
    {
        printf("No shape saved\n");
        return;
    }
    print_shapes_list(chain); // permet au user de voir la liste des formes contenu dans la liste chainée
    unsigned int index = ask_for_limited_int(
        "Which shape would you display ?\n",
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
        print_rectangle(shape->data.rectangle);
        print_style(shape->styles);
        break;

    case FORM_SQUARE:
        print_square(shape->data.square);
        print_style(shape->styles);
        break;

    case FORM_CIRCLE:
        print_circle(shape->data.circle);
        print_style(shape->styles);
        break;

    case FORM_ELLIPSE:
        print_ellipse(shape->data.ellipse);
        print_style(shape->styles);
        break;

    case FORM_LINE:
        print_line(shape->data.line);
        print_style(shape->styles);
        break;
    }
    int export_svg(Landmark_t * landmark, const char *file_name);
}

/**
 * @brief Interactively prompts user to select and delete a shape from the list.
 * @param chain Pointer to the Landmark_t linked list container.
 */

void delete_shape(Landmark_t *chain) // regarder si c'est possible de mettre une option leave sans forcément supprimer
{
    if (chain == NULL || chain->start == NULL)
    {
        printf("No shape saved\n");
        return;
    }
    print_shapes_list(chain); // permet au user de voir la liste des formes contenu dans la liste chainée

    printf("[%u] Return\n", chain->length);

    unsigned int index = ask_for_limited_int(
        "which shape would you delete ?\n",
        0,
        chain->length);

    if (index == chain->length)
    {
        return;
    }
    if (supp_node(chain, index) == 1)
    {
        printf("Shape deleted successfully.\n");
    }
    else
    {
        printf("Error while deleting shape.\n");
    }
}
