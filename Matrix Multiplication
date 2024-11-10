#include <stdio.h>
#include <stdlib.h>

int **matrix_read(char *fname, int *row, int *col) {

    int i, j, **m;
    FILE *fp;

    fp = fopen(fname, "r");
    if (fp == NULL) {
        fprintf(stderr, "File open error (file=%s).\n", fname);
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d %d", row, col);
    m = (int **) malloc((*row) + sizeof(int *));
    if (m == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < *row; i++) {
        m[i] = (int *) malloc((*col) * sizeof(int));
        if (m[i] == NULL) {
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        for (j = 0; j < *col; j++) {
            fscanf(fp, "%d", &m[i][j]);
        }
    }

    fclose(fp);
    return m;
}

int **product(int **m1, int r1, int c1, int **m2, int r2, int c2){

    int i, j, k, **m3;

    m3 = (int **)malloc(r1 * sizeof(int *));
    if (m3 == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<r1; i++){
        m3[i] = (int *)malloc(c2 * sizeof(int));
        if (m3[i] == NULL){
            fprintf(stderr, "Memory allocation error.\n");
            exit(EXIT_FAILURE);
        }
        for (j=0; j<c2; j++){
            m3[i][j] = 0;
            for (k=0; k<c1; k++){
                m3[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return m3;
}

void matrix_write(char *name, int **m, int r, int c){
    int i, j;
    FILE *fp;

    fp = fopen(name, "w");
    if (fp == NULL){
        fprintf(stderr, "File open error (file=%s).\n", name);
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%d °%d\n", r ,c);
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            fprintf(fp, "%d", m[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

void matrix_quit(int **m, int r){
    int i;

    for (i=0; i<r; i++){
        free(m[i]);
    }
    free(m);
}

int main(int argc, char *argv[]){

    int **m1, **m2, **m3;
    int r1, c1, r2, c2;
    
    if (argc<4){
        fprintf(stderr, "Error: missing parameter.\n");
        return EXIT_FAILURE;
    }

    m1 = matrix_read(argv[1], &r1, &c1);
    m2 = matrix_read(argv[2], &r2, &c2);

    if(r2 != c1){
        fprintf(stderr, "Error: incompitable dimensions.\n");
        return EXIT_FAILURE;
    }

    m3 = product(m1, r1, c1, m2, r2, c2);
    matrix_write(argv[3], m3, r1, c2);

    matrix_quit(m1, r1);
    matrix_quit(m2, r2);
    matrix_quit(m3, r1);

    return 0;
}
