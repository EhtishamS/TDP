#include<stdio.h>
#define MAX 100

void trasla (int vet[], int n, int k);

int main (){
	int array[MAX], lunghezza, spostamento, i;
	
	do{
		printf("Dire di quando vuole il vettore: ");
		scanf("%d", &lunghezza);
	}while(lunghezza<0 || lunghezza>MAX);
	
	for(i=0;i<lunghezza;i++){
		printf("Inserire il valore per la cella [%d]: ", i);
		scanf("%d", &array[i]);
	}
	
	do{
		printf("Di quanto vuole spostare gli elementi: ");
		scanf("%d", &spostamento);
	}while(spostamento<0 || spostamento>lunghezza);
	
	trasla(array, lunghezza, spostamento);
}

void trasla (int vet[], int n, int k){
	int i, j;
	
	for(i=k;i>0;i--){
		for(j=n;j>0;j--){
			vet[i]=vet[i-1]; // 
		}
		vet[0]=-1;
	}
	
	printf("Il vettore cambiato di %d posizioni: ", k);
	for(i=0;i<n;i++){
		printf("%d ", vet[i]);
	}
}
