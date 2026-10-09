#include <stdio.h>
#include <stdlib.h>

void termina (char *msg){
    perror(msg);
    exit(-1);
}
int confrontas(const char *s, const char *q){
    int i = 0;
    // mi scorro tutta s
    while (s[i] != '\0'){
        // se q è terminata oppure il il carattere s[i] è maggiore
        // allora s è maggiore
        if ((q[i] == '\0') || (s[i] > q[i])){
            return 1;
        }
        // se il carattere q[i] è maggiore allora q è maggiore
        if (q[i] > s[i]){
            return -1;
        }
        i++;
    }
    // se ho finito di scorremi s non ho ancora restituito (quindi per ora sono uguali)
    // verifico che anche q sia terminata, se non lo è allora è maggiore
    if (q[i] != '\0'){ 
        return -1;
    }
    // se anche q è terminata allora sono uguali
    return 0;
}
int main (int argc, char *argv[]){
    int indexMinimo = 1;
    for (int i = 2; i < argc; i++){
        int resConfronto = confrontas(argv[indexMinimo], argv[i]);
        if (resConfronto == 1){
            indexMinimo = i;
        }
    }
    printf("%s\n", argv[indexMinimo]);
    // se ho 2 o piu stringhe uguali, considero la prima come minore
    // ad esempio se ho argv[1] = "aaa" argv[2] = "aaa", il minore sarà argv[1]
    printf("Argv[%d] è lessicograficamente minore\n", indexMinimo);
}