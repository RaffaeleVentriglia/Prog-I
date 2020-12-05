#include <stdio.h>

int somma_ric(int);

int main(){
    int n;
    printf("Inserire n: ");
    scanf("%d", &n);
    printf("%d\n", somma_ric(n));
    return 0;
}

int somma_ric(int n){
    if(n == 1){
        return 1;
    } else {
        return n + somma_ric(n-1);   //somma i primi n numeri naturali
    }
}