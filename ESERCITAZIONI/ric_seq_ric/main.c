//ricerca sequenziale sviluppata in maniera ricorsiva

#include <stdio.h>

int appartiene(int[], int, int);

int main(){
    int arr[] = {1,2,3,4,5};
    int chiave = 5;
    printf("Appartiene? %d\n", appartiene(arr,5,chiave));
    return 0;
}

int appartiene(int a[], int n, int chiave){
    if(n < 1){
        return 0;
    } else {
        if(a[n-1] == chiave){
            return 1;
        } else {
            return appartiene(a+1, n, chiave);
        }
    }
}