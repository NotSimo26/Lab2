/*
    Aritmetica dei puntatori: posso sommare un intero m ad un mio puntatore p, il risultato ovviamente
    è un altro puntatotore con indirizzo n + m dove n è l'indirizzo di p.

    Di fatto quando vado a fare a[0] è uguale ad accedere al valore del puntatore stesso, ovvero *a
    mentre con a[1] sarebbe come fare *(a+1) e a[n] = *(a+n).

    per leggere una stringa è buona norma mettere un limite ai caratteri da leggere,
    per farlo basta scrivere così:
*/
    void fun(){
        char *s = malloc(10 * sizeof(char));
        scanf("%9s", s);
    }
/*
    in questo modo io leggo solamente 9 caratteri della mia stringa allocata con 10 byte
    (ovviamente 1 byte è riservato all'ultimo '\0').

*/