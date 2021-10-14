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
	int i, j, temp, temp1;
	
	for(i=k;i>0;i--){
		temp = vet[0]; 
		for(j=0;j<n-1;j++){   
			temp1= vet[j+1];
			if(j+1>=n){
				vet[j+1]=temp;
			} 
			temp=temp1;
		}
		vet[0]=-1;
	}
	
	printf("Il vettore cambiato di %d posizioni: ", k);
	for(i=0;i<n;i++){
		printf("%d ", vet[i]);
	}
}
