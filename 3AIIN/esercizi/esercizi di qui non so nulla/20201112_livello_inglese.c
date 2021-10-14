/*
Un sito web propone un test per determinare il livello di inglese dei visitatori. Il test 
prevede un punteggio da 0 a 100. se il punteggio è inferiore a 40, il sito assegna
all'utente il livello 1. Se il punteggio è compreso tra 40 e 79, il livello e' 2. Se il 
punteggio è maggiore o uguale a 80, il livello e' 3. 
Definisci la funizione livello, che consenta di calcolare il livello a partire dal punteggio. 
Infine scrivi un programma che utilizza la funzione.
*/
#include<stdio.h>

int livello(int punteggio);

int main(){
	int punteggio, risultato;
	
	do{
		printf("Inserire il punteggio del test: ");
		scanf("%d", &punteggio);
	}while(punteggio<0 || punteggio>100);

	risultato = livello(punteggio);

	switch(risultato){
		case 1:
			printf("utene livello %d!", risultato);
			break;
		case 2:
			printf("utene livello %d!", risultato);
			break;
		case 3:
			printf("utene livello %d!", risultato);
			break;
		default:
			printf("errore 404!");
			break;
	}
	return 0;
}

int livello(int punteggio){
	int ris;

	if(punteggio<40){
		ris = 1;
	}
	else if (punteggio>=40 && punteggio<=79){
		ris = 2;
	}
	else{
		ris = 3;
	}

	return ris;
}


