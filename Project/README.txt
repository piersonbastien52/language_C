Shape Manager

Projet réalisé en C permettant la création, la modification, l'affichage et la suppression de formes géométriques via une interface en ligne de commande (CLI).
Objectif

L'objectif de ce projet est de manipuler différentes formes géométriques à travers :

    l'utilisation de structures (struct)
    l'allocation dynamique de mémoire (malloc, free)
    les pointeurs
    les unions et énumérations
    la gestion de listes chaînées
    la validation des entrées utilisateur

Fonctionnalités actuelles
Gestion des points

Un point est défini par :

typedef struct
{
    int x;
    int y;
} Point_t;

Fonctions disponibles :

    création d'un point
    modification des coordonnées
    affichage des coordonnées
    libération de la mémoire associée

Gestion des formes

Le programme permet de manipuler plusieurs types de formes :

    Rectangle
    Carré
    Cercle
    Ellipse
    Ligne
    Polyligne

Chaque forme possède ses propres paramètres géométriques ainsi que des propriétés de style.
Gestion des couleurs

Les couleurs sont saisies par l'utilisateur au format hexadécimal :

#FF0000
#00FF00
#0000FF

La saisie est vérifiée afin de garantir la validité du format.
Gestion mémoire

Chaque objet créé dynamiquement est libéré lorsqu'il n'est plus nécessaire.

Exemple :

Point_t *point = create_point();

*ree(point*;
point = NULL;

Structure *u projet

project/
│
├──*main.c
│*├── Geometry/
│  *├── point.c
│  *├── point.h
│  *├── rectangle.c
*   ├── rectangle.h
│  *├── square.c
│  *├*─ square.h
│  *├── circle.c
│  *├── circle.h
│   ├── ellipse.c
│*  ├── ellipse.h
│  *├*─ line.c
│  *├── line.h
│*  ├── polylines.c
│  *└*─ polylines.h
│
├──*Representation/
│  *├*─ styles.c
│   └── styles.h
│
├*─ Utils/
│  *├── input.c*│   └── input.h
│
└──*README.md

*# Compilation

Avec GCC*:

*u

bash*gcc main*c Geometry/*.c Representation/*.c*Utils/*.c -o shapes*
Utilisation

L'utilisateur*peut :

1.Créer une forme. 2. Modifier ses popriétés. 3.*Modifier ses coordonnées. 4.Modifier ses couleurs. 5.Afficher les formes enregistres. 6. Supprimer une forme. 7. Quiter le programme.

##*Concepts travaillés

Ce projetpermetd'approfondir les notions suivante* :

    Structures
    Typedef
    Point*urs
    Allocationdynamique- Gestion*mémoire
    Listes chaînées
    Unions*- É*umérations
    Modèle de données
    Achitecturemodulaire en C
    Interface*CLI

Amliorations prévues

    Sauegarde des formes dans un fichier.- Chargement depuis un fichier.
    xportSVG.
    Gestion*de plusieurs couleurs.
    Rotationdesformes.
    Calcul automatique de l'ireet du périmètre.
    Interface plus *oussée pour l'édition.

Auteur

*Bastien
Projet daprentissage du langage C axé sur le* structures dedonnées, l'allocation dynamique etla programmation modulaire.