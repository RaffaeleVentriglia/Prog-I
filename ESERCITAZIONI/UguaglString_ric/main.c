//uguaglianza di due stringhe (ricorsivo)

#include <stdio.h>

int uguaglianza(char*, char*);

int main(){
    char a[] = "Raffaele";
    char b[] = "Raffaele";
    printf("Uguali? %d\n", uguaglianza(a,b));
    return 0;
}

int uguaglianza(char* a, char* b){
    if(*a == '\0' && *b != '\0'){
        return 0;
    }
    if(*a == '\0' && *b == '\0'){
        return 1;
    } else {
        if(*a == *b){
            return uguaglianza(a+1,b+1);
        } else {
            return 0;
        }
    }
}