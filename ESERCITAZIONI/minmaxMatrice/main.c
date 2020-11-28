#include <stdio.h>

void funzione(int*, int, int, int*, int*);
void scrivi(int*, int, int);

int main(){
    int matrice[100][100];
    int row, col, i, j;
    int min = 0, max = 0;
    printf("Inserire numero righe: ");
    scanf("%d", &row);
    printf("Inserire numero colonne: ");
    scanf("%d", &col);
    scrivi(&matrice[0][0], row, col);
    funzione(&matrice[0][0], row, col, &min, &max);
    printf("Valore massimo: %d\n", max);
    printf("Valore minimo: %d\n", min);
    return 0;
}

void funzione(int* matrice, int row, int col, int* min, int* max){
    *min = *max = *(matrice + col * 0 + 0);
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if(*(matrice + col * i+j) > *max){
                *max = *(matrice + col * i+j);
            } else if(*(matrice + col * i+j) < *min){
                *min = *(matrice + col * i+j);
            }
        }
    }
}

void scrivi(int* matrice, int row, int col){
    int i, j;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            printf("Inserire [%d][%d]: ", i, j);
            scanf("%d", matrice + col * i+j);
        }
    }
}

/* #include <stdio.h>

void leggi_da_tastiera_a2D(int*, int, int);
void min_max(int*, int, int, int*, int*);

int main(int argc, const char * argv[])
{
    int M[100][100], min, max;
    int row, col;

    printf("Inserire il numero di righe: ");
    scanf("%d", &row);
    printf("Inserire il numero di colonne: ");
    scanf("%d", &col);
    leggi_da_tastiera_a2D(&M[0][0], row, col);

    min_max(&M[0][0], row, col, &min, &max);
    printf("\nMinimo: %d\nMassimo: %d\n", min, max);

    return 0;
}

void leggi_da_tastiera_a2D(int* M, int row, int col)
{
    int i, j;
    for(i = 0; i < row; ++i)
    {
        for(j = 0; j < col; ++j)
        {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", M + col * i + j);
        }
    }
}

void min_max(int* M, int row, int col, int* min, int* max)
{
    int i, j;
    *min = *max = *(M + col * 0 + 0);

    for(i = 0; i < row; ++i)
    {
        for(j = 0; j < col; ++j)
        {
            if(*(M + col * i + j) > *max)
            {
                *max = *(M + col * i + j);
            }
            else if(*(M + col * i + j) < *min)
                *min = *(M + col * i + j);
        }
    }
} */