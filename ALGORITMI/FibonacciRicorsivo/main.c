#include <stdio.h>

int fibonacci(int);

int main(){
    int n;
    printf("Inserire n: ");
    scanf("%d", &n);
    printf("Fibonacci: %d", fibonacci(n));
    return 0;
}

int fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}