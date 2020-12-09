    //conta le parole presenti in una stringa
    
    #include <stdio.h>
    #define max 1000
    
    int contaParole(char[]);

    int main() {
        int parole;
        char testo[max];
        printf("Inserire del testo: ");
        gets(testo);
        parole = contaParole(testo);
        printf("Parole inserite: %d", parole);
        return 0;
    }

    int contaParole(char testo[]){
        int i, parole = 0, stato = 0;
        for(i = 0; testo[i] != '\0'; i++){
            //controlla se si trova in uno spazio
            if(testo[i] == ' '){
                stato = 0;
            }
            //altrimenti vuol dire che non si trova in uno spazio quindi si trova all'interno di una parola
            //e quindi deve incrementare la variabile parole
            else if(stato == 0){
                stato = 1;
                parole++;
            }
        }
        return parole;
    }