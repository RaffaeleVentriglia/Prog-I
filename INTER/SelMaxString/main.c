#include <stdio.h>
#include <string.h>

int max_ind(char**, int);
void scambiare(char**, char**);
void ord_Sel_max(char**, int);

int main(){
    char *elenco[] = {
        "Raffaele",
        "Luca",
        "Antonio",
        "Giuseppe"
    };
    ord_Sel_max(elenco, 4);
    int i;
    for(i = 0; i < 4; i++){
        puts(elenco[i]);
    }
    return 0;
}

void scambiare(char** a, char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int max_ind(char** elenco, int size){
    int i_max = 0;
    int i;
    for(i = 0; i < size; i++){
        if(strcmp(elenco[i], elenco[i_max]) > 0){
            i_max = i;
        }
    }
    return i_max;
}

void ord_Sel_max(char** elenco, int size){
    int i;
    for(i = size-1; i>0; i--){
        scambiare(&elenco[i], &elenco[max_ind(&elenco[0], i+1)]);
    }
}