#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define nome 30
#define max 9

void stampaCampo(char [][10]);
void simulazione(char [][10], char*, char*, int);
void beat1(char [][10], char *, char *);
void beat2(char [][10], char *, char *);


int main() {
    srand(time(NULL));
    int result = 0;
    char giocatore1[nome];
    char giocatore2[nome];
    char campo[10][10] = {
            {'*', '*', '*', '*', '|', '*', '*', '*', '*', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', '*'},
            {'*', '*', '*', '*', '|', '*', '*', '*', '*', '*'}
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
    stampaCampo(&campo[0]);
    printf("Inserire il nome del primo giocatore, che giocherà nella metà di sinistra: ");
    scanf("%s", giocatore1);
    printf("Inserire il nome del secondo giocatore, che giocherà nella metà di destra: ");
    scanf("%s", giocatore2);
    simulazione(&campo[0],giocatore1,giocatore2, result);
    return 0;
}

//FUNZIONE PER LA STAMPA DEL CAMPO
void stampaCampo(char field[10][10]){
    int row, column;
    for(row = 0; row < 10; row++){
        for( column = 0; column < 10; column++){
            printf("%c ",field[row][column]);
            if(column == 9){
                printf("\n");
            }
        }
    }
}



//FUNZIONE PRINCIPALE DELLA SIMULAZIONE
void simulazione(char field[10][10], char* player1, char* player2, int result){
    int battuta;
    int row, column;
    int probability;
    printf("SCELTA CASUALE DI CHI BATTE PER PRIMO\n");
    battuta = 1 + rand() % 2;
    
    //BATTE IL GIOCATORE 1
    if(battuta == 1){
        printf("Il pallone viene battuto da %s\n", player1);
        sleep(2);
        //Controllo della probabilità
        //per sapere dove finirà il pallone
        probability = 1 + rand() % 100;
        //caso in cui il pallone termini sulla rete
        if(probability >= 0 && probability <= 10){
            row = 4;
            column = 0 + rand() % 9;
            printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
            field[column][row] = 'O';
            stampaCampo(&field[0]);
            field[column][row] = '|';  //reset della posizione al valore iniziale
            stampaCampo(&field[0]);
            printf("Batterà %s\n", player2);
        }
        //caso in cui il pallone termini fuori
        else if(probability >= 11 && probability <= 31){
            printf("Pallone terminato fuori, batterà %s\n", player2);
        }
        //caso in cui il pallone cade nel campo
        else {
            row = (rand() % (max + 1 - 0)) + 0;
            column = (rand() % (max +1 - 5)) + 5;
            //printf("DEBUG --> row : [%d]\n", row);        --> DEBUG
            //printf("DEBUG --> column: [%d]\n", column);   --> DEBUG
            //  TO DO: controlla se il pallone si trova nel quadrato intorno
            //         al giocatore avversario, se si allora batte dall'altro lato,
            //         altrimenti è punto.

            //reset della posizione al valore iniziale
            if(field[row][column] == '*'){
                field[row][column] = 'X';
                stampaCampo(&field[0]);
                field[row][column] = '*';
            } else {
                field[row][column] = 'X';
                stampaCampo(&field[0]);
                field[row][column] = ' ';
            }
            //stampaCampo(&field[0]);  -->  DEBUG
        }
    } 

    //BATTE IL GIOCATORE 2
    else {
        printf("Il pallone viene battuto da %s\n", player2);
        sleep(2);
        //Controllo della probabilità
        //per sapere dove finirà il pallone
        probability = 1 + rand() % 100;
        //caso in cui il pallone termini sulla rete
        if(probability >= 0 && probability <= 10){
            row = 4;
            column = 0 + rand() % 9;
            printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
            field[column][row] = 'O';
            stampaCampo(&field[0]);
            field[column][row] = '|';  //reset della posizione al valore iniziale
            stampaCampo(&field[0]);
            printf("Batterà %s\n", player1);
        }
        //caso in cui il pallone termini fuori
        else if(probability >= 11 && probability <= 31){
            printf("Pallone terminato fuori, batterà %s\n", player1);
        }
        //caso in cui il pallone cade nel campo
        else {
            row = (rand() % (3 + 1 - 0)) + 0;
            column = (rand() % (max +1 - 0)) + 0;
            //printf("DEBUG --> row : [%d]\n", row);       --> DEBUG
            //printf("DEBUG --> column: [%d]\n", column);  --> DEBUG
            //  TO DO: controlla se il pallone si trova nel quadrato intorno
            //         al giocatore avversario, se si allora batte dall'altro lato,
            //         altrimenti è punto.
    
            //reset della posizione al valore iniziale
            if(field[column][row] == '*'){
                field[column][row] = 'X';
                stampaCampo(&field[0]);
                field[column][row] = '*';
            } else {
                field[column][row] = 'X';
                stampaCampo(&field[0]);
                field[column][row] = ' ';
            }
            //stampaCampo(&field[0]);  -->  DEBUG
        }
    }
}


/*
//CASO IN CUI DOVESSE BATTERE IL GIOCATORE 1
void beat1(char field[10][10], char* player1, char* player2){
    int row, column;
    int probability;
    printf("Il pallone viene battuto da %s\n", player1);
    //sleep(2);
    //Controllo della probabilità
    //per sapere dove finirà il pallone
    probability = 1 + rand() % 100;
    //caso in cui il pallone termini sulla rete
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        field[column][row] = 'O';
        stampaCampo(&field[0]);
        field[column][row] = '|';  //reset della posizione al valore iniziale
        stampaCampo(&field[0]);
        printf("Batterà %s\n", player2);
    }
    //caso in cui il pallone termini fuori
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player2);
    }
    //caso in cui il pallone cade nel campo
    else {
        //row = 0 + rand() % max;
        //column = 5 + rand() % max;
        row = (rand() % (max + 1 - 0)) + 0;
        column = (rand() % (max +1 - 5)) + 5;
        printf("DEBUG --> row : [%d]\n", row);
        printf("DEBUG --> column: [%d]\n", column);
        //  TO DO: controlla se il pallone si trova nel quadrato intorno
        //         al giocatore avversario, se si allora batte dall'altro lato,
        //         altrimenti è punto.

        //reset della posizione al valore iniziale
        if(field[row][column] == '*'){
            field[row][column] = 'X';
            stampaCampo(&field[0]);
            field[row][column] = '*';
        } else {
            field[row][column] = 'X';
            stampaCampo(&field[0]);
            field[row][column] = ' ';
        }
        stampaCampo(&field[0]);
    }
}

//CASO IN CUI DOVESSE BATTERE IL GIOCATORE 2
void beat2(char field[10][10], char* player1, char* player2){
    int row, column;
    int probability;
    printf("Il pallone viene battuto da %s\n", player2);
    //sleep(2);
    //Controllo della probabilità
    //per sapere dove finirà il pallone
    probability = 1 + rand() % 100;
    //caso in cui il pallone termini sulla rete
    if(probability >= 0 && probability <= 10){
        row = 4;
        column = 0 + rand() % 9;
        printf("Pallone terminato sulla rete, nella posizione [%d][%d]\n", row, column);
        field[column][row] = 'O';
        stampaCampo(&field[0]);
        field[column][row] = '|';  //reset della posizione al valore iniziale
        stampaCampo(&field[0]);
        printf("Batterà %s\n", player1);
    }
    //caso in cui il pallone termini fuori
    else if(probability >= 11 && probability <= 31){
        printf("Pallone terminato fuori, batterà %s\n", player1);
    }
    //caso in cui il pallone cade nel campo
    else {
        //row = 0 + rand() % 3;
        //column = 0 + rand() % 9;
        row = (rand() % (3 + 1 - 0)) + 0;
        column = (rand() % (max +1 - 0)) + 0;
        printf("DEBUG --> row : [%d]\n", row);
        printf("DEBUG --> column: [%d]\n", column);
        //  TO DO: controlla se il pallone si trova nel quadrato intorno
        //         al giocatore avversario, se si allora batte dall'altro lato,
        //         altrimenti è punto.
    
        //reset della posizione al valore iniziale
        if(field[column][row] == '*'){
            field[column][row] = 'X';
            stampaCampo(&field[0]);
            field[column][row] = '*';
        } else {
            field[column][row] = 'X';
            stampaCampo(&field[0]);
            field[column][row] = ' ';
        }
        stampaCampo(&field[0]);
    }
}
*/