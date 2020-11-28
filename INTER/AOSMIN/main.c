#include <stdio.h>

void scambiare(int *, int *);
int min_val_ind(int *, int, int *, int *);
void ord_sel_min(int *, int);

int main(){
    int a[] = {1,5,2,4,3};
    int i;
    ord_sel_min(a,5);
    for(i = 0; i < 5; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}

//IMPARATO A MEMORIA
void scambiare(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//IMPARATO A MEMORIA

//IMPARATO A MEMORIA
int min_val_ind(int *a, int size, int *minimo, int *i_min){
    *minimo = a[0];
    *i_min = 0;
    int i;
    for(i = 0; i < size; i++){
        if(*minimo > a[i]){
            *minimo = a[i];
            *i_min = i;
        }
    }
    return *i_min;
}
//IMPARATO A MEMORIA

//IMPARATO A MEMORIA
void ord_sel_min(int *a, int size){
    int minimo, i_min, i;
    for(i = 0; i < size-1; i++){
        min_val_ind(&a[i], size-i, &minimo, &i_min);
        //passiamo a[i] perchè parte dal primo posto dell'array
        //passiamo size-i perchè passiamo la porzione
        //ultimi due sono output, chiamali come cazzo ti pare
        scambiare(&a[i], &a[i_min+i]);
        //passiamo come secondo parametro i_min+i per lo spiazzamento
    }
}
//IMPARATO A MEMORIA