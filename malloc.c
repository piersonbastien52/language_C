#include<stdlib.h>
#include<stdio.h>

int main(void)

{

//je créer un pointeur, dans lequel je met 100 int différents 

    int *tab;
        tab = malloc(sizeof(int) * 100);
    free(tab);

 // je libères lkes 100 int occupé

    return EXIT_SUCCESS; 
}