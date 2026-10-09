#include<stdio.h>
#include<stdlib.h>


// tu peux à la place des paramètres ici mettre "void" ou "" (rien)

int main (int argc, char **argv)

{

// utiliser un pointeur à la place d'un tableau, je ne sais pas pourquoi mais ce fonctionne mieux

uint age = 23;
unsigned char* prenom = "Bastien";
unsigned char* nom = "PIERSON";

// pense bien à déclarer l'ordre de tes variables àprès ton printf. 

    printf("mon prenom est : %s %s et mon age est %d ans\n", prenom, nom, age);
    return EXIT_SUCCESS;
}
