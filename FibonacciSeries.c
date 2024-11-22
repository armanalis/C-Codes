#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *p;
    int n, i = 0;
    printf("How many numbers you wanna see in fibonacci sequence: ");
    scanf("%d", &n);
    if (n < 1){
        printf("Invalid number. Error!!!");
        exit(1);
}
    
    p = (int *) malloc(n * sizeof(int));

    while (i < 2){
        p[i] = i;
        i++;
}
    while(i<n){
        p[i] = p[i-1]+ p[i-2];
        i++;
    }
    for(int k=0;k<n;k++)
        printf("%d\n", p[k]);

    return 0;
}

