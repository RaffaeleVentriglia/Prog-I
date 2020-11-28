#include <stdio.h>
#include <string.h>

int conta(char []);

int main()
{
    char testo[500];
    printf("Inserire testo: ");
    gets(testo);
    printf("Parole contate: %d\n", conta(testo));
    return 0;
}

int conta(char testo[]){
    char *token;
    token = strtok(testo, " ");
    int conta = 0;
    while(token != NULL){
        if (strncmp((&token[strlen(token) - 3]), "are", 3) == 0){   //toglie a strlen(token) la lunghezza di are = 3
            conta++;
        }
        token = strtok(NULL, " ");
    }
    return conta;
}
