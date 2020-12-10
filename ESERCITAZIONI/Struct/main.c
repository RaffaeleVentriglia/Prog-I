//esercitazioni con le struct

#include <stdio.h>
#include <string.h>

struct studente{
    char *cognome;
    char *nome;
    int eta;
    int libretto[18];
};
typedef struct studente Studente;

struct libro {
    char *titolo;
    int costo;
};
typedef struct libro Libro;

Studente aggiorna_carriera(Studente, int, int);
Studente aggiorna_carrieraP(Studente *, int, int);
int max_cost(Libro [], int);

int main(){
    int i;
    struct data{
        int giorno;
        char mese[10];
        int anno;
    };
    typedef struct data Data;
    Data data_nascita, partenza;

    struct punto_2D {
        int ascissa;
        double ordinata;
    } estr_sin;
    struct punto_2D vertice;
    struct punto_2D *ppunto, mio_punto = {10.3,20.1};
    ppunto = &mio_punto;
    //due metodi di accesso
    (*ppunto).ascissa = 15;
    ppunto -> ordinata = 20;

    struct studente Mario_Rossi;
    Studente Maria_Rossi;

    Mario_Rossi.nome = "Mario";
    Mario_Rossi.cognome = "Rossi";
    Mario_Rossi.eta = 19;
    Mario_Rossi.libretto[0] = 28;
    Mario_Rossi.libretto[1] = 30;

    printf("Questo è il nome: %s\n", Mario_Rossi.nome);
    printf("Questo è il cognome: %s\n", Mario_Rossi.cognome);
    printf("Questa è l'età: %d\n", Mario_Rossi.eta);
    printf("Questo è il risultato del primo esame: %d\n", Mario_Rossi.libretto[0]);

    //struttura all'interno di una struttura
    struct indirizzo {
    struct {
        char* toponimo;
        int n_civico;
    } sede;
    int CAP;
    char* comune;
    char* provincia;
    };
    typedef struct indirizzo Indirizzo;
    Indirizzo Parthenope;
    //accesso ai dati della struttura interna
    Parthenope.sede.toponimo = "Via Acton";
    Parthenope.sede.n_civico = 33;
    Parthenope.CAP = 80133;
    Parthenope.comune = "Napoli";
    Parthenope.provincia = "NA";

    //utilizzo dello strcpy per inserire dati all'interno della struct
    strcpy(data_nascita.mese, "Ottobre");

    //esercitazione con le carte francesi
    typedef enum{picche, fiori, quadri, cuori} Semi_fr;
    struct carta {
        int valore;
        Semi_fr seme;
    };
    typedef struct carta Carta;
    Carta carta_mia, carta_tua;
    carta_mia.valore = 10;
    carta_mia.seme = fiori;
    //vengono assegnati a carta_tua i valori di carta_mia
    carta_tua = carta_mia;
    Carta mazzo_francese[52];
    mazzo_francese[12].valore = 10;
    mazzo_francese[12].seme = cuori;

    Carta mano_poker[2] = {
        {13,cuori},
        {2,picche},
    };
    Carta *pcarta;
    pcarta = &mano_poker[0];

    for(i = 0; i < 2; i++){
        printf("Carta n. %d, Valore: %d, Seme: %d\n", i+1, (pcarta+i)->valore, (pcarta+i)->seme);
    }

    //esercitazione con funzione
    Studente stud = {"rossi", "mario", 19, {25,30,0}};
    stud = aggiorna_carriera(stud, 30, 3);
    aggiorna_carrieraP(&stud, 30, 4);
    printf("Cognome: %s\n Nome: %s\n", stud.cognome, stud.nome);
    for(i = 0; i < 18; i++){
        printf("Esame: %d-esimo, Voto: %d\n", i+1, stud.libretto[i]);
    }

    Studente corso_P1[180];
    //corso_P1[0] = {"Raffaele", "Ventriglia", 19, {18,27,25}};
    //corso_P1[1] = {"Giuseppe", "Fiorillo", 19, {30,30,30}};

    //ESERCIZIO: Trova il libro che costa di più
    Libro libri[10];
    libri[0].titolo = "Linguaggio_C";
    libri[0].costo = 25;
    libri[1].titolo = "Linguaggio_Java";
    libri[1].costo = 35;
    libri[2].titolo = "Linguaggio_Python";
    libri[2].costo = 50;

    printf("Il libro più costoso è: %s\n", libri[max_cost(libri,10)].titolo);

    return 0;
}

int max_cost(Libro scaffale[], int n){
    int i, max, pos;
    max = scaffale[0].costo;
    for(i = 0; i < n; i++){
        if(max < scaffale[i].costo){
            max = scaffale[i].costo;
            pos = i;
        }
    }
    return pos;
}

Studente aggiorna_carriera(Studente stud, int voto, int pos_exam){
    stud.libretto[pos_exam-1] = voto;
    return stud;
}

Studente aggiorna_carrieraP(Studente *stud, int voto, int pos_exam){
    stud->libretto[pos_exam-1] = voto;
    //ALTERNATIVA = (*stud).libretto[pos_exam-1] = voto;
}