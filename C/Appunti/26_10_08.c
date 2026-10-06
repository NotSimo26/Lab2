/*
#define è un istruzione del compilatore che serve ad assegnare un valore ad una certa stringa identificatore
ad esempio:

#define test 4

quando nel codice userò test, lo considererà come 4

const keyword per le costanti in c, rende immutabili ad esempio se ho un const char*, quindi una stringa costante,
posso utilizzarla (ad esempio per stamparla) ma non posso modificare i caratteri a suo interno.

per passare un array come parametro in una funzione posso fare in questi 2 modi:

*/
    void myFun(int *array){
    }
    void myFun(int array[]){
    }
/*

tutti e due sono validi, però la prima è ambigua per il programmatore, perchè potrebbe rappresentare un semplice puntatore di
una variabile intera (e non un array), quindi meglio utilizzare la seconda sintassi.
*/
