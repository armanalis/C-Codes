#include <stdio.h>
#include <stdlib.h>

#define MAX 20


void reverse_print (char *s) {
    if (*s == '\0') {
        return;
    }
    reverse_print (s+1);
    printf ("%c", *s);
    return;
}

int main() {
    char str[MAX + 1];

    printf("Input string: ");
    scanf("%s", str);
    printf("Reverse string is: ");

    reverse_print(str);

    return 0;
}
