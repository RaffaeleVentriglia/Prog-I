#include <stdio.h>

void aoins(int [], int);

int main(){
    int a[] = {1,5,2,4,3};
    int i;
    aoins(a,5);
    printf("ARRAY ORDINATO\n");
    for(i = 0; i < 5; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}

void aoins(int a[], int size){
    int i, j, temporanea;
    for(i = 1; i < size; i++){
    //parte da uno supponendo che il primo elemento sia già ordinato
        temporanea = a[i];
        j = i-1;
        //posto ad i-1 perchè così può confrontarlo con el_da_ins
        while(j >= 0 && temporanea < a[j]){
        //finchè j non arriva a 0 e el_da_ins è minore di a[j]
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temporanea;
    }
}