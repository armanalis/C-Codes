#include <stdio.h>
#include <stdlib.h>

void palindrome(char *str){
    printf("%s\n", str);
    char *ptr, *rev;
    ptr = str;

    while(*ptr != '\0'){
        ++ptr;
    }
    --ptr;
    for(rev = str; ptr>=rev;){
        if(*ptr == *rev){
            --ptr;
            rev++;
        }
        else
            break;
    }
    if(rev>ptr)
        printf("String is palindrome");
    else
        printf("is not palindrome");

}
int main()
{
    char str[80];
    printf("Enter the string:");
    scanf("%s", str);

    palindrome(str);

    return 0;
}
