#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define Rowlength 20

int main(int argc, char *argv[]){

    int i;
    FILE *fin, *fout;
    char c, blank;

    if(argc<3){
        printf("Error: missing parameter.");
        printf("\nRun as: %s <input_file> <output_file>.\n", argv[0]);
    }


    fin = fopen(argv[2], "r");
    if(fin == NULL){
        printf("Error when opening the input file.\n");
        return -1;
    }

    fout = fopen(argv[2], "w");
    if(fout == NULL){
        printf("Error when opening the input file.\n");
        return -1;
    }

    i = 0;
    blank = 0;
    while(fscanf(fin, "%c", &c) != EOF){
        if(c != '\n'){
            if(c == ' '){
                blank = 1;
            }
            else{
                if(blank){
                    c = toupper(c);
                    blank = 0;
                }
            }
            fprintf(fout, "%c", c);
            i++;

            if(i == Rowlength){
                fprintf(fout, "\n");
                i = 0;
            }
        }
    }
    if(i != 0){
        fprintf(fout, "\n");
    }



    fclose(fin);
    fclose(fout);
    return 0;
}
