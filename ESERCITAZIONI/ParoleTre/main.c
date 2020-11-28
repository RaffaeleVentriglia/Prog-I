//contare le parole di tre lettere

#include <stdio.h>
#include <string.h>

int conta(char []);

int main()
{
    char testo[500];
    printf("Inserire testo: ");
    gets(testo);
    printf("Parole contate che contengono tre lettere: %d\n", conta(testo));
    return 0;
}

int conta(char testo[]){
    char *token;
    int conta = 0;
    token = strtok(testo, " ");
    while(token != NULL){
        if(strlen(token) == 3)
            conta++;
        token = strtok(NULL, " "); //continua a scorrere da dove stava
    }
    return conta;
}
