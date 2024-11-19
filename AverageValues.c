#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define TRUE 1
#define FALSE 0

int validate(int x, int y);

float average(float matrixIn[MAX][MAX], int x, int y){

    int i, j, count;
    float sum;

    sum = count = 0;
    for(i=-1; i<=1; i++){
        for(j=-1; j<=1; j++){
            if((i!=0 || j!=0) && validate(x+i, y+j) == TRUE){
                count++;
                sum += matrixIn[x+i][y+j];
            }
        }
    }
    return sum/count;
}

int validate (int x, int y){
    if(x<0 || x>=MAX)
        return FALSE;
    if(y<0 || y>=MAX)
        return FALSE;

    return TRUE;
}

int main(void){

    float matrixIn[MAX][MAX], matrixAvg[MAX][MAX];
    int i, j, r, c;

    for(i=0; i<MAX; i++){
        for(j=0; j<MAX; j++){
            printf("Element[%d][%d]=", i, j);
            scanf("%f", &matrixIn[i][j]);
        }
    }

    for(r=0; r<MAX; r++){
        for(c=0; c<MAX; c++){
            matrixAvg[r][c] = average(matrixIn, r, c);
        }
    }

    printf("Output matrix:\n");
    for(r=0; r<MAX; r++){
        for(c=0; c<MAX; c++){
            printf("%6.2f", matrixAvg[r][c]);
        }
        printf("\n");
    }

    return 0;
}
