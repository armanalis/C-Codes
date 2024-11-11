#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 60+1

char **input_read(char *name, int *num){
    char word[MAX_LENGTH], **strings;
    int i=0, n;
    FILE *fp;

    fp = fopen(name, "r");
    if (fp == NULL){
        fprintf(stderr, "Error while opening a file.\n");
        exit(EXIT_FAILURE);
    }
    while(fscanf(fp, "%s", word) != EOF) {
        i++;
    }
    fclose(fp);
    n = i;
    *num = n;

    strings = (char **) malloc(n * sizeof(char *));
    if(strings == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(name, "r");
    if (fp == NULL){
        fprintf(stderr, "Error while opening a file.\n");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<n; i++){
        fscanf(fp, "%s", word);
        strings[i] = (char *) malloc((strlen(word) + 1) * sizeof(char));
        if(strings[i] == NULL){
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        strcpy(strings[i], word);
    }

    return strings;
}

void string_sort(char ** strings, int num){
    int i, j;
    char *ptr;

    for(i=1; i<num; i++){
        ptr = strings[i];
        j = i;
        while(--j>=0 && strcmp(ptr, strings[j])<0){
            strings[j+1] = strings[j];
        }
        strings[j+1] = ptr;
    }
}

void output_write(char *name, char **strings, int num){
    int i;
    FILE *fp;

    fp = fopen(name, "w");
    if (fp == NULL){
        fprintf(stderr, "Error while opening a file.\n");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<num; i++){
        fprintf(fp, "%s\n", strings[i]);
    }
    fclose(fp);
}

int main(){

    int i, num;
    char **strings;

    strings = input_read("C:\\Users\\arman\\CLionProjects\\YourProject\\cmake-build-debug\\input", &num);
    string_sort(strings, num);
    output_write("C:\\Users\\arman\\CLionProjects\\YourProject\\cmake-build-debug\\output", strings, num);

    for (i=0; i<num; i++){
        free(strings[i]);
    }
    free(strings);

    return 0;
}

