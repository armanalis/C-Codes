#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINT 100

struct point{
    float x, y, z;
    float distance;
};

int read_points(char *name, struct point points[]){

    float x, y, z;
    FILE *fp;
    int i = 0;

    fp = fopen(name, "r");
    if(fp == NULL){
        printf("File open error! (file = %s).\n", name);
        exit(EXIT_FAILURE);
    }

    while(fscanf(fp, "%f%f%f", &x, &y, &z) != EOF && i < MAX_POINT){
        points[i].x = x;
        points[i].y = y;
        points[i].z = z;
        points[i].distance = sqrt(pow(x,2) + pow(y,2) + pow(z, 2));
        i++;
    }
    fclose(fp);

    return i;
}

void sort_points(struct point points[], int n_points){
    int i, j;
    struct point current;

    for(i=1; i<n_points; i++){
        current = points[i];
        j = i;
        while((--j >= 0) && (current.distance < points[j].distance)){
            points[j+1] = points[j];
        }
        points[j+1] = current;
    }
}

void write_points(char *name, struct point points[], int n_points){
    FILE *fp;
    int i;
    
    fp = fopen(name, "w");
    if(fp == NULL){
        printf("File open error (file=%s).\n");
        exit(EXIT_FAILURE);
    }
    for(i=0; i<n_points; i++){
        fprintf(fp, "%f %f %f %f\n", points[i].x, points[i].y, points[i].z, points[i].distance);
    }
    fclose(fp);
}

int main(int argc, char *argv[]){

    struct point space_points[MAX_POINT];
    int n_point;

    if(argc < 3){
        printf("Error: Missing parameter!!");
        return -1;
    }

    n_point = read_points(argv[1], space_points);
    sort_points(space_points, n_point);
    write_points(argv[2], space_points, n_point);

    return 0;
}
