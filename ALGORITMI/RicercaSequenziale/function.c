#include "function.h";

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