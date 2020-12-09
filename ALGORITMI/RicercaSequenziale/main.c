//algoritmo di ricerca sequenziale

#include <stdio.h>
#define false 0
#define true 1

int appartiene(int [], int, int);

int main(){
    int n = 0, i, stato;
    int arr[100];
    int chiave;
    printf("Inserire size dell'array: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        printf("Inserire il %d° elemento: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Inserire la chiave da cercare all'interno dell'array: ");
    scanf("%d", &chiave);
    stato = appartiene(arr, chiave, n);
    if(stato == 0){
        printf("La chiave non è stata trovata all'interno dell'array\n");
    } else
        printf("La chiave è stata trovata all'interno dell'array\n");
    return 0;
}

int appartiene(int arr[], int chiave, int n){
    int stato = false;
    int i = 0;
    while(chiave != arr[i] && i < n-1){
        i++;
        if(chiave == arr[i])
            stato = true;
        else
            stato = false;
    }
    return stato;
}

/*               COMPLESSITÀ DI TEMPO E SPAZIO
 *
 *     la function farà al più n confronti nel caso peggiore,
 *     ovvero che la chiave si trovi alla fine o che addirittura
 *     non sia proprio presente all'interno dell'array
 *     Quindi la complessità è lineare (O(n))
*/