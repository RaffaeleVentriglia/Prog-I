#include <stdio.h>

//void fusione(int [], int, int [], int, int []);
void fusioneWhile(int [], int, int [], int, int []);

int main(){
    int arr[4] = {1,4,7,9};
    int arr2[4] = {2,5,8,10};
    int c[8];
    fusioneWhile(arr, 4, arr2, 4, c);
    for(int i = 0; i < 8; i++){
        printf("%d\t", c[i]);
    }
    return 0;
}

/*
void fusione(int arr1[], int size1, int arr2[], int size2, int arr3[]){
    int i_a = 0, i_b = 0, i_c = 0;
    for(i_c = 0; i_c < size1 + size2; i_c++){       // inserimento nuovi elementi in array3
        if(i_a < size1 && i_b < size2){             // se uno dei due array è finito
            if(arr1[i_a] < arr2[i_b]){              // controlla se arr1[i_a] è minore di arr2[i_b]
                arr3[i_c] = arr1[i_a];
                i_a++;
            } else {                                // altrimenti arr1[i_a]
                arr3[i_c] = arr2[i_b];
                i_b++;
            }
        }
        else if(i_a >= size1){            
                arr3[i_c] = arr2[i_b];
                i_b++;
        }
        else {
                arr3[i_c] = arr1[i_a];
                i_a++;
            
        }
    }
}
*/

void fusioneWhile(int arr1[], int size1, int arr2[], int size2, int arr3[]){
    int i_a = 0, i_b = 0, i_c = 0;
    while(i_a < size1 && i_b < size2){   //finchè i_a e i_b non sono uguali a size1 e size2
        if(arr1[i_a] < arr2[i_b]){       //controlla se arr1[i_a] è minore di arr2[i_b]
            arr3[i_c++] = arr1[i_a++];   //in arr3[i_c] mette arr1[i_a]
        } else {
            arr3[i_c++] = arr2[i_b++];   //altrimenti mette arr2[i_b]
        }
    }
    while(i_a < size1)                   //finchè i_a è minore di size1
            arr3[i_c++] = arr1[i_a++];   //in arr3[i_c] mette arr1[i_a]
    while(i_b < size2)                   //finchè i_b è minore di size2
            arr3[i_c++] = arr2[i_b++];   //in arr3[i_c] mette arr2[i_b]
}