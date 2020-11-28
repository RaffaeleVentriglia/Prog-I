/*Sviluppare una function C che, dato come parametro di input una stringa che
  rappresenta un testo in italiano, determina e restituisce come parametri di
  output la parola di lunghezza massima contenuta nel testo e la posizione di inizio
  della parola nella stringa. Nel testo le parole sono separate da un unico spazio.*/


#include <stdio.h>
#include <string.h>

void parolaPiuLunga(char*, char*, int*);

int main()
{
    char testo[] = "raffaele studia troppissimissimo";
    char parola[100];
    int indirizzo;
    parolaPiuLunga(testo, parola, &indirizzo);
    printf("%s\n", parola);
    printf("%d\n", indirizzo);
    return 0;
}

void parolaPiuLunga(char *testo, char *parolaLunga, int *indirizzo)
{
    char *token;
    int max = 0, sum = -1;
    int len;
    token = strtok(testo, " ");

    while(token != NULL){
        len = strlen(token);
        sum += len+1;
        if(len > max){
            max = len;
            strcpy(parolaLunga, token);
            *indirizzo = sum-len;
        }
        token = strtok(NULL, " ");
    }
}
