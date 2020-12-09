//somma righe e colonne di un array bidimensionale
//e inserisce i risultati all'interno di due array 
//sc (somma colonne) e sr (somma righe)

#include <stdio.h>

void esercitazione(int [][3], size_t, size_t, int [], int []);

int main(){
    int a[2][3] = {
        {2,3,5},
        {2,8,9}
    };
    int righe[2];
    int colonne[3];
    int i;
    esercitazione(a, 2, 3, righe, colonne);
    for(i = 0; i < 2; i++){
        printf("%d\n", righe[i]);
    }
    printf("\n");
    for(i = 0; i < 3; i++){
        printf("%d\n", colonne[i]);
    }
    return 0;
}

void esercitazione(int a[][3], size_t righe, size_t colonne, int sr[], int sc[]){
    size_t i, j;
    for(i = 0; i < righe; i++){
        sr[i] = 0;
        for(j = 0; j < colonne; j++){
            sr[i] += a[i][j];
        }
    }
    for(j = 0; j < colonne; j++){
        sc[j] = 0;
        for(i = 0; i < righe; i++){
            sc[j] += a[i][j];
        }
    }
}

/****************************************************************
*Spazio:                                                        *
*T(n, m) = 2(n*m) quindi posto che n = n*m, allora T(n) = 2n    *
*                                                               *
*Tempo:                                                         *
*T(a) = 2(n*m)  quindi posto che n = n*m, allora T(a) = 2n      *
*****************************************************************/
