//algoritmo di ordinamento per selezione di massimo

#include <stdio.h>

void scambiare(char *, char *);
void ord_sel_max(char [], int);
void max_val_ind(char [], int, char *, int *);

int main(){
    char array[] = {'d','a','c','t','f','p'};
    int i;
    printf("array non ordinato\n");
    for(i = 0; i < 6; i++){
        printf("elemento: %c\n", array[i]);
    }

    ord_sel_max(array, 6);

    printf("array ordinato\n");
    for(i = 0; i < 6; i++){
        printf("elemento: %c\n", array[i]);
    }

    return 0;
}

void ord_sel_max(char array[], int n){
    int i, ind_max;
    char max_array;
    for (i = n-1; i > 0; i--){
        max_val_ind(&array[0], i+1, &max_array, &ind_max);
        scambiare(&array[i],&array[ind_max]); 
    }
}

void max_val_ind(char array[], int n, char *max_array, int *ind_max){
    int i;
    *max_array = array[0];
    *ind_max = 0;
    for(i = 1; i < n; i++){
        if(array[i] > *max_array){
            *max_array = array[i];
            *ind_max = i;
        }
    }
}

void scambiare(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*               COMPLESSITÀ DI TEMPO E SPAZIO
 *      
 *    la complessità di questo algoritmo è O(n^2) confronti dove n è la dimensione dell'array
 *    quindi ha una complessità quadratica
*/