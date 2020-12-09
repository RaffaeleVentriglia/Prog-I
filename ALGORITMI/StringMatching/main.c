//algoritmo di string matching

#include <stdio.h>
#include <string.h>

int conta(char [], char []);

int main()
{
    char testo[100];
    char chiave[50];
    int occorrenze = 0;
    printf("Inserisci il testo: ");
    gets(testo);
    printf("Inserisci la chiave: ");
    gets(chiave);
    occorrenze = conta(testo, chiave);
    printf("Occorrenze: %d\n", occorrenze);
    return 0;
}

int conta(char testo[], char chiave[]){
    int i;
    int contatore = 0;
    int n = strlen(testo);
    int m = strlen(chiave);
    for(i = 0; i < n-m; i++){
        if(strncmp(chiave, &testo[i], m) == 0)
            contatore++;
    }
    return contatore;
}

/*                    COMPLESSITÀ DI TEMPO E SPAZIO
 *      
 *        n*(n - m + 1) confronti al più tra i caratteri delle due stringhe
 *
*/