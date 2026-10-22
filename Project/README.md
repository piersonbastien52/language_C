# 📐 Shape Manager CLI (C Project)

Un gestionnaire de formes géométriques en ligne de commande (CLI) développé en **Langage C (C99)**. Ce programme permet de créer, modifier, visualiser, supprimer et exporter des formes géométriques vectorielles au format SVG.

---

## 🚀 Fonctionnalités

- **Formes supportées** :
  - Rectangle (origine, hauteur, largeur)
  - Carré (origine, hauteur)
  - Cercle (centre, rayon)
  - Ellipse (centre, rayon horizontal, rayon vertical)
  - Ligne (deux points de coordonnées)
- **Gestion des Styles** :
  - Couleurs de remplissage et de contour personnalisables (format hexadécimal `#RRGGBB`).
  - Opacités réglables pour le contour et le remplissage.
  - Épaisseur de trait paramétrable.
  - Transformations géométriques (Vecteur de translation `tx, ty` et angle de rotation).
- **Structure de Données** : Implémentation d'une liste chaînée doublement chaînée (`Landmark_t` / `List_shape_t`) pour gérer dynamiquement la collection de formes.
- **Exportation** : Génération d'un fichier de sortie au format **SVG** pour visualiser graphiquement les créations.

---

## Compiler et lancer 

- **Compiler et lancer** :
   - Ouvrir un terminal dans le dossier Project.
   - Lancer le Makefile avec la commande make build. 
   - Exécuter le fichier généré : ./Project
   - Il est conseillé de sortir du programme depuis le menu principale/ 6.leave.

---

## 📂 Architecture du Projet

```text
Project/
│
├── All_shapes.c                # Implémentation des formes (création, modification, affichage, suppression)
├── project_CLI.c               # Point d'entrée principal et gestion des menus de la CLI
├── Makefile                    # Fichier d'automatisation de la compilation
│
├── CLI/
│   └── CLI_library.c           # Fonctions utilitaires d'affichage et de navigation CLI
│
├── export/
│   ├── export.c                # Logique d'exportation au format SVG
│   └── export.h                # En-tête pour l'export SVG
│
└── Representation/
    ├── generation.c            # Gestion de la liste chaînée et désallocation mémoire
    └── library/                # Fichiers d'en-tête et sous-modules (structures, styles, points, etc.)
        ├── All_shapes.h
        ├── apply_style.h
        ├── circle.h
        ├── color.h
        ├── ellipse.h
        ├── enum.h
        ├── line.h
        ├── point.h
        ├── Points.h
        ├── rectangle.h
        ├── square.h
        └── styles.h
```
