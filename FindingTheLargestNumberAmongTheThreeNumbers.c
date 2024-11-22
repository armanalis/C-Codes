#include <stdio.h>

void largestnumber(int n1, int n2, int n3){

    int largest = 0;
    if(n1>=n2 && n1>=n3){
        largest = n1;
    }
    else if(n2>=n1 && n2>=n3){
        largest = n2;
    }
    else{
        largest = n3;
    }
    printf("The largest number is: %d", largest);

}
int main() {

    int n1, n2, n3;

    printf("Enter three numbers separated with comma:");
    scanf("%d,%d,%d", &n1, &n2, &n3);
    largestnumber(n1, n2, n3);

    return 0;
}
