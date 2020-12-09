//contatore di numeri pari in un array (ricorsivo)

#include <stdio.h>

int numPari_ric(int[], int);
int pari(int);

int main(){
    int arr[] = {1,2,4,6,7,9};
    printf("Numeri pari contati: %d\n", numPari_ric(arr, 6));
    return 0;
}

int numPari_ric(int a[], int n){
    if(n == 0){
        return 0;
    } else {
        if(pari(a[0])){
            return 1 + numPari_ric(a+1, n-1);
        } else {
            return numPari_ric(a+1, n-1);
        }
    }
}

int pari(int x){
    if(x%2 == 0){
        return 1;
    } else {
        return 0;
    }
}