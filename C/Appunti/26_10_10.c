    int *myF(){
    }
/*
    È una funzione che restituisce un puntatore ad interi, quindi nelle funzioni posso restituire
    puntatori.
    Se un file fallisce la sua apertura (sia in lettura che scrittura) la funzione fopen restituisce NULL,
    mentre se fallisce la sua chiusura fclose restituisce EOF.
    
    fscanf per leggere su un file
    fprintf per stampare su un file

    quando il file finisce e continuo a leggerlo con fscanf mi restituisce EOF (end of file)

    fscanf restituisce un intero, se diverso da 1 significa che c'è stato un errore nella lettura,
    ad esempio sto cercando di leggere un intero che non può subire un cast (ad esempio la stringa "ciao",
    non puoò subire un cast ad intero, mentre la stringa "123" sì),
    Attenzione peroò perchè se incontra un carattere 'speciale' chiamato Whitespace, fscanf lo salta,
    un esempio di carattere Whitespace è \n oppure \t

    se scrivo:
*/
    int n = 200;
    printf("%8d", n);
/*
    scrivo un intero con degli spazi davanti, nel caso di 200 saranno 5 spazi davanti

*/