//algoritmo di ordinamento per selezione di minimo

#include <stdio.h>

void ord_sel_min(char [], int);
void min_val_ind(char [], int, char *, int *);
void scambiare_c(char *, char *);
int min_val(char [], int);

int main() {
    char a[] = {'z', 'm', 'a', 'd', 'b'};
    int i, n = 5;
    printf("Array non ordinato\n");
    for(i = 0; i < n; i++){
        printf("Il %d° elemento è: %c\n", i+1, a[i]);
    }
    ord_sel_min(a, n);
    printf("Array ordinato\n");
    for(i = 0; i < n; i++){
        printf("Il %d° elemento è: %c\n", i+1, a[i]);
    }
    return 0;
}

void ord_sel_min(char a[], int n){
    int i, indice_min;
    char min_array;
    for(i = 0; i < n - 1; i++){
        min_val_ind(&a[i], n - i, &min_array, &indice_min);
        scambiare_c(&a[i], &a[indice_min + i]);

        //SOLUZIONE COMPATTA
        //scambiare_c(&a[i], &a[min_val(&a[i], n-i) + i]);
    }
}

/* int min_val(char a[], int n){
    int i, i_min = 0;
    char minimo = a[0];
    for(i = 1; i < n; i++){
        if(a[i] < minimo){
            minimo = a[i];
            i_min = i;
        }
    }
    return i_min;
} */

void min_val_ind(char a[], int n, char *min_array, int *i_min){
    int i;
    *min_array = a[0];
    *i_min = 0;

    for(i = 1; i < n; i++){
        if(a[i] < *min_array){
            *min_array = a[i];
            *i_min = i;
        }
    }
}

void scambiare_c(char *a, char *b){
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