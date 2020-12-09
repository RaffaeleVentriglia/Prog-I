#include <stdio.h>

int ric_seq(int*, int, int);

int main(){
    int size = 0;
    int arr[size];
    int chiave;
    int stato;
    int i;
    printf("Inserire size: ");
    scanf("%d", &size);
    for(i = 0; i < size; i++){
        printf("Inserire elemento: ");
        scanf("%d", &arr[i]);
    }
    printf("Inserire chiave: ");
    scanf("%d", &chiave);
    stato = ric_seq(arr, chiave, size);
    printf("Chiave trovata: %d\n", stato);
    return 0;
}

int ric_seq(int* arr, int chiave, int size){
    int i; 
    int stato;
    for(i = 0; i < size; i++){
        if(chiave == arr[i]){
            stato = 1;
        } else {
            stato = 0;
        }
    }
    return stato;
}