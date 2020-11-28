#include <stdio.h>

float mediaArr(int*, int);
void fusione(int*, int, int*, int, int*);
void fusioneMedia(int*, int, int*, int, int*, float*);

int main(){
    int a[3] = {2,4,6};
    int b[3] = {3,5,7};
    int c[6];
    float media;
    int i;
    fusioneMedia(a,3,b,3,c,&media);
    printf("%f\n\n", media);
    for(i = 0; i < 6; i++){
        printf("%d\n", c[i]);
    }
    return 0;
}

float mediaArr(int *a, int n){
    float media = 0;
    int i;
    for(i = 0; i < n; i++){
        media += a[i];
    }
    return media/n;
}

void fusione(int *a, int n_a, int *b, int n_b, int *c){
    int i_a = 0, i_b = 0, i_c = 0;
    while(i_a < n_a && i_b < n_b){
        if(a[i_a] < b[i_b]){
            c[i_c++] = a[i_a++];
        } else {
            c[i_c++] = b[i_b++];
        }
    }
    while(i_a < n_a){
        c[i_c++] = a[i_a++]; 
    }
    while(i_b < n_b){
        c[i_c++] = b[i_b++];
    }
}

void fusioneMedia(int *a, int n_a, int *b, int n_b, int *c, float *media){
    fusione(a, n_a, b, n_b, c);
    *media = mediaArr(c, n_a+n_b);
}

/***********************************************************************************
*Spazio:                                                                           *
*S(n_a+n_b) = 2(n_a+n_b). Posto n = n_a+n_b, S(n) = 2n                             *
*                                                                                  *
*Tempo:                                                                            *
*Operazione dominante -> Confronti                                                 *
*Tc(n_a, n_b) = al più n_a + n_b. Posto n = n_a+n_b, avremo Tc(n) = n. O(n)        *
*                                                                                  *
*Operazione dominante -> +, /                                                      *
*Ta(n_a, n_b) = n_a + n_b + 1. Posto n = n_a+n_b, avremo Ta(n) = n + 1. O(n)       *
************************************************************************************/