/*
Se utilizzo una funzione prima di dichiararla (o dichiarare almeno la firma/prototipo) il compilatore implicitamente 
la intepreta come una funzione che prende un intero e restituisce un intero (implicit declaration).

Quando il compilatore "legge" #include <...> va a cercare il file ... per utilizzare le funzioni contenute in esso
ovviamente ci sono dei path predefiniti dove va a controllare così che non ho bisogno di dover scrivere 
il path esatto per ogni libreria (ad esempio con #include <stdio.h>).

Gli array in c non memorizzano la propria lunghezza (sono solo puntatori)
quindi non esiste nessun metodo lenght (come in js).
Nel c le stringhe sono array di char, ad esempio: char *s = "ao ao";
dentro un array di char sono memorizzati i codici ascii dei vari caratteri,
l'ultimo carattere dell'array DEVE SEMPRE essere \0 (codice ascii 0) per dire al compilatore 
che la stringa finisce, se non lo metto quando poi vado a leggere la stringa, leggero' anche 
out of bounds dell'array fino a quando non trovo il carattere \0
quindi in un array di dimensione n posso scriverci una stringa di dim n-1.

argc è un intero che rappresenta il numero di parametri (compreso il nome dell'eseguibile)
argv è un array di stringhe, ogni stringa è un parametro (compreso il nome dell'eseguibile)
Esempio:

mioexe 4 ciao

argc sarà = 3
argv sarà:
argv[0] un puntatore ad un array di char (stringa) che contiene "[c] [i] [a] [o] [\0]"

In c le virgolette singole '' si usano per rappresentare un char, mentre le
virgolette doppie "" si usano per rappresentare una stringa.

le stringhe dichiarate in questo modo:
*/
void test (){
    char *myStr = "mia stringa";
}
char *myStr = "mia stringa";
/*
vanno bene ma sono immutabili, nel senso che non posso cambiare i caratteri,
per poterlo fare devo usare strdupe:
*/
void test (){
    char *myStr = strdup("mia stringa");
    free(myStr);
}
/*
free(myStr) ovviamente dealloca la mia stringa (visto che è un array)

*/ 
