#include <stdio.h>
#define max 100
void fusione(char [], int, char [], int, char []);

int main(){
    char arr1[] = {'a','b','c'};
    char arr2[] = {'d','e','f'};
    char arr3[max];
    int i;
    fusione(arr1, 3, arr2, 3, arr3);
    printf("Risultato della fusione degli array\n");
    for(i = 0; i < 6; i++){
        printf("elemento: %c\n", arr3[i]);
    }
    return 0;
}

void fusione(char arr1[], int n_a, char arr2[], int n_b, char arr3[]){
    int i_a = 0, i_b = 0, i_c = 0;
    while(i_a < n_a && i_b < n_b){
        if(arr1[i_a] < arr2[i_b]){
            arr3[i_c++] = arr1[i_a++];
        } else {
            arr3[i_c++] = arr2[i_b++];
        }
        while(i_a < n_a)
            arr3[i_c++] = arr1[i_a++];
        while(i_b < n_b)
            arr3[i_c++] = arr2[i_b++];
    }
}

/*               COMPLESSITÀ DI TEMPO E SPAZIO
 *      
 *         Complessità di tempo di tipo logaritmica
 *    
*/