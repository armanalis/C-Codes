#include <stdio.h>
#include <stdlib.h>

struct person{
    int id;
    char fname[20];
    char lname[20];
};

int main() {

    FILE *outfile;

    outfile = fopen("C:\\Users\\arman\\CLionProjects\\YourProject\\new.txt", "wb");
    if (outfile == NULL){
        fprintf(stderr, "\n Error opened file.\n");
        exit(1);
    }

    struct person fperson = {1, "ali", "dai"};

    int flag = 0;
    flag = fwrite(&fperson, sizeof(struct person), 1, outfile);

    if (flag = 1){
        printf("Contents of the structure written successfully.");
    }
    else
        printf("Error writing to file-");

    fclose(outfile);

    return 0;
}
