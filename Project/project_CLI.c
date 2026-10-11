#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


// interface en ligne et demande entrée utilisateur

int main(void)
{
    int choice;
    float num1, num2, result;
    
    printf("1.Créer\n");
    printf("2.Editer\n"); 
    printf("3.Sauver\n");
    printf("4.Charger\n");
    printf("5.Visualiser\n");
    printf("Enter your choice (1-5): \n");
    scanf("%d", &choice);  
} 

// en fonction de l'entrée utilisateur le code redirige 

int switch_choice(int choice) 
{
    SWITCH(choice)
        case 1: 
        case 2:
        case 3:
        case 4:
        case 5:
        default: printf("invalid entry\n"); break;
}



