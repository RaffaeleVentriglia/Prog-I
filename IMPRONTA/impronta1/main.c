/*
 * Sviluppare una function C che, dati come parametri di input un array di int
 * e il suo size, determina  e  restituisce  come  parametro  di  output
 * il  secondo più  grande elemento dell’array
 */

#include <stdio.h>

int secondo(int [], int);

int main() {
    int max2, size, i;
    int arr[100]; // = {100,23,24,999};
    printf("Inserire size: ");
    scanf("%d", &size);
    for(i = 0; i < size; i++){
        printf("Inserire valore: ");
        scanf("%d", &arr[i]);
    }
    max2 = secondo(arr, size);
    printf("Secondo elemento: %d\n", max2);
    return 0;
}

int secondo(int arr[], int size){
    int max2 = 0, max = 0, i;
    for(i = 0; i < size; i++){
        if(arr[i] > max) {
            max2 = max;
            max = arr[i];
        }
        else if(arr[i] > max2 && arr[i] < max){
            max2 = arr[i];
        }
    }
    return max2;
}