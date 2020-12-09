#include <stdio.h>
#define max 100
void el_uguali(char [][100], int, int, char, int []);

int main(){
    char M[][max] = {
        {'a','b','b','b'},
        {'a','b','b','b'}
    };
    int n = 2, m = 4, i;
    int risultato[max];
    char c = 'b';
    el_uguali(M, n, m, c, risultato);
    for(i = 0; i < n; i++){
        printf("%d\n", risultato[i]);
    }
    return 0;
}

void el_uguali(char M[][100], int n, int m, char c, int risultato[]){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(M[i][j] == c){
                risultato[i] += 1;
            }
        }
    }
}