/*
* Sviluppare  una  function  C  che,  data  come  parametro  di  input  una  stringa
* che rappresenta un  testo  in  italiano,  determina  e  restituisce  come  parametro
* di  output  il numero  delle parole  contenute  nel  testo  che  hanno  almeno 5 vocali.
* Nel  testo  le parole sono separate da un unico spazio.
*/

#include <stdio.h>
#define MAX 100

int voc_cont(char []);

int main() {
    char testo[MAX];
    int i, vocali;
    printf("Inserire un testo italiano di massimo 100 caratteri: ");
    gets(testo);
    vocali = voc_cont(testo);
    printf("Vocali contate: %d", vocali);
    return 0;
}

int voc_cont(char testo[]){
    int i, vocali = 0;
    for(i = 0; testo[i] != '\0'; i++) {
        if (testo[i] == 'a' || testo[i] == 'e' || testo[i] == 'i' || testo[i] == 'o' || testo[i] == 'u') {
            vocali++;
        }
    }
    return vocali;
}
