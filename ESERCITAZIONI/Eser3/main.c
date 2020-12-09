//conta le vocali nella parola che ne contiene di più

#include <stdio.h>
#include <string.h>

int e_vocale(char);
int esercizio(char[], int);

int main(){
    char testo[] = {"Raffaele studia tanto"};
    int max;
    printf("Massimo: %d",esercizio(testo, 22));
    return 0;
}

int esercizio(char testo[], int n){
    char *token;
    int i, som = 0;
    int max = 0;
    token = strtok(testo, " ");
    while(token != NULL){
        int len = strlen(token);
        for(i = 0; i < len; i++){
            if(e_vocale(token[i]) == 1){
                som++;
            }
            if(som > max){
                max = som;
            }
        }
        som = 0;
        token = strtok(NULL, " ");
    }
    return max;
}

int e_vocale(char car){
    if(car == 'a' || car == 'e' || car == 'i' || car == 'o' || car == 'u'){
        return 1;
    } else {
        return 0;
    }
}