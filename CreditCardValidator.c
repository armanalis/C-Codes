/*

This is a simple project that uses Luhn's algorithm to validate a user's credit card.
The program works for all popular cards like Visa,Amex, MasterCard, etc. Luhn's algorithm checks for basic validations;
for example, a Visa card should start with 4 and then moves on to complex digit-wise calculations.
It is a good program to learn because most e-commerce transactions require credit card validation.

Solution starts here */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool is_digit_string(char *str){
    for (int i=0; str[i] != '\0'; i++){
        if(isdigit(str[i]) == false){
            return false;
        }
    }
    return true;
}

bool luhn(char *card_number){
    int n_digits = strlen(card_number);
    int sum = 0, digit;
    bool is_second = false;

    for (int i=n_digits-1; i>=0; i--){
        digit =card_number[i] - '0';

        if(is_second){
            digit *= 2;
            if (digit > 9){
                digit -= 9;
            }
        }

        sum += digit;
        is_second = !is_second;
    }
    return(sum % 10 == 0);
}

void card_type(char *card_number){
    if(card_number[0] == '4'){
        printf("This is a Visa card.\n");
    }
    else if(card_number[0] == '5' && (card_number[1] >= '1' && card_number[1] <= '5')){
        printf("This is a MasterCard.\n");
    }
    else{
        printf("Unknown card type.\n");
    }
}

int main(){
    char card_number[20];//19+1 card might be differ between 16-19

    printf("Enter your credit card number: ");
    scanf("%19s", card_number);

    if (strlen(card_number) < 16) {
        printf("Error: Credit card number must be at least 16 digits.\n");
        return 1;
    }

    if (is_digit_string(card_number) == false){//Checking the input is valid or not
        printf("Invalid input. Please enter only digits.\n");
        return 1;
    }

    if (luhn(card_number)){//Validate the card number using Luhn's Algorithm
        printf("Credit card is valid.\n");
        card_type(card_number);
    }
    else{
        printf("Credit card is invalid.\n");
    }

    return 0;
}

