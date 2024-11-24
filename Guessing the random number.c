#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){

int number, input;
srand ( time(NULL) );
number = rand() % 10 + 1; // generates a random number
    
printf("%d", number); // displays the number
do {
    printf ("\nGuess the number (1 to 10): ");
    scanf ("%d",&input);
    if (number > input)
        printf ("The number is higher\n");
    else if (number < input)
        printf("The number is lower\n");
    else 
        break;
} while (number!=input);
printf ("That is correct!\n");

return 0;
}
