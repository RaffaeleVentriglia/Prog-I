//algoritmo di ordinamento per inserimento sulle stringhe

#include <stdio.h>
#include <string.h>

void funzione(char**, int);

int main(){
    int i;
    char* elenco[] = {
        "Raffaele",
        "Giuseppe",
        "Antonio", 
        "Luca"
    };
    funzione(elenco, 4);
    printf("Array ordinato\n");
    for(i = 0; i < 4; i++){
        printf("%s\n", elenco[i]);
    }
    return 0;
}

void funzione(char** elenco, int size){
    int i, j;
    char *el_da_ins;
    for(i = 0; i < size; i++){
        el_da_ins = elenco[i];
        j = i-1;
        while(j >= 0 && strcmp(el_da_ins, elenco[j]) < 0){
            elenco[j+1] = elenco[j];
            j--;
        }
        elenco[j+1] = el_da_ins;
    }
}