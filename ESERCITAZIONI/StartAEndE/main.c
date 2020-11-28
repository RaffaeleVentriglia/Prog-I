#include <stdio.h>
#include <string.h>

int conta(char[]);

int main()
{
    char testo[500];
    printf("Inserisci testo: ");
    gets(testo);
    printf("Parole contate: %d\n", conta(testo));
    return 0;
}

int conta(char testo[]){
    int contatore = 0;
    char *token;
    token = strtok(testo, " ");
    int len;
    while(token != NULL){
        len = strlen(token); //lunghezza di ogni parola
        if(token[0] == 'a' && token[len - 1] == 'e'){
            contatore++;
        }
        token = strtok(NULL, " ");
    }
    return contatore;
}
