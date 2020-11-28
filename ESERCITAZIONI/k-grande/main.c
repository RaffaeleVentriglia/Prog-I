#include <stdio.h>
#define max 100

int main() {
    int arr[max];
    int size;
    int k;
    int i;
    printf("Inserire il size dell'array: ");
    scanf("%d", &size);
    for(i = 0; i < size; i++){
        printf("Inserire il %d° valore dell'array: ", i+1);
        scanf("%d", &arr[i]);
    }
    return 0;
}