#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]){
    int sommaPari = 0;
    int sommaDispari = 0;
    FILE *pariFile = fopen("pari.txt", "w");
    FILE *dispariFile = fopen("dispari.txt", "w");
    for (int i = 1; i < argc; i++){
        int myN = atoi(argv[i]);
        // atoi restituisce 0 se gli do come input una stringa non valida 
        // quindi una stringa non convertibile in un intero
        // ovviamente se il numero convertito è 0 va bene come intero (e sarebbe pari)
        // quindi per verificare che lo 0 restituito da atoi significhi un errore devo verificare che
        // anche la stringa argv[i] sia diversa da '0'
        if (myN == 0 && *argv[i] != '0'){
            printf("parametro '%s' non valido!!\n", argv[i]);
            continue;
        }
        if (myN % 2 == 0){
            // pari
            sommaPari += myN;
            fprintf(pariFile, "%d\n", myN);

        }else{
            // dispari
            sommaDispari += myN;
            fprintf(dispariFile, "%d\n", myN);
        }
    }
    fclose(pariFile);
    fclose(dispariFile);
    printf("Somma interi pari: %d\n", sommaPari);
    printf("Somma interi dispari: %d\n", sommaDispari);
}