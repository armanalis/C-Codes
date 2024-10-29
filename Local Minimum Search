#include <stdio.h>
#include <stdlib.h>

#define R 3
#define C 2

int main(void){

    int row, col, matrix[R][C];
    int i, j, flag;

    for(i=0; i<R; i++){
        for(j=0; j<C; j++){
            do {
                printf("Element [%d][%d]= ", i, j);
                scanf("%d", &matrix[i][j]);
            } while (matrix[i][j]<=0);
        }
    }

    for(row=0; row<R; row++) {
        for (col = 0; col < C; col++) {

            flag = 1;//it means the row and col is a local minimum.

            for(i=row-1; i<=row+1 && flag==1; i++){
                for(j=col-1; j<=col+1 && flag==1; j++){
                    if((i!=row || j!=col) && i<R && i>=0 && j<C && j>=0){
                        if(matrix[row][col] >= matrix[i][j]){
                            flag = 0;
                        }
                    }
                }
            }

            if(flag){
                printf("\nLocal Minumum (value=%d)", matrix[row][col]);
                printf(" at row=%d, column=%d.", row, col);
            }
        }
    }

    return 0;
}
