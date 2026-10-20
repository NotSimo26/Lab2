#include <stdio.h>
#include <stdlib.h>
void termina (char *msg){
    perror(msg);
    exit(-1);
}
int* initArray (int size){
    int *a;
    a = malloc(size * sizeof(int));
    if (a == NULL){
        termina("Malloc fallita");
    }
    return a;
}
int ** initMatrix(int x, int y){
    int **matrix = malloc(x *sizeof(int *)); // un puntatore ha 8 byte mentre un intero 4
    if (matrix == NULL) {
        termina("Malloc fallita");
    }
    for (int i = 0; i<x; i++){
        matrix[i] = initArray(y);
    }
    return matrix;
}
void freeMatrix(int **matrix, int x){
    for (int i = 0; i < x; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
void getSize (char*argv[], int *x, int*y){
    *x = atoi(argv[1]);
    *y = atoi(argv[2]);
    if ((*x == 0 && *argv[1] != '0') || (*y == 0 && *argv[2] != '0')){
        termina ("Gli argomenti devono essere interi !");
    }
}
int main (int argc, char *argv[]){
    if (argc < 3){
        termina("Troppi pochi argomenti !");
    }
    int x;
    int y;
    getSize(argv,&x, &y);
    int **matrix = initMatrix(x,y);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            matrix[i][j] = i + j;
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    freeMatrix(matrix, x);
}