#include<stdio.h>
#define MAX 100
void acquisizione(int vet[], int n);
int confronto(int array[], int n, int array1[]);

int main (){
    int vet1[MAX], vet2[MAX], lunghezza, ris;

    do{
        printf("Inserire la lunghezza per i vettori: ");
        scanf("%d", &lunghezza);
    }while(lunghezza<0 || lunghezza>MAX);

    printf("\nAdesso devi inserire i valori per il primo vettore!")
    acquisizione(vet1, lunghezza);
     printf("\nAdesso devi inserire i valori per il secondo vettore!")
    acquisizione(vet2, lunghezza);

    ris = confronto (vet1, lunghezza, vet2);

    printf("Il prodotto scalare e' di: %d", ris);
    return 0;
}

void acquisizione(int vet[], int n){
    int i;

    for(i=0;i<n;i++){
        printf("Inserire il valore per la cella [%d]: ", i);
        scanf("%d", &vet[i]);
    }
}

int confronto(int array[], int n, int array1[]){
    int ris=0, i;

    for(i=0;i<n;i++){
        ris= ris+(array[i]*array1[i]);
    }

    return ris;
}