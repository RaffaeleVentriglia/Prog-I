//algoritmo di Fibonacci (ricorsivo)

#include <stdio.h>

int fibonacci(int);
double fib_ric_PD(int);
double fib[100];

int main(){
    int n;
    for(int i = 0; i < 100; i++){
        fib[i] = 0.0;
    }
    printf("Inserire n: ");
    scanf("%d", &n);
    printf("Fibonacci: %d\n", fibonacci(n));
    printf("Fibonacci: %lf\n", fib_ric_PD(n));
    return 0;
}

int fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

double fib_ric_PD(int n){
    if(n <= 1){
        return (double)n;
    }
    if(fib[n] != 0.0){
        return fib[n];
    } else {
        fib[n] = fib_ric_PD(n-1) + fib_ric_PD(n-2);
        return fib[n];
    }
}