#include <stdio.h>

void fusione(int[], int, int[], int, int[]);
void fusionewhile(int [], int, int [], int, int []);

int main(){
    int a[4] = {1,4,7,9};
    int b[4] = {2,5,8,10};
    int c[8];
    fusionewhile(a, 4, b, 4, c);
    for(int i = 0; i < 8; i++){
        printf("%d\t", c[i]);
    }
    return 0;
}

//void fusione(int a[], int size1, int b[], int size2, int c[]){
//    int i_a = 0;
//    int i_b = 0;
//    int i_c = 0;
//    while(i_a < size1 && i_b < size2){
//        if(a[i_a] < b[i_b]){
//            c[i_c++] = a[i_a++];
//        } else {
//            c[i_c++] = b[i_b++];
//        }
//    }
//    while(i_a < size1)
//        c[i_c++] = a[i_c++];
//    while(i_b < size2)
//        c[i_c++] = b[i_b++];
//}


void fusionewhile(int a[], int size1, int b[], int size2, int c[]){
    int i_a = 0;
    int i_b = 0; 
    int i_c = 0;
    while(i_a < size1 && i_b < size2){
        if(a[i_a] < b[i_b]){
            c[i_c++] = a[i_a++];
        } else {
            c[i_c++] = b[i_b];
        }
    }
    while(i_a < size1){
        c[i_c++] = a[i_a++];
    }
    while(i_b < size2){
        c[i_c++] = b[i_b++];
    }
}