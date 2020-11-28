#include <stdio.h>

void concatenazione(int[], int*, int[], int, int[]);
void ord_ins(int[], int);

int main(){
    int a[] = {1,3,5};
    int b[] = {2,4,6};
    int c[6];
    int n = 3, m = 3, i;
    concatenazione(a,&n,b,m,c);
    ord_ins(c, n+m);
    printf("ARRAY ORDINATO\n");
    for(i = 0; i < n+m; i++){
        printf("%d\n", c[i]);
    }
}

void concatenazione(int a[], int *n, int b[], int m, int c[]){
    int i;
    if(*n == m){
        for(i = 0; i < m; i++){
            a[*n] = b[i];
            *n += 1;
        }
    }
}

void ord_ins(int c[], int size){
    int i, j, el_da_ins;
    for(i = 1; i < size; i++){
        el_da_ins = c[i];
        j = i-1;
        while(j >= 0 && el_da_ins < c[i]){
            c[j+1] = c[j];
            j--;
        }
        c[j+1] = el_da_ins;
    }
}