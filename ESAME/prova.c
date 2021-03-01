#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { //dichiaro una struct di nome elenco dentro la quale specifico il tipo dei dati costituenti gli utenti
  char nome[30];
  char cognome[30];
  char domicilio[30];
  char num_telefonico[30];
} Utente;

Utente utenti[]={
  {"Fulvio","Di Meglio","Via Foscolo","081/2387390"}, //inserisco i dati degli utenti
  {"Raimondo","Quoto","Via Zante","081/5498210"},
  {"Gianni","Mania","Viale Felice del Tredici","081/8776397"},
  {"Guido","Di Rado","Viale Natale","081/3497219"},
  {"Roberta","Greca","Piazza Gentile","081/9380756"},
  {"Flavia","Bellammondo","Corso Speranza","081/8732013"},
  {"Cristina","Esposito","Via Capodimonte","081/4308768"},
  {"Simone","Remondo","Via Capodichino","081/5021743"},
  {"Genoveffa","Di Maria","Via Sant'Alpino","081/9012312"},
  {"Santa","Vacca","Viale Renaldi","081/4587390"},
  {"Gianluca","Di Marzio","Piazza Stabene","081/4321084"},
  {"Ernesto","Valverde","Viale del Mulino","081/6309125"},
  {"Ariana","Grande","Los Angeles Street","626/8742910"},
  {"Rossella","Notaro","Via Repubblica","081/6472981"},
  {"George","Juarez","Viale Serra","081/6598210"},
  {"Margherita","Pizza","Via Napoli","081/0912783"},
  {"Fortuna","Incostante","Corso Costante","081/2013789"},
  {"Riccardo","Porto","Via Marina","081/6020650"},
  {"Maria Rosaria","Fior Di Latte","Viale Monte","081/4070230"},
  {"Filo","Lomena","Viale Sant'Angelo","081/4390777"},
  {"Renato","Tancredi","Via Erasmus","081/2938912"},
  {"Marco","Roccafonte","Corso Benevole","081/5391084"},
  {"Takeshi","Yoshida","Suzuki Abenyū","684/1286345"},
  {"Alessandro","Florenzi","Via De Medici","081/4204374"},
  {"Flora","Natura","Via Marzulla","081/3941212"},
  {"Martina","Zagaria","Viale Regina","081/2993922"},
  {"Ylenia","Della Corte","Corso Parlamento","081/2398324"},
  {"Eleonora","Grambone","Via Zuppetta","081/3234039"},
  {"Pasquale","Residenti","Via Casareale","081/8465210"},
  {"Lucia","Gravante","Corso Equilatero","081/4282333"}};
//dichiaro che il tipo struct elenco è identificato da ora in poi con tipo Elenco

void StampaElenco(Utente []);
void insertion_nome(Utente []);
void insertion_cognome(Utente []);
void insertion_domicilio(Utente []);
int ric_bin_ric(char [], char [], char[], Utente [], int);


int main(){

  char key_nome[30];//dichiaro le variabili e la loro grandezza massima
  char key_cognome[30];
  char key_domicilio[30];
  int n=30, i;
  //int nome_i, cognome_i, domicilio_i;

  insertion_cognome(utenti);
  StampaElenco(utenti);
  printf("Inserire il nome dell'utente:");
  fgets(key_nome,30,stdin);
  key_nome[strcspn(key_nome,"\n")] = 0;

  printf("Inserire il cognome dell'utente:");
  fgets(key_cognome,30,stdin);
  key_cognome[strcspn(key_cognome,"\n")] = 0;

  printf("Inserire il domicilio dell'utente:");
  fgets(key_domicilio,30,stdin);
  key_domicilio[strcspn(key_domicilio,"\n")] = 0; 

    if(ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)==-1)
    {
      printf("Non e' stato trovato alcun numero con quella combinazione.");
    } 
    else{
      printf ("Il numero telefonico di %s %s residente in %s e': %s\n", utenti[ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)].nome, utenti[ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)].cognome, utenti[ric_bin_ric(key_nome, key_nome, key_domicilio, utenti, n)].domicilio, utenti[ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)].num_telefonico);
    }
    while(ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)== -1)
    {
   printf("Inserire il nome dell'utente:");
    gets(key_nome);

     printf("Inserire il cognome dell'utente desiderato:");
     gets(key_cognome);

     printf("Inserire il domicilio dell'utente desiderato:");
     gets(key_domicilio);
    if
    (ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)== -1)
    printf("L'utente non e' stato trovato\n");
    else
    printf ("Il numero telefonico di %s %s residente in %s e': %s\n", utenti[ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)].nome, utenti[ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)].cognome, utenti[ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)].domicilio, utenti[ric_bin_ric(key_nome, key_cognome, key_domicilio, utenti, n)].num_telefonico);
    }
  return 0;
  /*} while(strcmp(utenti[nome_i].nome, key_nome) != 0 || strcmp(utenti[cognome_i].cognome, key_cognome) != 0 || strcmp(utenti[domicilio_i].domicilio, key_domicilio) != 0);
    return 0;*/
}

void StampaElenco(Utente utenti[30])
{
  int i;
  for(i = 0; i < 30; i++)
  {
    printf("Nome: %s, Cognome: %s, Domicilio: %s, Numero di telefono: %s\n", utenti[i].nome, utenti[i].cognome, utenti[i].domicilio, utenti[i].num_telefonico);
  }
}

/*void insertion_nome(Utente utenti[30])
{
    for (int i = 1; i < 30; i++)
    {
        int j = i;

        while (j > 0 && strcmp(utenti[j - 1].nome, utenti[j].nome) > 0)
        {
            char tmp[30];
            strncpy(tmp, utenti[j - 1].nome, sizeof(tmp) - 1);
            tmp[sizeof(tmp) - 1] = '\0';

            strncpy(utenti[j - 1].nome, utenti[j].nome, sizeof(utenti[j - 1].nome) - 1);
            utenti[j - 1].nome[sizeof(utenti[j - 1].nome) - 1] = '\0';

            strncpy(utenti[j].nome, tmp, sizeof(utenti[j].nome));
            utenti[j].nome[sizeof(utenti[j].nome) - 1] = '\0';

            --j;
        }
    }
}*/

void insertion_cognome(Utente utenti[30])
{
    for (int i = 1; i < 30; i++)
    {
        int j = i-1;
        Utente temp=utenti[i];

        while (j >= 0 && temp.cognome<utenti[j].cognome){
            strcpy(utenti[j + 1].cognome, utenti[j].cognome);
            j--;
        }
        strcpy(temp.cognome, utenti[j+1].cognome);
    }
}
/*void insertion_domicilio(Utente utenti[30])
{
    for (int i = 1; i < 30; i++)
    {
        int j = i;

        while (j > 0 && strcmp(utenti[j - 1].domicilio, utenti[j].domicilio) > 0)
        {
            char tmp[30];
            strncpy(tmp, utenti[j - 1].domicilio, sizeof(tmp) - 1);
            tmp[sizeof(tmp) - 1] = '\0';

            strncpy(utenti[j - 1].domicilio, utenti[j].domicilio, sizeof(utenti[j - 1].domicilio) - 1);
            utenti[j - 1].domicilio[sizeof(utenti[j - 1].domicilio) - 1] = '\0';

            strncpy(utenti[j].domicilio, tmp, sizeof(utenti[j].domicilio));
            utenti[j].domicilio[sizeof(utenti[j].domicilio) - 1] = '\0';

            --j;
        }
    }
}*/

int ric_bin_ric(char key_nome[], char key_cognome[], char key_domicilio[], Utente utenti[],int n){
  int mediano;
  if(n == 0)
     return 0;
  mediano = (n-1)/2;
  if(strcmp(key_nome,utenti[mediano].nome) == 0 && strcmp(key_cognome, utenti[mediano].cognome)== 0 && strcmp(key_domicilio, utenti[mediano].domicilio)== 0  )
     return 1;
  else if(strcmp(key_nome,utenti[mediano].nome) < 0 && strcmp(key_cognome, utenti[mediano].cognome)< 0 && strcmp(key_domicilio, utenti[mediano].domicilio)< 0  )
     return ric_bin_ric(key_nome,key_cognome,key_domicilio,utenti,mediano);
  else
     return ric_bin_ric(key_nome,key_cognome,key_domicilio,utenti+mediano+1,n-mediano-1);
}