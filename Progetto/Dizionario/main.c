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
int Piuconsonanti(Dizionario[], int);
int ricercaBinaria(char*, Dizionario[], int);
int min_ind(Dizionario*, int);
void scambiare(Dizionario*, Dizionario*);
void ord_Sel_min(Dizionario*, int);
int consonanti(char*);

int main(){
    int scelta = 0, cont = 0, indMax;
    Dizionario elenco[max];
    printf("*********************************\n");
    printf("*                               *\n");
    printf("*        DIZIONARIO DI          *\n");
    printf("*       LINGUA ITALIANA         *\n");
    printf("*                               *\n");
    printf("*********************************\n");
    while(scelta != 4){
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
            indMax = Piuconsonanti(elenco,cont);
            printf("La parola con più consonanti è: %s\n", elenco[indMax].parola);
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
    elenco[cont].parola = (char *)malloc(30*sizeof(char));
    if(elenco[cont].parola == NULL){
        printf("Operazione di allocazione dinamica non riuscita\n");
        exit(0);
    }
    elenco[cont].definizione = (char *)malloc(150*sizeof(char));
    if(elenco[cont].definizione == NULL){
        printf("Operazione di allocazione dinamica non riuscita\n");
        exit(0);
    }
    printf("FUNZIONE DI INSERIMENTO AVVIATA . . .\n");
    printf("Immettere la parola da inserire nel dizionario: ");
    fgets(elenco[cont].parola,30,stdin);
    elenco[cont].parola[strcspn(elenco[cont].parola,"\n")] = 0;
    printf("Inserire il suo significato: ");
    fgets(elenco[cont].definizione,150,stdin);
    elenco[cont].definizione[strcspn(elenco[cont].definizione,"\n")] = 0;
    //funzione di ordinamento
    if(cont > 0){
        ord_Sel_min(elenco,cont);
    }
}

//FUNZIONE PER LA RICERCA DI UNA PAROLA
//ALL'INTERNO DEL DIZIONARIO
void cerca(Dizionario elenco[], int cont){
    int ris;
    char ricerca[30];
    printf("FUNZIONE DI RICERCA AVVIATA . . .\n");
    printf("Inserire la parola da ricercare: ");
    fgets(ricerca,30,stdin);
    ricerca[strcspn(ricerca,"\n")] = 0;
    ris = ricercaBinaria(ricerca,elenco,cont);
    if(ris >= 0){
        printf("%s: %s\n", elenco[ris].parola, elenco[ris].definizione);
    } else {
        printf("Parola non trovata\n");
    }
}

//FUNZIONE PER LA RICERCA DELLA PAROLA
//CHE CONTIENE PIU' CONSONANTI
int Piuconsonanti(Dizionario elenco[], int cont){
    int i, contatore = 0, contMax = 0, indMax = 0;
    printf("FUNZIONE DI RICERCA DELLA PAROLE CONTENENTE IL MAGGIOR NUMERO DI CONSONANTI . . .\n");
    for(i = 0; i < cont; i++){
        contatore = consonanti(elenco[i].parola);
        if(contatore > contMax){
            contMax = contatore;
            indMax = i;
        }
    }
    return indMax;
}

//FUNZIONI PER L'ORDINAMENTO PER SELEZIONE DI MINIMO
int min_ind(Dizionario* elenco, int size){
    int i;
    int i_min = 0;   //variabile fondamentale da passare alla fine
    for(i = 1; i <= size; i++){
        if(strcmp(elenco[i].parola, elenco[i_min].parola) < 0){
            i_min = i;    //operazione dominante
        }
    }
    return i_min;
}

void scambiare(Dizionario* a, Dizionario* b){
    Dizionario temp = *a;
    *a = *b;
    *b = temp;
}

void ord_Sel_min(Dizionario* elenco, int size){
    int i;
    for(i = 0; i < size; i++){
        scambiare(&elenco[i], &elenco[min_ind(&elenco[i], size-i) + i]);
    }
}
//FINE FUNZIONI PER L'ORDINAMENTO

//FUNZIONE PER LA RICERCA BINARIA RICORSIVA
int ricercaBinaria(char* id, Dizionario elenco[], int n)
{
    int mediano;
    if(n < 1)
    {
        return -1;
    }
    mediano = (n-1)/2;
    if(strcmp(id, elenco[mediano].parola) == 0){
        return mediano;
    }
    else if(strcmp(id, elenco[mediano].parola) < 0)
        return ricercaBinaria(id, elenco, mediano);
    else
        return mediano + 1 + ricercaBinaria(id, elenco+mediano+1, n-mediano-1);
}
//FINE FUNZIONE DI RICERCA BINARIA RICORSIVA

//INIZIO FUNZIONE DI RICERCA SEQUENZIALE
int consonanti(char *prova){
    int cont = 0, i;
    char consonanti[] = {'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z'};
    
    for(i = 0; prova[i] != '\0'; i++){   
        for(int j = 0; j < 21; j++){
            if(prova[i] == consonanti[j])
                cont++;
        }
    }
    return cont;
}
//FINE FUNZIONE DI RICERCA SEQUENZIALE