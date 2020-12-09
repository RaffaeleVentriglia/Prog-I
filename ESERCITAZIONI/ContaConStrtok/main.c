//conta parole con strtok

#include <stdio.h>
#include <string.h>

#define max 100

int conta_tutto_strtok(char*);

int main() {
    char testo[max];
    int num_char, num_parole, num_linee;
    printf("Inserire il testo in italiano: ");
    gets(testo);
    printf("Conta tutto con strtok: %d\n", conta_tutto_strtok(testo));
    return 0;
}

int conta_tutto_strtok(char *testo){
    char separatori[] = {' ', '\n', '\t', '\0'};
    char *token = NULL;
    int cont = 0;
    token = strtok(testo, separatori);

    while(token != NULL){
        printf("%s", token);
        getchar();
        if(strncmp((&token[strlen(token) - 3]), "are", 3)){
            ++cont;
        }
        token = strtok(NULL, separatori);
    }
    return cont;
}
