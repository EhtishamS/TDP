/*
	Name: Ehtisham Sarwar
	Copyright: //
	Author: Sarwar Ehtisham
	Date: 19/03/21 14:55
	Description: Scrivi un programma che genera un file di testo contenente N numeri interi casuali 
	compresi tra A e B, separati dal carattere "spazio". I valori N, A, E ed il nome del file sono forniti 
	dall'utente. Nel caso in cui non sia possibile creare il file, il programma deve mostrare un opportuno 
	messaggio di errore.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {
	int a, b, n;
	int numrand;
	srand(time(NULL));
	
	do{
		printf("Quanti numeri casuali vuole inserire: ");
		scanf("%d", &n);
		printf("Inserire l'intervallo tra quale vuole generare i numeri (a>b): ");
		scanf("%d %d", &a, &b);
	}while(n<=0 || a>b);
	
	FILE * fp = fopen("C:/Users/ehtis/OneDrive/Desktop/file c generatore/numeri_generati.txt", "w");  
	
	if (fp != NULL) {  
		while(n>0){
			numrand = rand()% ((b-a)+1)+a;
			fprintf(fp,"%d ", numrand);
			n--;
		}
		fclose( fp );
		printf("Programma terminato con successo!");
	} else 
		printf("Impossibile aprire il file!");
}
