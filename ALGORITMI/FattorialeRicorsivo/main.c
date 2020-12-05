#include <stdio.h>

int fattoriale_ric(int);

int main(){
    int n;
    printf("Inserire n: ");
    scanf("%d", &n);
    printf("%d\n", fattoriale_ric(n));
    return 0;
}

int fattoriale_ric(int n){
    if(n == 1){
        return 1;
    } else {
        return n * fattoriale_ric(n-1);
    }
}