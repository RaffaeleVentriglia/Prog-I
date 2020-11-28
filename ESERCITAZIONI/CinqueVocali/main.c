#include <stdio.h>
#include <string.h>

int conta(char []);

int main()
{
    char testo[500];
    printf("Inserire testo: ");
    gets(testo);
    printf("Parole contate: %d", conta(testo));
    return 0;
}

int conta(char testo[]){
    char *token;
    int cont = 0;
    int contavocali = 0;
    token = strtok(testo, " ");
    while(token != NULL){
        for(int i = 0; token[i] != '\0'; i++){
            if(token[i] == 'a' || token[i] == 'e' || token[i] == 'i' || token[i] == 'o' || token[i] == 'u'){
                contavocali++;
            }

        }
        if(contavocali >= 5){
            cont++;
        }
        token = strtok(NULL, " ");
    }
    return cont;
}
