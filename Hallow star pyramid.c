#include <stdio.h>

void hallow(int n){
    int col = 0;
    int i, k;
    for (i =0; i<n-1; i++){
        for (k=0; k<n-i; k++){
            printf(" ");
        }

        for (col = 0; col<= 2*i; col++){
            if(col ==0 || col== 2*i){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    printf(" ");
    for(i =0; i<2*n-1; i++)
        printf("*");


}

int main() {
    int n;

    printf("Enter the number of rows:");
    scanf("%d", &n);

    hallow(n);

    return 0;
}
