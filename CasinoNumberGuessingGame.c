#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void bet(int *bet){

    int temp;
    printf("Enter your bet amount:");
    scanf("%d", &temp);
    *bet = temp;
}

int main(){

    int in, curr, betAmount, guess;
    int rolledNum;
    char check;

    srand(time(NULL));
    
    printf("Enter the inital amount of money:");
    scanf("%d", &in);

    curr = in;
    do{

        if(curr <= 0){
            printf("You don't have enough money. Game over!\n:");
            break;
        }
        printf("Your current money is: %d\n", curr);

        bet(&betAmount);

        if(betAmount > curr) {
            printf("You cannot bet more than your current balance!\n");
            continue;
        }

        printf("Guess a number between 1 and 10:");
        scanf("%d", &guess);

        rolledNum = (rand() %10) + 1;

        printf("Rolled number: %d and you guessed %d\n", rolledNum, guess);

        if(guess == rolledNum){
            printf("Congratulations! You won %d.\n", betAmount);
            curr += betAmount;
        }
        else{
            printf("You have lost %d\n", betAmount);
            curr -= betAmount;
        }

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &check);


    }while(check == 'y' || check == 'Y');

    printf("Game over! You ended with $%d\n", curr);

    return 0;
}
