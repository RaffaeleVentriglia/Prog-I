#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int nc, i, seed, max_sup, min;
    float nc_f;
    printf("Rand Max: %d\n", RAND_MAX);    //valore massimo che può essere estratto
    printf("Rand: %d\n", rand());          //valore casuale

    //printf("Inserire il seed: ");
    //scanf("%d", &seed);

    printf("Inserire l'intervallo superiore: ");
    scanf("%d", &max_sup);
    printf("Inserire l'intervallo inferiore: ");
    scanf("%d", &min);
    //srand((unsigned int) time(0));       //genera un seed casuale per ogni secondo che passa
    srand(time(NULL));                     //seconda versione
    for(i = 1; i <= 10; i++){
        nc = min + rand() % (max_sup + 1 - min);
        printf("Numero pseudocasuale: %d\n", nc);
    }

    for(i = 1; i <= 5; i++){
        //in questo modo stampiamo numeri casuali con la virgola
        //utilizzando il minimo e il massimo inseriti prima
        nc_f = min + (max_sup - min) * (float)rand()/(float)RAND_MAX;
        printf("Numeri casuali con la virgola: %f\n", nc_f);
    }
    return 0;
}