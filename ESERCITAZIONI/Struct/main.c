#include <stdio.h>
/*
struct data{
        int giorno;
        char mese[10];
        int anno;
    };
typedef struct data Data;
*/

struct studente{
    char *cognome;
    char *nome;
    int eta;
    int libretto[18];
};
typedef struct studente Studente;

int main(){
    /*struct punto_2D {
        int ascissa;
        double ordinata;
    } vertice, estr_sin;
    Data data_nascita, partenza;*/
    //struct punto_2D vertice, estr_sin;

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
    return 0;

    //TODO: Finisci la lezione sulle struct
}
