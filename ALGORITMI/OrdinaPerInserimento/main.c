//algoritmo di ordinamento per inserimento

#include <stdio.h>

void ord_inser(char [], int);

int main() {
    char a[] = {'z', 'm', 'a', 'd', 'b'};
    int i, n = 5;
    
    printf("Array non ordinato\n");
    for(i = 0; i < n; i++){
        printf("Il %d° elemento è: %c\n", i+1, a[i]);
    }
    
    ord_inser(a, n);
    
    printf("Array ordinato\n");
    for(i = 0; i < n; i++){
        printf("Il %d° elemento è: %c\n", i+1, a[i]);
    }
    return 0;
}

void ord_inser(char a[], int n){
    int i, j;
    char el_da_ins;
    for(i = 1; i < n; i++){
        el_da_ins = a[i];
        j = i - 1;
        while(j >= 0 && el_da_ins < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = el_da_ins;
    }
}

/*               COMPLESSITÀ DI TEMPO E SPAZIO
 *      
 *    al più O(n^2) confronti dove n è la dimensione dell'array
 *    quindi ha una complessità quadratica
*/