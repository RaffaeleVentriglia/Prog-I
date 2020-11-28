#include <stdio.h>

float esercitazione1(float [], int, float [], int);
float media(float [], int);

int main(){
    float a[] = {1,2,3,4,5,6};
    float b[] = {1,2,3,4,5,6};
    esercitazione1(a,6,b,6);
    return 0;
}

float esercitazione1(float a[], int n_a, float b[], int n_b){
    float media_a = 0;
    float media_b = 0;
    float somma_a = 0;
    float somma_b = 0;
    int i;

    media_a = media(a, n_a);
    media_b = media(b, n_b);

    for(i = 0; i < n_a; i++){
        if(a[i] > media_a){
            a[i] = media_a;
        }
    }

    for(i = 0; i < n_b; i++){
        if(b[i] > media_b){
            b[i] = media_b;
        }
    }

    for(i = 0; i < n_a; i++){
        printf("%f\t", a[i]);
    }
    printf("\n");
    for(i = 0; i < n_b; i++){
        printf("%f\t", b[i]);
    }
    return 0;
}

float media(float arr[], int size){
    int i;
    float somma = 0, media = 0;
    for(i = 0; i < size; i++){
        somma += arr[i];
    }
    media = somma/size;
    return media;
}


/*

Tc(n_a,n_b) = n_a + n_b

Tc(n) = n dove il costo di n=n_a+n_b


COMPLESSITÀ ARITMETICA
Ta(n_a,n_b) = n_a+1+n_b+1

Ta(n) = n+2 dove il costo di n=n_a+n_b

Operazioni dominanti: + - / *

*/