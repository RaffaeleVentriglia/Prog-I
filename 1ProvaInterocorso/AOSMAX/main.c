#include <stdio.h>

int max_val_ind(int*, int, int*, int*);

void ord_sel_max(int*, int);

void scambiare(int*, int*);

int main(){
    int a[] = {1,5,2,4,3};
    int i;
    //CHIAMATA FUNZIONE FONDAMENTALE
    ord_sel_max(a, 5);
    printf("ARRAY ORDINATO\n");
    for(i = 0; i < 5; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}

//IMPARATO A MEMORIA
void scambiare(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//IMPARATO A MEMORIA

//IMPARATO A MEMORIA
int max_val_ind(int* a, int size, int* massimo, int* i_max){
    *massimo = a[0];
    *i_max = 0;
    int i;
    for(i = 0; i < size; i++){
        if(*massimo < a[i]){
            *massimo = a[i];
            *i_max = i;
        }
    }
    return *i_max;
}
//IMPARATO A MEMORIA

//IMPARATO A MEMORIA
void ord_sel_max(int* a, int size){
    int massimo, i_max, i;
    for(i = size-1; i > 0; i--){
        max_val_ind(&a[0], i+1, &massimo, &i_max);
        //passiamo a[0] perchè è l'indirizzo iniziale dell'array
        //passiamo i+1 perchè è il size della porzione dell'array in questione
        //ultimi due sono di output, chiamali come cazzo ti pare
        scambiare(&a[i], &a[i_max]);
    }
}
//IMPARATO A MEMORIA


// #include <stdio.h>

// void scambiare(int*, int*);
// int max_val_ind(int*, int, int*, int*);
// void ord_sel_max(int*, int);

// int main(){
//     int a[] = {1,5,2,4,3};
//     int i;
//     ord_sel_max(a, 5);
//     for(i = 0; i < 5; i++){
//         printf("%d\n", a[i]);
//     }
//     return 0;
// }

// void scambiare(int* a, int* b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int max_val_ind(int* a, int size, int* massimo, int* i_max){
//     *massimo = a[0];
//     *i_max = 0;
//     int i;
//     for(i = 0; i < size; i++){
//         if(*massimo < a[i]){
//             *massimo = a[i];
//             *i_max = i;
//         }
//     }
//     return *i_max;
// }

// void ord_sel_max(int* a, int size){
//     int i, i_max, massimo;
//     for(i = size-1; i > 0; i--){
//         max_val_ind(&a[0], i+1, &massimo, &i_max);
//         scambiare(&a[i], &a[i_max]);
//     }
// }


// #include <stdio.h>

// void scambiare(int *, int *);
// int max_val_ind(int *, int, int *, int *);
// void ord_sel_max(int *, int);

// int main(){
//     int a[] = {1,5,2,4,3};
//     int i;
//     ord_sel_max(a,5);
//     for(i = 0; i < 5; i++){
//         printf("%d\n", a[i]);
//     }
//     return 0;
// }

// void scambiare(int *a, int *b){
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int max_val_ind(int *a, int size, int *massimo, int *i_max){
//     *massimo = a[0];
//     *i_max = 0;
//     int i;
//     for(i = 0; i < size; i++){
//         if(*massimo < a[i]){
//             *massimo = a[i];
//             *i_max = i;
//         }
//     }
//     return *i_max;
// }

// void ord_sel_max(int *a, int size){
//     int massimo, i_max, i;
//     for(i = size-1; i > 0; i--){
//         max_val_ind(&a[0], i+1, &massimo, &i_max);
//         scambiare(&a[i], &a[i_max]);
//     }
// }