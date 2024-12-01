#include <stdio.h>
#include <stdlib.h>

void display(int map[9][9]){

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
}

int isvalid(int map[9][9], int row, int col, int num){

    for(int x=0; x<9; x++){
        if(map[row][x] == num || map[x][col] == num)
            return 0;
    }
    int startrow = row-row%3, startcol = col- col%3;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(map[i + startrow][j + startcol] == num)
                return 0;
        }
    }
}

int sudokusolver(int map[9][9]){

    int row= -1, col = -1;
    int empty = 0;

    for(int i=0; i<9 && !empty; i++){
        for(int j=0; j<9 && !empty; j++){
            if(map[i][j] == 0){
                row = i;
                col = j;
                empty = 1;
            }
        }
    }
    if(!empty)
        return 1;

    for(int num=1; num<=9; num++){
        if(isvalid(map, row, col, num)){
            map[row][col] = num;
            if(sudokusolver(map))
                return 1;
            map[row][col] = 0;
        }
    }
    return 0;
}

int main(void){

    int map[9][9] = {{6, 3, 7, 1, 5, 9, 2, 4, 8},
                     {2, 8, 1, 3, 4, 7, 9, 5, 6},
                     {5, 9, 4, 2, 6, 8, 1, 7, 3},
                     {8, 1, 6, 5, 9, 2, 7, 3, 4},
                     {4, 2, 9, 7, 8, 3, 6, 1, 5},
                     {3, 7, 5, 6, 1, 4, 8, 2, 9},
                     {7, 4, 2, 9, 3, 6, 5, 8, 1},
                     {9, 5, 3, 8, 2, 1, 4, 6, 7},
                     {1, 6, 8, 4, 7, 5, 3, 9, 2}
    };// this is the example solved sudoku to check my program works or not.
     /*normally the code should be like this:
     int map[9][9];
     printf("Enter the full map(should be 9x9):");

     for(int i=0; i<9; i++){
         for(int j=0; j<9; j++){
             scanf("%d", &map[i][j]);
         }
     }
*/

     if(sudokusolver(map)){
         printf("Sudoku solution:\n");
         display(map);
     }
     else {
         printf("No solution exists. \n");
     }

    return 0;
}
