#include <stdio.h>

void max_val_ind(int*, int, int*, int*);
void ord_sel_max(int*, int);
void scambiare(int*, int*);

int main(){
    int arr[] = {2,6,3,5,4,9,7,0,8};
    int i;
    ord_sel_max(arr,9);
    for(i = 0; i < 9; i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}

void max_val_ind(int *arr, int size, int *massimo, int * i_max){
    *i_max = 0;
    *massimo = arr[0];
    int i;
    for(i = 0; i < size; i++){
        if(*massimo < arr[i]){
            *massimo = arr[i];
            *i_max = i;
        }
    }
}

void ord_sel_max(int *arr, int size){
    int i;
    int massimo, i_max;
    for(i = size - 1; i > 0; i--){
        max_val_ind(&arr[0], i+1, &massimo, &i_max);
        scambiare(&arr[i], &arr[i_max]);
    }
}

void scambiare(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}