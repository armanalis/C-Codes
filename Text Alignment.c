#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 82 // 80 + "\n" + \0

int main(void){

    char name[MAX], line[MAX];
    int i, num_space;
    FILE *fp;

    printf("Enter input text file name: ");
    scanf("%s", name);
    fp = fopen(name, "r");
    if(fp == NULL){
        printf("Error when opening the input file.\n");
        return -1;
    }
    printf("Centered text:\n");
    while(fgets(line, MAX, fp) != NULL) {
        num_space = (MAX - strlen(line)) / 2;
        for (i = 0; i < num_space; i++){
            printf(" ");
        }
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}
