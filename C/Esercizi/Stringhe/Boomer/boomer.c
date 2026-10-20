#include <stdio.h>
#include <ctype.h>

void maiuscole (char *s){
    int i = 0;
    while (s[i] != '\0'){
        s[i] = toupper(s[i]);
        i++;
    }
}
int main (int argc, char *argv[]){
    for (int i = 1; i<argc; i++){
        maiuscole(argv[i]);
        printf("%s\n", argv[i]);
    }
}