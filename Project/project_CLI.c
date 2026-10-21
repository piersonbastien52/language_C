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

int main(void)
{
    main_menu();
}

int ask_navigation(char *menu, int min, int max)
{
    return ask_for_limited_int(menu, min, max);
}

void main_menu(void)
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
        menu_create_shape();
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
    case 6:
        return 0;
        break;
    default:
        printf("wrong input");
        break;
    }
    return 0;
}

void menu_create_shape(void) // pas fini
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

    switch (choice)
    {
    case 1:
    {
        Rectangle_t *rect = create_rectangle();
        rectangle_styles(rect);
        break;
    }
    case 2:
    {
        Square_t *sqr = create_square();
        square_styles(sqr);
        break;
    }
    case 3:
    {
        Circle_t *crl = create_circle();
        circle_styles(crl);
        break;
    }
    case 4:
    {
        Ellipse_t *ellp = create_ellipse();
        ellipse_styles(ellp);
        break;
    }
    case 5:
    {
        Line_t *ln = create_line();
        line_styles(ln);
        break;
    }
    case 6:
    {
        main_menu();
    }
    default:
    {
        printf("wrong input");
        break;
    }
    }
}

/*
Enregistrer dans la liste chaînée :Allouer un nouveau maillon (List_shape_t),
y insérer la structure Shape_t (en renseignant le bon Shape_e type et la bonne union data,
ainsi que le pointeur styles).   Ajouter ce maillon à votre structure de suivi (Landmark_t)
à l'aide de la fonction add_node().
*/

void editing(void)
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
        modify_coordonates();
        break;
    }
    case 2:
    {
        modify_styles_applied();
        break;
    }
    case 3:
    {
        main_menu();
    }
    default:
    {
        printf("wrong input");
        break;
    }
    }
}

void modify_coordonates(void)
{
    int choice = ask_navigation(
        "--- MODIFY COORDONATES ---"
        "1.Rectangle\n"
        "2.Square\n"
        "3.Circle\n"
        "4.Ellipse\n"
        "5.Line\n"
        "6.Return\n"
        "Enter your choice (1-6): \n",
        1, 6);

    switch (choice)
    {
    case 1:
    {
        modify_rectangle();
        break;
    }
    case 2:
    {
        modify_square();
        break;
    }
    case 3:
    {
        modify_circle();
        break;
    }
    case 4:
    {
        modify_ellipse();
        break;
    }
    case 5:
    {
        modify_line();
        break;
    }
    case 6:
    {
        editing();
    }
    default:
    {
        printf("wrong input");
        break;
    }
    }
}

void modify_styles_applied(void)
{
    int choice = ask_navigation(
        "--- MODIFY STYLES ---"
        "1.Rectangle\n"
        "2.Square\n"
        "3.Circle\n"
        "4.Ellipse\n"
        "5.Line\n"
        "6.Return\n"
        "Enter your choice (1-6): \n",
        1, 6);

    switch (choice)
    {
    case 1:
    {
        rectangle_styles();
        break;
    }
    case 2:
    {
        square_styles();
        break;
    }
    case 3:
    {
        circle_styles();
        break;
    }
    case 4:
    {
        ellipse_styles();
        break;
    }
    case 5:
    {
        line_styles();
        break;
    }
    case 6:
    {
        editing();
    }
    default:
    {
        printf("wrong input");
        break;
    }
    }
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

void delete_shape();
{
}
/*
Pour supprimer proprement une forme de la liste :
Afficher la liste des formes existantes avec leurs indices.
Demander l'index de la forme à supprimer via ask_for_limited_int.
Appeler la fonction supp_node(chain, index) que vous avez déjà écrite dans generation.c,
qui se chargera de libérer la mémoire de la forme, de ses styles et du maillon associé (free_node).
*/