#include<stdio.h>
#define MAX 100
int confrontoArray(int vet[], int n, int vet1[], int n1);

int main (){
	int array[MAX], array1[MAX], lunghezza, lunghezza1;
	int i;
	do{
		printf("Dire la lunghezza del primo Array: ");
		scanf("%d", &lunghezza);
		printf("Dire la lunghezza del secondo Array: ");
		scanf("%d", &lunghezza1);
	}while(lunghezza<0 || lunghezza >MAX || lunghezza1<0 || lunghezza1 > MAX);

	printf("\nAdesso devi inserire dati per il primo vettore!\n");	
	for(i=0;i<lunghezza;i++){
		printf("Inserire un valore per [%d] cella: \n", i);
		scanf("%d", &array[i]);
	}
	
	printf("\nAdesso devi inserire dati per il secondo vettore!\n");
	for(i=0;i<lunghezza1;i++){
		printf("Inserire un valore per [%d] cella: \n", i);
		scanf("%d", &array1[i]);
	}
	
	i = confrontoArray(array, lunghezza, array1, lunghezza1);
	
	if(i==1){
		printf("Il primo Array e' minore di tutti gli elementi del secondo Array!");
	} else {
		printf("Il primo Array non e' minore di tutti gli elementi del secondo Array!");
	}
}

int confrontoArray(int vet[], int n, int vet1[], int n1){
	int i, j, ris, flag=0;
	
	for(i=0;i<n1&&flag==0;i++){
		for(j=0;j<n&&flag==0;j++){
			if(vet1[i] < vet[j]){
				flag=1;
			}
		}
	}
	
	if(flag==0){
		ris = 1;
	} else {
		ris = 0;
	}
	
	return ris;
}
