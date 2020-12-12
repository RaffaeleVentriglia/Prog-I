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
    printf("Chiave trovata: %d\n", ric_seq(arr, chiave, size));
    return 0;
}

int ric_seq(int* arr, int chiave, int size){
    int i; 
    for(i = 0; i < size; i++){
        if(chiave == arr[i]){
            return 1;
        } else {
            return 0;
        }
    }
}