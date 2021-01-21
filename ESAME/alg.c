#include <stdio.h>
#include <string.h>

void aoins(int [], int); //algoritmo di ordinamento per inserimento
void swap(int *, int *); //algoritmo per lo swap di due variabili
void ord_sel_min(int *, int); //algoritmo di ordinamento per selezione di minimo
void ord_sel_max(int *, int); //algoritmo di ordinamento per selezione di massimo
int min_val_ind(int *, int, int *, int *); //algoritmo per la ricerca dell'elemento minimo e il suo indice
int max_val_ind(int *, int, int *, int *); //algoritmo per la ricerca dell'elemento massimo e il suo indice
int arbin(int *, int, int); //algoritmo di ricerca binaria versione iterativa
int arbinRic(int *, int, int); //algoritmo di ricerca binaria versione ricorsiva
void afus(int *, int, int *, int, int *); //algoritmo di fusione di due array ordinati
int StringMatching(char [], char []); //algoritmo di string matching (conta occorrenze)
int SommaRicorsiva(int [], int); //algoritmo di somma ricorsiva di un'array

int main(){
	int arr[] = {1,5,2,4,3};
	int list[] = {2,4,6,8,10};
	int a[] = {1,3,5,7,9};
	int b[] = {2,4,6,8,10};
	char key[] = "prova";
	char text[] = "questa è una prova di una prova di una prova che bho";
	int var;
	int c[10];
	int chiave = 6;
	int i;
	int size = 5; //size dell'array
	//aoins(arr,size); //richiamo della funzione di ordinamento
	//ord_sel_min(arr,size);
	ord_sel_max(arr,size);
	for(i = 0; i < size; i++){ //for che scorre tutto l'array
		printf("%d\t",arr[i]); //stampa gli elementi
	}
	printf("\n");
	if(arbinRic(list, size, chiave) == 1){
		printf("Chiave trovata\n");
	}
	else{
		printf("Chiave non trovata\n");
	}
	afus(a,size,b,size,c);
	for(i = 0; i < 10; i++){ //for che scorre tutto l'array
		printf("%d\t",c[i]); //stampa gli elementi
	}
	printf("\n");
	var = StringMatching(key,text);
	printf("Occorrenze trovate: %d\n", var);
	var = SommaRicorsiva(arr,size);
	printf("Somma degli elementi: %d\n", var);
	return 0;
}

//ALGORITMO DI ORDINAMENTO PER INSERIMENTO
void aoins(int arr[], int size){
	int i, j; //variabili per il for e per la posizione degli elementi da spostare
	int el_da_ins; //variabile momentanea dove conservare i valori che devono essere spostati
	for(i = 1; i < size; i++){ //for che parte dal secondo elemento poichè il primo è già ordinato
		el_da_ins = arr[i]; //salvo il valore di arr[i] in el_da_ins
		j = i-1; //decremento j per poter puntare all'elemento precedente
		while(j >= 0 && el_da_ins < arr[j]){ //finchè j diverso da 0 e el_da_ins minore dell'elemento nella posizione arr[j]
			arr[j+1] = arr[j]; //viene shiftato l'elemento da j a j+1
			j--; //decremento j per puntare all'elemento precedente fino ad arrivare a 0
		}
		arr[j+1] = el_da_ins; //trovata la posizione giusta viene inserito el_da_ins
	}
}

//FUNZIONE DI SWAP TRA DUE VARIABILI
void swap(int *a, int *b){
	int var; //variabile temporanea
	var = *b; //salvo il contenuto di b in var
	*b = *a; //sposto il contenuto di a in b
	*a = var; //sposto il contenuto di b salvato all'interno di var in a
}

//ALGORITMO DI ORDINAMENTO PER SELEZIONE DI MINIMO
int min_val_ind(int *arr, int size, int *minimo, int *ind_min){
	*minimo = arr[0]; //variabile per il valore minore posto al primo elemento dell'array
	*ind_min = 0; //variabile per l'indice del valore minore
	int i; //variabile per il for
	for(i = 0; i < size; i++){ //da 0 a size
		if(*minimo > arr[i]){ //controllo se maggiore di arr[i]
			*minimo = arr[i]; //salvo il valore minimo
			*ind_min = i; //salvo l'indice del valore minimo
		}
	}
	return *ind_min; //ritorno l'indice del valore minimo
}

void ord_sel_min(int *arr, int size){
	int minimo; //variabile per il valore minimo
	int ind_min; //variabile per l'indice del valore minimo
	int i; //variabile per il for
	for(i = 0; i < size-1; i++){ //da 0 a size-1
		min_val_ind(&arr[i], size-i, &minimo, &ind_min); 
		swap(&arr[i], &arr[ind_min+i]);
	}
}

//ALGORITMO DI ORDINAMENTO PER SELEZIONE DI MASSIMO
int max_val_ind(int *arr, int size, int *massimo, int *ind_max){
	*massimo = arr[0]; //variabile per il valore massimo posto al primo elemento dell'array
	*ind_max = 0; //variabile per l'indice del valore massimo
	int i; //variabile per il for
	for(i = 0; i < size; i++){ //da 0 a size
		if(*massimo < arr[i]){ //controllo se minore di arr[i]
			*massimo = arr[i]; //salvo il valore massimo
			*ind_max = i; //salv l'indice del valore massimo
		}
	}
	return *ind_max; //ritorno l'indice del valore massimo
}

void ord_sel_max(int *arr, int size){
	int massimo; //variabile per il valore massimo
	int ind_max; //variabile per l'indice del valore massimo
	int i; //variabile per il for
	for(i = size-1; i > 0; i--){ //da size-1 a 0 (quindi parte dal penultimo per arrivare al primo)
		max_val_ind(&arr[0], i+1, &massimo, &ind_max);
		swap(&arr[i], &arr[ind_max]);
	}
}

int arbin(int *arr, int size, int chiave){
	int primo = 0, ultimo = size-1, mediano; //variabili che indicano il primo, ultimo e il mediano elemento
	while(primo <= ultimo){ //fin quando ci sono elementi all'interno dell'array
		mediano = (primo + ultimo) / 2; //trovo il numero che si trova nel punto medio dell'array
		if(chiave == arr[mediano]){ //se è uguale alla chiave
			return 1; //allora torna 1
		} else if (chiave < arr[mediano]) //altrimenti se è più piccolo
			ultimo = mediano - 1; //pone come ultimo elemento, l'elemento che viene prima di mediano
					      //quindi si prende in considerazione la porzione di sinistra
		else //altrimenti se è più grande
			primo = mediano + 1; //pone come primo elemento, l'elemento che viene dopo mediano
					     //quindi si prende in considerazione la porzione di destra
	}
	return -1; //l'elemento non è stato trovato e quindi ritorna -1
}

int arbinRic(int *arr, int size, int chiave){
	int mediano; //questa volta ci serve solamente mediano
	if(size == 0) //caso banale, ovvero che non ci sono più elementi nell'array
		return 0; //ritorna 0, chiave non trovata
	mediano = (size - 1) / 2; //trovo il numero che si trova nel punto medio dell'array
	if(chiave == arr[mediano]){ //se è uguale alla chiave
		return 1; //allora ritorna 1
	} else if(chiave < arr[mediano]) //altrimenti se è più piccolo
		return arbinRic(arr,mediano,chiave); //si considera come size mediano,
						     //in modo tale da prendere in considerazione la porzione di sinistra
	else //altrimenti se è più grande si considera l'array che parte dalla posizione mediana+1, e come size la metà-1
		return arbinRic(arr + mediano + 1, size - mediano - 1, chiave);
}

void afus(int *a, int n_a, int *b, int n_b, int *c){
	int i_a = 0, i_b = 0, i_c = 0; //puntatori agli indici dei tre array
	while(i_a < n_a && i_b < n_b){ //finchè nessuno dei dure array non è finito
		if(a[i_a] < b[i_b]){ //controlla quale degli elementi è più piccolo
			c[i_c++] = a[i_a++]; //in modo tale da inserirlo all'interno di C
		} else {
			c[i_c++] = b[i_b++];
		}
	}
	while(i_a < n_a){ //controlla se gli elementi di A sono terminati
		c[i_c++] = a[i_a++]; //altrimenti li inserisce all'interno dell'array C
	}
	while(i_b < n_b){ //controlla se gli elementi di B sono terminati
		c[i_c++] = b[i_b++]; //altrimenti li inserisce all'interno dell'array C
	}
}

int StringMatching(char chiave[], char testo[]){
	int i, n, m, cont = 0;
	n = strlen(chiave); //lunghezza della chiave
	m = strlen(testo); //lunghezza del testo
	for(i = 0; i < m-n; i++){ //for che scorre tutto il testo
		if(strncmp(chiave, &testo[i], n) == 0){ //se le due sottostringhe sono uguali
			cont++; //incrementa il contatore delle sottostringhe uguali contate
		}
	}
	return cont; //ritorna il numero delle occorrenze
}

int SommaRicorsiva(int arr[], int n){
	if(n == 1){ //caso banale in cui c'è un singolo elemento
		return arr[0];
	} else { //altrimenti ritorna l'elemento n-1 più l'elemento ad n-1 per ogni volta
			 //in cui viene fatta la riattivazione
		return arr[n-1] + SommaRicorsiva(arr, n-1);
	}
}