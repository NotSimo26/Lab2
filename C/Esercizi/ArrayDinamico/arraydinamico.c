#include <stdio.h>
#include <stdlib.h>
void termina (char *msg){
    perror(msg);
    exit(-1);
}
int getIntero (char *str){
    int myN = atoi(str);
    if (myN == 0 && *str != '0'){
        termina("Impossibile convertire in un intero");
    }
    return myN;
}
int* inizializzaArray (int size){
    int *a;
    a = malloc(size * sizeof(int));
    if (a == NULL){
        termina("Malloc fallita");
    }
    return a;
}
void reallocaArray (int *a, int size){
    a = realloc(a, size * sizeof(int));
    if (a == NULL){
        termina("Realloc fallita");
    }
}

int main (int argc, char *argv[]){
    if (argc != 2){
        termina("Errore parametri");
    }
    int myInt = getIntero(argv[1]);
    int aIndex = 0;
    int bIndex = 0;
    int aSomma = 0;
    int bSomma = 0;
    int aCapacita = 10;
    int bCapacita = 10;
    int *a = inizializzaArray(aCapacita);
    int *b = inizializzaArray(bCapacita);

    for (int i = 1; i <= myInt; i++){
        if (i%3 == 0 && i%5 != 0){
            if (aIndex >=  aCapacita){
                aCapacita = aCapacita * 2;
                reallocaArray(a, aCapacita);
            }
            a[aIndex] = i;
            aIndex ++;
            aSomma += i;
        }
        if (i%5 == 0 && i%3 != 0){
            if (bIndex >=  bCapacita){
                bCapacita = bCapacita * 2;
                reallocaArray(b, bCapacita);
            }
            b[bIndex] = i;
            bIndex ++;
            bSomma += i;
        }
    }
    printf("lunghezza a[] = %d,  somma a[] = %d", aIndex, aSomma);
    printf("\nlunghezza b[] = %d,  somma b[] = %d\n", bIndex, bSomma);
    free(a);
    free(b);
}