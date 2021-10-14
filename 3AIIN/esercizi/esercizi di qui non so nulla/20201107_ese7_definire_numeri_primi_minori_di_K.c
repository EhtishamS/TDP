/*
Scrivere i numeri primi monori a un numero K che è dato dall'utente.
*/
#include<stdio.h>

int numK();
void numminprim (int K);

int main(){
	int K;
	
	K = numK();
	numminprim (K);
}

int numK(){
	int temp;
	
	do{
		printf("Inserire un numero maggiore di 1: ");
		scanf("%d", &temp);
	}while(temp<=1);
	
	return temp;
}

void numminprim (int K){
	int i, j, flag=0;
	
	for(i=2;i<K;i++){
		flag=0;
		for(j=2;j<i&flag==0;j++){
			if(i%j==0){
				flag=1;
			}
		}
		if(flag==0){
			printf("il numero %d e primo!\n", i);
		}
	}	
}
