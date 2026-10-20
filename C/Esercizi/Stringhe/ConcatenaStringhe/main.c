#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void termina (char *msg){
    perror(msg);
    exit(-1);
}
char* inizializzaStringa (int size){
    char *a;
    a = malloc(size * sizeof(char));
    if (a == NULL){
        termina("Malloc fallita");
    }
    return a;
}

int main (int argc, char *argv[]){
    int lunghezzaStr = 0;
    if (argc < 2){
        termina("Inserire le stringhe");
    }
    for (int i = 1; i<argc; i++){
        lunghezzaStr += strlen(argv[i]);
    }
    char *res = inizializzaStringa(lunghezzaStr + 1);
    int resIndex = 0;
    for (int i = 1; i<argc; i++){
        int j = 0;
        while(argv[i][j] != '\0'){
            res[resIndex] = argv[i][j];
            resIndex++;
            j++;
        }
    }
    res[lunghezzaStr] = '\0';
    printf("%s\n", res);
    free(res);
}