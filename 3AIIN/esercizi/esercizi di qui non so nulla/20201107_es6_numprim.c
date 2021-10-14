/*
Definire se il numero inserito dall'utente è primo oppure no.
*/
#include<stdio.h>

int numprim(int N);

int main(){
	int N, flag;
	
	do{
		printf("Dire un numero primo maggiore di 1: ");
		scanf("%d", &N);	
	}while(N<=1);
	
	flag = numprim(N);
	
	if(flag == 0){
		printf("Il numero e' primo!");
	}
	else{
		printf("Il numero non e' primo!");
	}
}

int numprim(int N){
	int flag=0, i;
	
	for (i=N/2;i>1&&flag==0;i--){
		if(N%i==0){
			flag = 1;
		}
	}
	
	return flag;
}
