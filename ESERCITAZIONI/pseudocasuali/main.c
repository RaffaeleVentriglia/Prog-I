#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void movimento_casella();
void generaStringaCasuale();
void lancioDado();

int main(){
    int n, i, j;
    float nc_f;
    printf("%d\n",RAND_MAX);
    printf("%d\n", 1+rand()%6);
    printf("%d\n", 1+rand()%6);
    printf("%d\n", 1+rand()%6);
    printf("%d\n", rand()%11);
    //generare numeri casuali di tipo float
    nc_f = (float)rand() / (float)RAND_MAX;

    lancioDado();
    generaStringaCasuale();
    return 0;
}

void movimento_casella(){
    //movimento casuale di una pedina all'interno di una scacchiera
    int prob;
    prob = 1 + rand()%99;
    if(prob >= 1 && prob <= 49){
        //movimento a nord
    } else if(prob >= 50 && prob <= 79){
        //movimento a est
    } else if(prob >= 80 && prob < 89){
        //movimento a sud
    } else if(prob >= 90 && prob <= 100){
        //movimento a est
    }
}

void lancioDado(){
    //simulazione lancio di un dado n volte
    int n, i;
    printf("Lancio di un dado\n");
    printf("Inserire il numero di volte per cui tirare il dado: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Lancio n.%d: %d\n", i+1, 1+rand()%6);
    }
}

void generaStringaCasuale(){
    //generazione 20 stringhe di 5 caratteri
    int i, j, n_volte;
    char alfabeto[] = {'a','b','c','d','e','f','g','h','i','l','m'};
    char stringa_cas[] = "12345";
    int lun = 11;
    int nc;
    printf("Inserire il numero di volte: ");
    scanf("%d", &n_volte);
    srand(time(NULL));
    for(i = 0; i < n_volte; i++){
        for(j = 0; j < 5; j++){
            nc = rand()%lun;
            stringa_cas[j] = alfabeto[nc];
        }
        printf("Stringa: %s\n", stringa_cas);
    }
}