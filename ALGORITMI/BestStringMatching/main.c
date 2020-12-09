//algoritmo di Best String Matching

#include <stdio.h>
#include <string.h>

int migliore(char *, char *);
int punteggio(char *, char *, int);

int main(){
    char testo[100];
    char chiave[20];
    printf("Inserire testo: ");
    gets(testo);
    printf("Inserire chiave: ");
    gets(chiave);
    printf("Il BestMatching si trova all'indice: %d", migliore(testo, chiave));
    return 0;
}

int migliore(char *testo, char *chiave){
    int i;
    int n, m, punt, BestPunt = 0, indice = 0;
    n = strlen(testo);
    m = strlen(chiave);
    for(i = 0; i < n-m; i++){
        punt = punteggio(chiave, &testo + i, m);
        if(punt > BestPunt){
            punt = BestPunt;
            indice = i;
        }
    }
    return indice;
}

/*                COMPLESSITÀ DI TEMPO E SPAZIO
 *      
 *    n*(m - n + 1) confronti al più tra i caratteri delle due stringhe
 *
*/

int punteggio(char *a, char *b, int n){
    int i, uguali = 0;
    for(i = 0; i < n; i++){
        if(a[i] == b[i])
            uguali++;
    }
    return uguali;
}

/*               COMPLESSITÀ DI TEMPO E SPAZIO
 *      
 *        n confronti tra i caratteri delle due stringhe
 *
*/