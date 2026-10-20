#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
/*
Buffer = zona di memoria contigua

C non ha metodi di conversione fra tipo classici.
Da intero a stringa => printf (con %d)
"snprintf()" fa la stessa cosa, ma non trasmette la stringa nel terminale, la salva in memoria.
snprinftf() ha bisogno di un buffer già pronto

Invece, "asprintf" fa la stessa cosa, ma non ha bisogno diun buffer iniziale
*/
void f(){
    int a=0;
    char *b;  //buffer gia pronto  
    // ...
    // dovrei fare la malloc e tutto quanto per inizializzarlo...
    //... 
    //stampo la stringa + l'intero a fatto a stringa, salvo tutto in b
    snprintf(b,sizeof(b),"aaoaooaoa %d\n", a);
    //oppure
    asprintf(&b,"aaoaooaoa %d\n", a);
}
// la free poi la fai in entrambi i cas


/*
    TYPEDEF:
    la keyword typedef serve a definire un tipo, o dare un sinonimo 
    ad un tipo esistente, ad esempio:
*/
    typedef int mioTipoIntero;
    typedef int* mioTipoPuntatoreIntero;
/*
    ho definito 2 sinonimi del tipo intero e di puntatore ad intero.
    
    STUCT:
    La keyword struct definisce tipi composti da più campi,
    ad esempio:
*/
    struct terna {
        int a;
        int b;
        double c;
    };
//  dopo aver definito la mia struct posso usarla in questo modo:
    struct terna x,y,z;
/*
    posso utilizzare anche typedef e struct messe insieme per avere 
    un codice più pulito:
*/
    typedef struct terna miaTerna;
/*
    Questo significa che ho definito un tipo miaTerna che è una struct terna,
    quindi posso usarla cosi:
*/ 
    miaTerna x,y,z;

//  posso definire terna direttamente dentro il typedef:
    typedef struct terna {
        int a;
        int b;
        double c;
    } tuaTerna; // Il tipo tuaTerna è uguale al tipo miaTerna.
/*

    Le struct normalmente vengono passate per valore nelle funzioni,
    pero' possono anche essere passate per riferimento:
*/
    //     const rende la terna t immutabile, posso leggere ma non modificare
    void stampaTerna (const miaTerna t){ // la terna t è passata per valore
        printf("(%d, %d, %f", t.a, t.b, t.c);
    }
    void scambiaAB (miaTerna *t){ // la terna è passata per riferimento (puntatore)
        int temp = (*t).a; // accedo al valore effettivo di t con *, e poi ad a
        (*t).a = (*t).b;
        (*t).b = temp; // apposto di usare (*t).b potrei utilizzare t->b, è semanticamente uguale
    }

    //Posso costruire degli array di struct   
    void f(){
        int dim = 10;
        miaTerna *terne;
        terne = malloc(dim * sizeof(miaTerna)); // alloco un array di tipo miaTerna con 10 elementi
    }


/*
    Posso avere anche dei puntatori dentro la mia struct,
    attenzione però, pecheè se devo liberare memoria con un oggetto
    di tipo struct con un puntatore dentro, devo prima fare la free di tutti i
    discendenti, ed infine la free della struct, altrimenti avrò un memory leak.
    Per questo motivo posso crearmi una funzione distruttore della stuct, che fa 
    tutti gli eventuali free(), un po' come si fa nella oop.
*/