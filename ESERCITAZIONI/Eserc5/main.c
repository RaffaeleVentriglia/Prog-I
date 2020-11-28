/*Sviluppare una function C che, dati come parametri di input un array 2D di int, 
il numero delle righe, il numero delle colonne e un int p e un int q 
(con int p minore di int q), determina  e restituisce 
come parametro di output la somma degli elementi che
hanno gli indici di riga e di colonna compresi tra int p e int q.*/


#include <stdio.h>

int funzione(int[][100], int, int, int, int);

int main(){
    int matrix[100][100] = {
        {1,2,3,4,5},
        {1,2,3,4,5},
        {5,6,7,8,9},
        {5,6,7,8,9}
    };
    int p, q, somma = 0;
    printf("Inserire p: ");
    scanf("%d", &p);
    printf("Inserire q: ");
    scanf("%d", &q);
    
    printf("La somma: %d", funzione(matrix, 4, 5, p, q));
    return 0;
}

int funzione(int matrix[][100], int row, int col, int p, int q){
    int i, j, somma = 0;
    for(i = 0; i < row; i++){
        for(j = 0; j < col; j++){
            if((p < i && i < q) && (p < j && j < q)){
                somma += matrix[i][j];
            }
        }
    }
    return somma;
}

/*
Spazio: Costante perchè opera in place
Tempo 
*/