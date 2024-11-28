#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void displaychoice(int choice){

    if(choice == 1){
        printf("Rock");
    }
    else if(choice == 2){
        printf("Paper");
    }
    else if(choice == 3){
        printf("Scissors");
    }
}

int main(){

    int choice, comp_choice;
    char flag;

    srand(time(NULL));

    do{

        printf("Welcome to the Rock-Paper-Scissors Game\n");
        printf("1 for Rock\n");
        printf("2 for Paper\n");
        printf("3 for Scissors\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        if(choice<1 || choice>3){
            printf("\nInvalid choice. Please enter a new integer between 1 and 3\n");
            continue;
        }

        comp_choice = rand() % 3 +1;
        printf("Your choice: ");
        displaychoice(choice);
        printf("\nComputer's choice: ");
        displaychoice(comp_choice);

        if(choice == comp_choice){
            printf("\nIt's a draw.");
        }
        else if((choice == 1 && comp_choice == 2) || (choice == 2 && comp_choice == 3) || (choice == 3 && comp_choice == 1)){
            printf("\nComputer wins.");
        }
        else{
            printf("\nYou win!");
        }

        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &flag);

    }while(flag == 'y' || flag == 'Y');

    return 0;
}
