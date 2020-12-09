#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("%d\n",RAND_MAX);
    printf("%d\n", 1+rand()%6);
    printf("%d\n", 1+rand()%6);
    printf("%d\n", 1+rand()%6);
    printf("%d\n", rand()%11);
    return 0;
}