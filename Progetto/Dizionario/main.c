/************************************************************************************************
*    Dizionario della lingua italiana
*    Si vuole simulare la gestione di un dizionario della lingua italiana. Il dizionario è
*    indicizzato tramite le lettere dell’alfabeto ed ogni parola contiene il significato.
*    Permettere all’utente di:
*    • Inserire una parola, ricercarla nel dizionario e visualizzare il significato
*    • Visualizzare la parola del dizionario contenente più consonanti.
*    Implementare l’algoritmo per la simulazione del dizionario ed effettuare almeno un test
*    per ognuna delle opzioni richieste dall’utente.
************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 427000
//numero approssimativo delle parole presenti in un dizionario di lingua italiana
struct dizionario {
    char *parola;
    char *definizione;
};
typedef struct dizionario Dizionario;

void inserimento(Dizionario[], int);
void cerca(Dizionario[], int);
void consonanti(Dizionario[], int);

int main(){
    int scelta, cont;
    Dizionario elenco[max];
    while(scelta != 4){
        printf("Dizionario di lingua Italiana\n");
        printf("Operazioni consentite:\n");
        printf("1. Inserimento di una parola\n");
        printf("2. Cercare una parola e il corrispettivo significato all'interno del dizionario\n");
        printf("3. Visualizza la parola del dizionario contenete più consonanti\n");
        printf("4. Uscire dal programma di gestione\n");
        printf("Inserire il numero dell'operazione che si desidera compiere: ");
        scanf("%d%*c", &scelta);
        //in base al numero inserito viene eseguita una operazione specifica
        switch (scelta)
        {
        case 1:
            inserimento(elenco,cont);
            cont++;
            break;
        case 2:
            cerca(elenco,cont);
            break;
        case 3:
            consonanti(elenco,cont);
            break;
        case 4:
            printf("USCITA DAL PROGRAMMA IN CORSO . . .\n");
            break;
        default:
            printf("Operazione non consentita\n");
            break;
        }
    }
    return 0;
}

//FUNZIONE PER L'INSERIMENTO DI UNA NUOVA PAROLA
//ALL'INTERNO DEL DIZIONARIO
void inserimento(Dizionario elenco[], int cont){
    //termine = malloc(30*sizeof(char));
    //significato = malloc(100*sizeof(char));
    elenco[cont].parola = malloc(30*sizeof(char));
    if(elenco[cont].parola == NULL){
        printf("Operazione di allocazione dinamica non riuscita\n");
        exit(0);
    }
    elenco[cont].definizione = malloc(150*sizeof(char));
    if(elenco[cont].definizione == NULL){
        printf("Operazione di allocazione dinamica non riuscita\n");
        exit(0);
    }
    printf("FUNZIONE DI INSERIMENTO AVVIATA\n");
    printf("Immettere la parola da inserire nel dizionario: ");
    fgets(elenco[cont].parola,30,stdin);
    elenco[cont].parola[strcspn(elenco[cont].parola,"\n")] = 0;
    printf("Inserire il suo significato: ");
    fgets(elenco[cont].definizione,150,stdin);
    elenco[cont].definizione[strcspn(elenco[cont].definizione,"\n")] = 0;
}

//FUNZIONE PER LA RICERCA DI UNA PAROLA
//ALL'INTERNO DEL DIZIONARIO
void cerca(Dizionario prova[], int cont){
    printf("FUNZIONE DI RICERCA AVVIATA\n");
}

//FUNZIONE PER LA RICERCA DELLA PAROLA
//CHE CONTIENE PIU' CONSONANTI
void consonanti(Dizionario prova[], int cont){
    printf("FUNZIONE DI RICERCA DELLA PAROLE CONTENENTE IL MAGGIOR NUMERO DI CONSONANTI\n");
}