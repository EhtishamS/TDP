/*
	Name: Ehtisham Sarwar
	Copyright: //
	Author: Sarwar Ehtisham
	Date: 19/03/21 14:52
	Description: Scrivi un programma che genera un file di testo contenente N numeri float casuali compresi
	tra 0 e 1, separati dal carattere "a capo". Il valore N ed il nome del file sono forniti dall'utente.
	Se il file esiste già, il programma deve aggiungere i nuovi numeri alla fine del file esistente. 

	Esempio: se N = 3, il contentuo del file di output può essere:

	0.8039451
	0.5739421
	0.178321
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100
#define CASUALE 1000
int main() {
	int n, i, lunghezza;
	double valore, random;
	char nomeFile[MAX];
	srand(time(NULL));
	
	do{
		printf("Quanti numeri casuali tra 0 e 1 vuole generare: ");
		scanf("%d", &n);
		while(getchar()!='\n');
		printf("Inserire il nome del file: ");
		gets(nomeFile);
	}while(n<=0);
	
	FILE * fp = fopen(nomeFile, "a");  
	
	if (fp != NULL) {  
		while(n>0){
			random = (rand()% CASUALE);
			valore = random/CASUALE;
			fprintf(fp,"%c\n", nomeFile);
			n--;
		}
		fclose(fp);
		printf("Programma terminato con successo!");
	} else 
		printf("Impossibile aprire il file!");
}
