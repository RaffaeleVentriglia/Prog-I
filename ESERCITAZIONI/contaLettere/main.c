#include <stdio.h>

int contaLettere(char[]);

int main() {
    char testo[] = "CaNe123 CD";
    int lettere;
    lettere = contaLettere(testo);
    printf("Lettere contate: %d", lettere);
    return 0;
}

int contaLettere(char testo[]){
    int i, lettere = 0;
    for(i = 0; testo[i] != '\0'; i++){
        if((testo[i] >= 'a' && testo[i] <= 'z') || (testo[i] >= 'A' && testo[i] <= 'Z')){
            lettere++;
        }
    }
    return lettere;
}
