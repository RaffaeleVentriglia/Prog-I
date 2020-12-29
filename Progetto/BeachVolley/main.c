#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define max 9
#define nome 30
 
void printField(char [][10]);
void clearField(char [][10]);
void simulazione(char [][10], char*, char*, int);
void battuta1(char [][10], char *, char *);
void battuta2(char [][10], char *, char *);
void risposta1(char [][10], char *, char *);
void risposta2(char [][10], char *, char *);
 
int main() {
    srand((unsigned) time(NULL));
    int result = 0;
    char giocatore1[nome];
    char giocatore2[nome];
    char campo[10][10] = {
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
    printField(&campo[0]);
    printf("Inserire il nome del primo giocatore, che giocherà nella metà di sinistra: ");
    fgets(giocatore1, nome, stdin);
    printf("Inserire il nome del secondo giocatore, che giocherà nella metà di destra: ");
    fgets(giocatore2, nome, stdin);
    simulazione(&campo[0], giocatore1, giocatore2, result);
    return 0;
}
 
//FUNZIONE PER LA STAMPA DEL CAMPO
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
 
void clearField(char field[10][10]){
    int row, column;
    printf("PULIZIA DEL CAMPO . . .\n");
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
            if(column == 4)
            {
                if(field[row][column] == 'O')
                    field[row][column] = '|';
            }
        }
    }
    sleep(2);
}
 
 
//FUNZIONE PRINCIPALE DELLA SIMULAZIONE
void simulazione(char field[10][10], char* player1, char* player2, int result){
    int serve;
    int ScorePlayer1 = 0, ScorePlayer2 = 0;
    int PosPlayer1X, PosPlayer1Y;
    int PosPlayer2X, PosPlayer2Y;
    printf("SCELTA CASUALE DI CHI BATTE PER PRIMO\n");
 
    serve = rand() % 2 + 1;
    printf("DEBUG SERVE --> [%d]\n", serve);
 
    //CASO IN CUI DOVESSE BATTERE IL GIOCATORE 1
    if(serve == 1) {
        battuta1(&field[0], player1, player2);
    }
 
    //CASO IN CUI DOVESSE BATTERE IL GIOCATORE 2
    else if(serve == 2) {
        battuta2(&field[0], player1, player2);
    }
}
 
 
 
//FUNZIONI PER LE BATTUTE
void battuta1(char field[10][10], char* player1, char *player2){
    int row, column, probability;
    int ScorePlayer1 = 0, ScorePlayer2 = 0;
    int PosPlayer1X, PosPlayer1Y;
    int PosPlayer2X, PosPlayer2Y;
    printf("Il pallone viene battuto da %s\n", player1);
    sleep(1);
    //Controllo della probabilità
    //per sapere dove finirà il pallone
    probability = (rand() % (100 + 1 - 1)) + 1;
    printf("DEBUG  --> [%d]\n", probability);
 
    //caso in cui il pallone termini sulla rete
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        field[column][row] = 'O';
        printField(&field[0]);
        clearField(&field[0]);  //reset dei valori iniziali
        printf("PUNTO ASSEGNATO A %s\n", player2);
        printf("Batterà %s\n", player2);
        battuta2(&field[0], player1, player2);
    }
    //caso in cui il pallone termini fuori
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player2);
        printf("PUNTO ASSEGNATO A %s\n", player2);
        battuta2(&field[0], player1, player2);
    }
        //caso in cui il pallone cade nel campo
    else {
        row = (rand() % (3 + 1 - 0)) + 0;
        column = (rand() % (9 + 1 - 5)) + 5;
        //posizione giocatore avversario (2)
        PosPlayer2X = (rand() % (8 + 1 - 5)) + 5;
        PosPlayer2Y = (rand() % (8 + 1 - 1)) + 1;
        printf("DEBUG --> PosPlayer2X : [%d]\n", PosPlayer2X);
        printf("DEBUG --> PosPlayer2Y : [%d]\n", PosPlayer2Y);
        field[PosPlayer2Y][PosPlayer2X] = '2';
        field[row][column] = 'X';
        printField(&field[0]);
 
        //TROVA IL QUADRATO INTORNO
        if((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && row == PosPlayer2Y) {
            clearField(&field[0]);
            risposta2(&field[0], player1, player2);
        } else if((row == PosPlayer2Y - 1 || row == PosPlayer2Y + 1) && column == PosPlayer2X){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2);
        } else if((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && (row == PosPlayer2Y - 1 || row == PosPlayer2Y + 1)){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2);
        } else if (column == PosPlayer2X && row == PosPlayer2Y){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2);
        } else {
            clearField(&field[0]);
            printf("PUNTO ASSEGNATO A %s\n", player1);
            battuta1(&field[0], player1, player2);
        }
    }
}
 
void battuta2(char field[10][10], char* player1, char *player2){
    int row, column;
    int probability;
    int ScorePlayer1 = 0;
    int ScorePlayer2 = 0;
    int PosPlayer1X, PosPlayer1Y;
    int PosPlayer2X, PosPlayer2Y;
    printf("Il pallone viene battuto da %s\n", player2);
    sleep(1);
    //Controllo della probabilità
    //per sapere dove finirà il pallone
    probability = (rand() % (100 + 1 - 1)) + 1;
    printf("DEBUG  -->  [%d]\n", probability);
 
    //RETE
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        field[column][row] = 'O';
        printField(&field[0]);
        clearField(&field[0]);
        printf("PUNTO ASSEGNATO A %s\n", player1);
        printf("Batterà %s\n", player1);
        battuta1(&field[0], player1, player2);
    }
 
    //FUORI
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player1);
        printf("PUNTO ASSEGNATO A %s\n", player1);
        battuta1(&field[0], player1, player2);
    }
 
    //CAMPO
    else {
        //dove finisce il pallone
        row = (rand() % (9 + 1 - 0)) + 0;
        column = (rand() % (3 + 1 - 0)) + 0;
        //dove si trova il giocatore
        PosPlayer1X = (rand() % (3 + 1 - 1)) + 1;
        PosPlayer1Y = (rand() % (8 + 1 - 1)) + 1;
        //DEBUG
        printf("DEBUG --> row : [%d]\n", row);
        printf("DEBUG --> column : [%d]\n", column);
        printf("DEBUG --> PosPlayer1X : [%d]\n", PosPlayer1X);
        printf("DEBUG --> PosPlayer1Y : [%d]\n", PosPlayer1Y);
        field[PosPlayer1Y][PosPlayer1X] = '1';
        field[row][column] = 'X';
        printField(&field[0]);
 
        //TROVA IL QUADRATO INTORNO
        if((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y) {
            clearField(&field[0]);
            risposta1(&field[0], player1, player2);
        } else if((row == PosPlayer1Y - 1 || row == PosPlayer1Y + 1) && column == PosPlayer1X){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2);
        } else if((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y - 1){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2);
        } else if ((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y + 1){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2);
        } else if (column == PosPlayer1X && row == PosPlayer1Y){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2);
        } else {
            printf("PUNTO ASSEGNATO A %s\n", player2);
            clearField(&field[0]);
            battuta2(&field[0], player1, player2);
        }
    }
}
 
 
 
//FUNZIONI PER LE RISPOSTE
void risposta1(char field[10][10], char* player1, char* player2){
    int row, column;
    int probability;
    int ScorePlayer1 = 0;
    int ScorePlayer2 = 0;
    int PosPlayer2X, PosPlayer2Y;
 
    printf("Il pallone viene colpito da %s\n", player1);
    sleep(1);
 
    //DOVE FINISCE IL PALLONE?
    probability = (rand() % (100 + 1 - 1)) + 1;
    printf("DEBUG  -->  [%d]\n", probability);
 
    //RETE
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        field[column][row] = 'O';
        printField(&field[0]);
        clearField(&field[0]);  //reset della posizione al valore iniziale
        printf("PUNTO ASSEGNATO A %s\n", player2);
        printf("Batterà %s\n", player2);
        battuta2(&field[0], player1, player2);
    }
 
    //FUORI
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player2);
        printf("PUNTO ASSEGNATO A %s\n", player2);
        battuta2(&field[0], player1, player2);
    }
 
    //CAMPO
    else {
        row = (rand() % (9 + 1 - 0)) + 0;
        column = (rand() % (9 + 1 - 5)) + 5;
        //posizione giocatore avversario (2)
        PosPlayer2X = (rand() % (8 + 1 - 5)) + 5;
        PosPlayer2Y = (rand() % (8 + 1 - 1)) + 1;
 
        field[PosPlayer2Y][PosPlayer2X] = '2';
        field[row][column] = 'X';
        printField(&field[0]);
 
        //TROVA IL QUADRATO INTORNO
        if((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && row == PosPlayer2Y) {
            clearField(&field[0]);
            risposta2(&field[0], player1, player2);
        } else if((row == PosPlayer2Y - 1 || row == PosPlayer2Y + 1) && column == PosPlayer2X){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2);
        } else if((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && row == PosPlayer2Y - 1){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2);
        } else if ((column == PosPlayer2X - 1 || column == PosPlayer2X + 1) && row == PosPlayer2Y + 1){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2);
        } else if (column == PosPlayer2X && row == PosPlayer2Y){
            clearField(&field[0]);
            risposta2(&field[0], player1, player2);
        } else {
            printf("PUNTO ASSEGNATO A %s\n", player1);
            clearField(&field[0]);
            battuta1(&field[0], player1, player2);
        }
    }
}
 
void risposta2(char field[10][10], char* player1, char* player2){
    int row, column;
    int probability;
    int PosPlayer1X, PosPlayer1Y;
    printf("Il pallone viene colpito da %s\n", player2);
    sleep(1);
    //Controllo della probabilità
    //per sapere dove finirà il pallone
    probability = (rand() % (100 + 1 - 1)) + 1;
    printf("DEBUG  --> [%d]\n", probability);
    //RETE
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        printf("PUNTO ASSEGNATO A %s\n", player1);
        field[column][row] = 'O';
        printField(&field[0]);
        clearField(&field[0]);
        printf("Batterà %s\n", player1);
        battuta1(&field[0], player1, player2);
    }
    //FUORI
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player1);
        printf("PUNTO ASSEGNATO A %s\n", player1);
        battuta1(&field[0], player1, player2);
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
            risposta1(&field[0], player1, player2);
        } else if((row == PosPlayer1Y - 1 || row == PosPlayer1Y + 1) && column == PosPlayer1X){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2);
        } else if((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y - 1){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2);
        } else if ((column == PosPlayer1X - 1 || column == PosPlayer1X + 1) && row == PosPlayer1Y + 1){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2);
        } else if (column == PosPlayer1X && row == PosPlayer1Y){
            clearField(&field[0]);
            risposta1(&field[0], player1, player2);
        } else {
            printf("PUNTO ASSEGNATO A %s\n", player2);
            clearField(&field[0]);
            battuta2(&field[0], player1, player2);
        }
    }
}