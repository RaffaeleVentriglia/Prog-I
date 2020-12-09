#include <stdio.h>

void ordinamento(int*, int);

int main(){
    int array[] = {3,2,1,7,5,6,9,8};
    int i;
    printf("Array non ordinato\n");
    for(i = 0; i < 8; i++){
        printf("%d\t", array[i]);
    }
    ordinamento(array, 8);
    printf("\nArray ordinato\n");
    for(i = 0; i < 8; i++){
        printf("%d\t", array[i]);
    }
    printf("\n");
    return 0;
}

void ordinamento(int* array, int size){
    int i, j, temp;
    for(i = 1; i < size; i++){
        temp = array[i];
        j = i - 1;
        while(j >= 0 && temp < array[j]){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}