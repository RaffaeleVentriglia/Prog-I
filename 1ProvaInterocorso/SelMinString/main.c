#include <stdio.h>
#include <string.h>

int min_ind(char**, int);
void scambiare(char**, char**);
void ord_Sel_min(char**, int);

int main(){
    char *elenco[4] = {
        "Raffaele",
        "Luca",
        "Antonio",
        "Giuseppe"
    };
    ord_Sel_min(elenco, 4);
    int i;
    for(i = 0; i < 4; i++){
        printf("%s\n", elenco[i]);
    }
    return 0;
}

int min_ind(char** elenco, int size){
    int i;
    int i_min = 0;   //variabile fondamentale da passare alla fine
    for(i = 1; i < size; i++){
        if(strcmp(elenco[i], elenco[i_min]) < 0){
            i_min = i;    //operazione dominante
        }
    }
    return i_min;
}

void scambiare(char** a, char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void ord_Sel_min(char** elenco, int size){
    int i;
    for(i = 0; i < size-1; i++){       
        scambiare(&elenco[i], &elenco[min_ind(&elenco[i], size-i) + i]);
    }
}

/*
Spazio: S(n) = n -> O(n)                  (operazioni in place)
Tempo: Ta(n) = n -> O(n)                  assegnazioni
       Tc(n) = (n(n+1))/2 -> O(n^2)       confronti
*/