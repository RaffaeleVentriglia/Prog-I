#include <stdio.h>

void min_val_ind(int*, int, int*, int*);
void scambiare(int *, int *);
void ord_sel_min(int *, int);

int main(){
    int arr[] = {2,6,3,5,4,9,7,0,8};
    int i;
    ord_sel_min(arr,9);
    for(i = 0; i < 9; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}

void min_val_ind(int *arr, int size, int *minimo, int *i_min){
    int i;
    *minimo = arr[0];
    *i_min = 0;
    for(i = 0; i < size; i++){
        if(*minimo > arr[i]){
            *minimo = arr[i];
            *i_min = i;
        }
    }
}

void ord_sel_min(int *arr, int size){
    int i;
    int minimo, i_min;
    for(i = 0; i < size - 1; i++){
        min_val_ind(&arr[i], size-i, &minimo, &i_min);
        scambiare(&arr[i], &arr[i_min+i]);
    }
}

void scambiare(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}