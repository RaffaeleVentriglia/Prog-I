/**********************************************************************************************
*    Gioco del beach volley
*    Si vuole sviluppare un programma per la simulazione del gioco del beach volley fra
*    due giocatori.
*    Il campo da gioco viene considerato come una mappa regolare di dimensioni 10 x 10
*    (da visualizzare per ogni punto).
*    Il campo è formato dal bordo e da una rete. Il giocatore vince se si aggiudica un set e
*    cioè totalizza 20 punti.
*    Il gioco procede nel seguente modo:
*    • In modo casuale si sceglie il giocatore che batte la palla.
*    • La palla viene lanciata nel campo avversario e cade in una cella scelta
*    casualmente, o se la palla cade in una cella vuota il punteggio viene dato al
*    giocatore attaccante. L’attaccante batte la palla.
*    o Se la palla cade in prossimità del giocatore ricevente e cioè nelle
*    celle di distanza 1 intorno al giocatore, la palla viene lanciata nel
*    campo avversario.
*    • La palla lanciata ha il 10% di cadere sulla rete e il 20% di andare fuori. In
*    questo caso il punto va al giocatore ricevente che provvede a battere la
*    palla.
*    • La posizione dei due giocatori viene decisa casualmente ad ogni set.
*    Effettuare almeno 5 test, variando le condizioni del problema.
***********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define max 9
//LUNGHEZZA MASSIMA PER I NOMI
#define nome 30

void printField(char [][10]);
void clearField(char [][10]);
void simulazione(char [][10], char*, char*, int, int);
void battuta1(char [][10], char *, char *, int, int);
void battuta2(char [][10], char *, char *, int, int);
void risposta1(char [][10], char *, char *, int, int);
void risposta2(char [][10], char *, char *, int, int);

int main() {
    srand((unsigned) time(NULL));
    int score1 = 0, score2 = 0;
    char player1[nome];
    char player2[nome];
    char field[10][10] = {
            {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}
    };
    printf("\t**********************************\n");
    printf("\t*       SIMULAZIONE DI UNA       *\n");
    printf("\t*     PARTITA DI BEACH VOLLEY    *\n");
    printf("\t**********************************\n");
    printf("REGOLE FONDAMENTALI:\n");
    printf("1. Vince chi si aggiudica un set\n");
    printf("2. Un set è formato da venti punti\n");
    printf("3. Il battitore iniziale viene assegnato casualmente\n");
    printf("Presentazione del campo di gioco\n");
    printField(&field[0]);
    printf("Inserire il nome del primo giocatore, che giocherà nella metà di sinistra: ");
    fgets(player1, nome, stdin);
    printf("Inserire il nome del secondo giocatore, che giocherà nella metà di destra: ");
    fgets(player2, nome, stdin);

    //FUNZIONE PRINCIPALE PER LA SIMULAZIONE
    /*
    ho deciso di controllare l'intera simulazione della partita attraverso una funzione, in modo tale
    da non appesantire il main e rendere il codice molto più leggibile. A questa funzione "simulazione"
    vengono passati come parametri: il campo, con la dereferenziazione all'indice 0 della matrice; i nomi
    dei due giocatori, unica cosa che viene richiesta all'utente nel main; e come ultimi due parametri gli score
    di entrambi i giocatori che sono inizializzati a 0, e per ogni punto assegnato sarà fatto un controllo su questi.
    */
    simulazione(&field[0], player1, player2, score1, score2);
    return 0;
}
 
//FUNZIONE PER LA STAMPA DEL CAMPO
/*
al richiamo di questa funzione viene stampato il campo in modo tale che l'utente
possa vedere in che posizone si trovi il giocatore che deve difendersi e il pallone.
Ho scelto di non stampare la posizione del giocatore attaccante perchè non ci sarebbe
tanto utile ai fini della simulazione; a noi importa semplicemente sapere se
il pallone si trovi nel quadrato della matrice intorno al giocatore che deve difendere
*/
void printField(char field[10][10]){
    int row, column;
    for(row = 0; row < 10; row++){
        for( column = 0; column < 10; column++){
            printf("%c",field[row][column]);
            if(column == 9){
                printf("\n");
            }
        }
    }
}
//FUNZIONE PER LA PULIZIA DEL CAMPO
/*
grazi e questa funzione possiamo "pulire" il campo da tutti i segni che vengono
fatti sul campo dalla simulazione di una battuta, perchè a noi non serve sapere
all'i-esima battuta dove è andato il pallone, ma semplicemente chi ha fatto punto, e ciò
ci viene indicato dallo score che è stampato dopo ogni punto assegnato.
*/
void clearField(char field[10][10]){
    int row, column;
    for(row = 0; row < 10; row++){
        for(column = 0; column < 10; column++){
            //pulizia dei due campi da gioco
            if((row >= 1 && row <= 8) && (column >= 1 && column <= 3)){
                if(field[row][column] != ' '){
                    field[row][column] = ' ';
                }
            }
            if((row >= 1 && row <= 8) && (column >= 5 && column <= 8)){
                if(field[row][column] != ' '){
                    field[row][column] = ' ';
                }
            }
            //pulizia delle linee di fondo
            if((row == 0 || row == 9) && (column >= 0 && column <= 9)){
                if(field[row][column] != '*'){
                    field[row][column] = '*';
                }
            }
            if((row >= 0 && row <= 8) && (column == 0 || column == 9)){
                if(field[row][column] != '*'){
                    field[row][column] = '*';
                }
            }
            //pulizia della rete
            if(column == 4)
            {
                if(field[row][column] == 'O')
                    field[row][column] = '|';
            }
        }
    }
}

//FUNZIONE PRINCIPALE DELLA SIMULAZIONE
/*
Questa è invece la funzione principale, al cui interno viene deciso, in modo casuale
chi batterà per primo il pallone e viene richiamata la funzione per la battuta del 
giocatore 1, oppure del giocatore in 2 in base al risultato del rand()
*/
void simulazione(char field[10][10], char* player1, char* player2, int score1, int score2){
    int serve;
    int PosPlayer1X, PosPlayer1Y;
    int PosPlayer2X, PosPlayer2Y;
    printf("SCELTA CASUALE DI CHI BATTE PER PRIMO\n");

    //FUNZIONE RAND() LIMITATA TRA 1 E 2 PER LA SCELTA CASUALE DELLA BATTUTA
    serve = rand() % 2 + 1;
 
    //CASO IN CUI DOVESSE BATTERE IL GIOCATORE 1
    if(serve == 1) {
        battuta1(&field[0], player1, player2, score1, score2);
    }
 
    //CASO IN CUI DOVESSE BATTERE IL GIOCATORE 2
    else if(serve == 2) {
        battuta2(&field[0], player1, player2, score1, score2);
    }
}

/*
    FUNZIONI PER LE BATTUTE

Con le prossime due funzioni si effettua la battuta del pallone nel campo avversario in base
a chi dovrà battere, se batte il giocatore 1 allora il pallone dovrà finire nel campo di destra,
se batte il giocatore 2 nel campo di sinistra. Ho inserito alcuni getchar() durante la simulazione
in modo tale da rendersi prima conto di ciò che succede e poi, premendo invio, continuare
nella simulazione della partita. Poichè la traccia richiedeva di calcolare la probabilità della
posizione del pallone dopo la battuta (10% RETE - 20% FUORI - 70% CAMPO), ho pensato di creare una
variabile, al cui interno la funzione rand() inserirà un valore casuale che può avere un valore tra
1 e 100, e attraverso degli if che fanno il controllo sul valore di questa variabile (probability)
verrà scelto se il pallone debba andare nel campo avversario, sulla rete oppure fuori.
    1. Nel caso in cui il pallone colpisca la rete, verrà inserita una O nella posizione
    in cui il pallone è caduto, avviene la stampa del campo e poi viene richiamata la funzione per la pulizia,
    in modo tale da non avere degli elementi di disturbo per la visione della simulazione; dopodichè
    verrà effettuato il controllo sul punteggio di entrambi i giocatori, e così facendo, se uno dei due
    fosse arrivato a 20, allora viene conlusa la simulazione e assegnata la vittoria al giocatore vincitore.
    La battuta viene assegnata al giocatore avversario.
    2. Nel caso in cui il pallone termini fuori, viene semplicemente assegnato il punto al giocatore avversario
    e controllato il punteggio di entrambi per l'assegnazione della vittoria. La battuta viene assegnata al
    giocatore avversario
    3. Nell'ultimo caso, ovvero il caso in cui il pallone finisca nel campo avversario, sarà definita dal rand()
    la posizione X e Y del giocatore avversario in modo tale da conoscere la posizione precisa sul campo; 
    sarà definita casualmente anche la posizione del pallone sul campo, in modo tale
    da poter controllare attraverso degli if - elseif se il pallone cade nel quadrato intorno al giocatore: se
    così dovesse essere allora verrà richiamata la funzione di risposta del giocatore avversario, altrimenti 
    verrà assegnato il punto al giocatore attaccante e gli verrà assegnata di nuovo la battuta.
    Dopo di che verrà eseguito il solito controllo sugli score di entrambi, e l'uscita dalla simulazione 
    nel caso in cui uno dei due avesse vinto il set. 
*/

//BATTUTA DEL GIOCATORE DEL CAMPO DI SINISTRA, PLAYER1
void battuta1(char field[10][10], char* player1, char *player2, int score1, int score2){
    int row, column, probability;
    int PosPlayer1X, PosPlayer1Y;
    int PosPlayer2X, PosPlayer2Y;
    printf("Il pallone viene battuto da %s\n", player1);
    printf("Premere invio per continuare . . .\n");
    getchar();

    //DOVE FINISCE IL PALLONE
    probability = (rand() % (100 + 1 - 1)) + 1;

    //RETE
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        field[column][row] = 'O';
        printField(&field[0]);
        clearField(&field[0]);  //reset dei valori iniziali
        printf("PUNTO ASSEGNATO A %s\n", player2);
        
        
        //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
        score2++;
        printf("SCORE PLAYER 1: %d\n", score1);
        printf("SCORE PLAYER 2: %d\n", score2);
        if(score1 == 20){
            printf("HA VINTO %s\n", player1);
            exit(1);
        } else if(score2 == 20){
            printf("HA VINTO %s\n", player2);
            exit(1);
        }

        printf("Batterà %s\n", player2);
        battuta2(&field[0], player1, player2, score1, score2);
    }

    //FUORI
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player2);
        printf("PUNTO ASSEGNATO A %s\n", player2);
        

        //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
        score2++;
        printf("SCORE PLAYER 1: %d\n", score1);
        printf("SCORE PLAYER 2: %d\n", score2);
        if(score1 == 20){
            printf("HA VINTO %s\n", player1);
            exit(1);
        } else if(score2 == 20){
            printf("HA VINTO %s\n", player2);
            exit(1);
        }

        battuta2(&field[0], player1, player2, score1, score2);
    }

    //CAMPO
    else {
        //DOVE SI TROVA IL PALLONE
        row = (rand() % (3 + 1 - 0)) + 0;
        column = (rand() % (9 + 1 - 5)) + 5;
        //POSIZIONE GIOCATORE AVVERSARIO (2)
        PosPlayer2X = (rand() % (8 + 1 - 5)) + 5;
        PosPlayer2Y = (rand() % (8 + 1 - 1)) + 1;
        field[PosPlayer2Y][PosPlayer2X] = '2';
        field[row][column] = 'X';
        printField(&field[0]);
 
        //TROVA IL QUADRATO INTORNO
        if((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && row == PosPlayer2Y) {
            clearField(&field[0]);
            risposta2(&field[0], player1, player2, score1, score2);
        } else if((row == PosPlayer2Y - 1 || row == PosPlayer2Y + 1) && column == PosPlayer2X){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2, score1, score2);
        } else if((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && (row == PosPlayer2Y - 1 || row == PosPlayer2Y + 1)){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2, score1, score2);
        } else if (column == PosPlayer2X && row == PosPlayer2Y){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2, score1, score2);
        } else {
            clearField(&field[0]);
            printf("PUNTO ASSEGNATO A %s\n", player1);
            

            //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
            score1++;
            printf("SCORE PLAYER 1: %d\n", score1);
            printf("SCORE PLAYER 2: %d\n", score2);
            if(score1 == 20){
                printf("HA VINTO %s\n", player1);
                exit(1);
            } else if(score2 == 20){
                printf("HA VINTO %s\n", player2);
                exit(1);
            }
            
            battuta1(&field[0], player1, player2, score1, score2);
        }
    }
}

//BATTUTA DEL GIOCATORE DEL CAMPO DI SINISTRA, PLAYER2
void battuta2(char field[10][10], char* player1, char *player2, int score1, int score2){
    int row, column;
    int probability;
    int ScorePlayer1 = 0;
    int ScorePlayer2 = 0;
    int PosPlayer1X, PosPlayer1Y;
    int PosPlayer2X, PosPlayer2Y;
    printf("Il pallone viene battuto da %s\n", player2);
    printf("Premere invio per continuare . . .\n");
    getchar();

    //DOVE FINISCE IL PALLONE
    probability = (rand() % (100 + 1 - 1)) + 1;
 
    //RETE
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        field[column][row] = 'O';
        printField(&field[0]);
        clearField(&field[0]);
        printf("PUNTO ASSEGNATO A %s\n", player1);
        

        //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
        score1++;
        printf("SCORE PLAYER 1: %d\n", score1);
        printf("SCORE PLAYER 2: %d\n", score2);
        if(score1 == 20){
            printf("HA VINTO %s\n", player1);
            exit(1);
        } else if(score2 == 20){
            printf("HA VINTO %s\n", player2);
            exit(1);
        }

        printf("Batterà %s\n", player1);
        battuta1(&field[0], player1, player2, score1, score2);
    }
 
    //FUORI
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player1);
        printf("PUNTO ASSEGNATO A %s\n", player1);
        

        //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
        score1++;
        printf("SCORE PLAYER 1: %d\n", score1);
        printf("SCORE PLAYER 2: %d\n", score2);
        if(score1 == 20){
            printf("HA VINTO %s\n", player1);
            exit(1);
        } else if(score2 == 20){
            printf("HA VINTO %s\n", player2);
            exit(1);
        }

        battuta1(&field[0], player1, player2, score1, score2);
    }
 
    //CAMPO
    else {
        //DOVE FINISCE IL PALLONE
        row = (rand() % (9 + 1 - 0)) + 0;
        column = (rand() % (3 + 1 - 0)) + 0;

        //DOVE SI TROVA IL GIOCATORE
        PosPlayer1X = (rand() % (3 + 1 - 1)) + 1;
        PosPlayer1Y = (rand() % (8 + 1 - 1)) + 1;

        //POSIZIONA IL GIOCATORE E IL PALLONE
        field[PosPlayer1Y][PosPlayer1X] = '1';
        field[row][column] = 'X';
        printField(&field[0]);
 
        //TROVA IL QUADRATO INTORNO
        if((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y) {
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else if((row == PosPlayer1Y - 1 || row == PosPlayer1Y + 1) && column == PosPlayer1X){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else if((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y - 1){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else if ((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y + 1){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else if (column == PosPlayer1X && row == PosPlayer1Y){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else {
            printf("PUNTO ASSEGNATO A %s\n", player2);
            

            //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
            score2++;
            printf("SCORE PLAYER 1: %d\n", score1);
            printf("SCORE PLAYER 2: %d\n", score2);
            if(score1 == 20){
                printf("HA VINTO %s\n", player1);
                exit(1);
            } else if(score2 == 20){
                printf("HA VINTO %s\n", player2);
                exit(1);
            }

            clearField(&field[0]);
            battuta2(&field[0], player1, player2, score1, score2);
        }
    }
}

/*
Le prossime due funzioni sono invece essenziali per le risposte alle battute; queste funzioni vengono
richiamate solamente nel caso in cui il giocatore che deve difendersi si trova vicino al pallone, 
o per meglio dire se il pallone cade nel quadrato intorno al giocatore (ricordiamo che tutte le posizioni,
sia dei giocatori che del pallone vengono definite casualmente dalla simulazione). Per il resto, il funzionamento
di queste due funzioni è uguale alle funzioni utilizzate per le battute.
*/

//RISPOSTA DEL GIOCATORE DEL CAMPO DI SINISTRA, PLAYER1
void risposta1(char field[10][10], char* player1, char* player2, int score1, int score2){
    int row, column;
    int probability;
    int ScorePlayer1 = 0;
    int ScorePlayer2 = 0;
    int PosPlayer2X, PosPlayer2Y;

    printf("Il pallone viene colpito da %s\n", player1);
    printf("Premere invio per continuare . . .\n");
    getchar();
 
    //DOVE FINISCE IL PALLONE
    probability = (rand() % (100 + 1 - 1)) + 1;
 
    //RETE
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        field[column][row] = 'O';
        printField(&field[0]);
        clearField(&field[0]);
        printf("PUNTO ASSEGNATO A %s\n", player2);
        

        //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
        score2++;
        printf("SCORE PLAYER 1: %d\n", score1);
        printf("SCORE PLAYER 2: %d\n", score2);
        if(score1 == 20){
            printf("HA VINTO %s\n", player1);
            exit(1);
        } else if(score2 == 20){
            printf("HA VINTO %s\n", player2);
            exit(1);
        }

        printf("Batterà %s\n", player2);
        battuta2(&field[0], player1, player2, score1, score2);
    }
 
    //FUORI
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player2);
        printf("PUNTO ASSEGNATO A %s\n", player2);
        

        //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
        score2++;
        printf("SCORE PLAYER 1: %d\n", score1);
        printf("SCORE PLAYER 2: %d\n", score2);
        if(score1 == 20){
            printf("HA VINTO %s\n", player1);
            exit(1);
        } else if(score2 == 20){
            printf("HA VINTO %s\n", player2);
            exit(1);
        }

        battuta2(&field[0], player1, player2, score1, score2);
    }
 
    //CAMPO
    else {
        row = (rand() % (9 + 1 - 0)) + 0;
        column = (rand() % (9 + 1 - 5)) + 5;
        //POSIZIONE GIOCATORE AVVERSARIO (2)
        PosPlayer2X = (rand() % (8 + 1 - 5)) + 5;
        PosPlayer2Y = (rand() % (8 + 1 - 1)) + 1;

        //POSIZIONA IL GIOCATORE E IL PALLONE
        field[PosPlayer2Y][PosPlayer2X] = '2';
        field[row][column] = 'X';
        printField(&field[0]);
 
        //TROVA IL QUADRATO INTORNO
        if((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && row == PosPlayer2Y) {
            clearField(&field[0]);
            risposta2(&field[0], player1, player2, score1, score2);
        } else if((row == PosPlayer2Y - 1 || row == PosPlayer2Y + 1) && column == PosPlayer2X){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2, score1, score2);
        } else if((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && row == PosPlayer2Y - 1){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2, score1, score2);
        } else if ((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && row == PosPlayer2Y + 1){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2, score1, score2);
        } else if (column == PosPlayer2X && row == PosPlayer2Y){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2, score1, score2);
        } else {
            printf("PUNTO ASSEGNATO A %s\n", player1);
            

            //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
            score1++;
            printf("SCORE PLAYER 1: %d\n", score1);
            printf("SCORE PLAYER 2: %d\n", score2);
            if(score1 == 20){
                printf("HA VINTO %s\n", player1);
                exit(1);
            } else if(score2 == 20){
                printf("HA VINTO %s\n", player2);
                exit(1);
            }

            clearField(&field[0]);
            battuta1(&field[0], player1, player2, score1, score2);
        }
    }
}

//RISPOSTA DEL GIOCATORE DEL CAMPO DI SINISTRA, PLAYER2
void risposta2(char field[10][10], char* player1, char* player2, int score1, int score2){
    int row, column;
    int probability;
    int PosPlayer1X, PosPlayer1Y;
    printf("Il pallone viene colpito da %s\n", player2);
    printf("Premere invio per continuare . . .\n");
    getchar();

    //DOVE CADE IL PALLONE
    probability = (rand() % (100 + 1 - 1)) + 1;

    //RETE
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        printf("PUNTO ASSEGNATO A %s\n", player1);
        

        //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
        score1++;
        printf("SCORE PLAYER 1: %d\n", score1);
        printf("SCORE PLAYER 2: %d\n", score2);
        if(score1 == 20){
            printf("HA VINTO %s\n", player1);
            exit(1);
        } else if(score2 == 20){
            printf("HA VINTO %s\n", player2);
            exit(1);
        }

        field[column][row] = 'O';
        printField(&field[0]);
        clearField(&field[0]);
        printf("Batterà %s\n", player1);
        battuta1(&field[0], player1, player2, score1, score2);
    }

    //FUORI
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player1);
        printf("PUNTO ASSEGNATO A %s\n", player1);
        

        //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
        score1++;
        printf("SCORE PLAYER 1: %d\n", score1);
        printf("SCORE PLAYER 2: %d\n", score2);
        if(score1 == 20){
            printf("HA VINTO %s\n", player1);
            exit(1);
        } else if(score2 == 20){
            printf("HA VINTO %s\n", player2);
            exit(1);
        }

        battuta1(&field[0], player1, player2, score1, score2);
    }

    //CAMPO
    else {
        row = (rand() % (9 + 1 - 0)) + 0;
        column = (rand() % (3 + 1 - 0)) + 0;
        PosPlayer1X = (rand() % (3 + 1 - 1)) + 1;
        PosPlayer1Y = (rand() % (8 + 1 - 1)) + 1;
 
        field[PosPlayer1Y][PosPlayer1X] = '1';
        field[row][column] = 'X';
        printField(&field[0]);
 
        //TROVA IL QUADRATO INTORNO
        if((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y) {
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else if((row == PosPlayer1Y - 1 || row == PosPlayer1Y + 1) && column == PosPlayer1X){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else if((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y - 1){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else if ((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y + 1){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else if (column == PosPlayer1X && row == PosPlayer1Y){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2, score1, score2);
        } else {
            printf("PUNTO ASSEGNATO A %s\n", player2);

            //ESCE SE UNO DEI DUE GIOCATORI HA VINTO
            score2++;
            printf("SCORE PLAYER 1: %d\n", score1);
            printf("SCORE PLAYER 2: %d\n", score2);
            if(score1 == 20){
                printf("HA VINTO %s\n", player1);
                exit(1);
            } else if(score2 == 20){
                printf("HA VINTO %s\n", player2);
                exit(1);
            }

            clearField(&field[0]);
            battuta2(&field[0], player1, player2, score1, score2);
        }
    }
}

/*
Il primo esercizio che mi è stato assegnato è stato quello della simulazione di una
partita di Beach Volley, esercizio che ho deciso di svolgere grazie all'utilizzo di una
funzione principale per la simulazione, invece di utilizzare il main. Dietro questa scelta
c'è un motivo ben preciso, ovvero quello di presentare un main molto più pulito 
rispetto ad uno pieno di codice, e quindi renderlo più leggibile. Quindi troviamo una funzione,
ovvero la funzione simulazione
*/