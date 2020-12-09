//lunghezza di una stringa in maniera ricorsiva

#include <stdio.h>

int strlen_ric(char*);

int main(){
    char testo[100];
    printf("Inserire il testo: ");
    gets(testo);
    printf("Lunghezza: %d\n", strlen_ric(testo));
}

int strlen_ric(char* testo){
    if(*testo == '\0'){
        return 0;
    } else {
        return 1 + strlen_ric(testo+1);
    }
}