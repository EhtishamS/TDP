/*
Si scriva un programma C che legga una serie di dati 
e li memorizzi in un vettore SQUADRE (di dimensione 
3 contenente strutture (struct squadra) del tipo:

-nome squadra (stringa lunghezza 20).
-codice squadra (intero)
-goal fatti (intero)
-goal subiti(intero)

stampi a terminale tutti i nomi e codici delle squadre
che hanno fatto un numero di goal maggiore del numero dei goal subiti.

Letto a terminale un codice di una squadra stampi a
video il nome della squadra, i goal fatti e i goal subiti.
*/
#include<stdio.h>

#define GRUPPI 3
#define NOME_SQUADRA 20

struct squadra{
	char nome[NOME_SQUADRA];
	int codiceSquadra;
	int goalFatti;
	int goalSubiti;
};

void insert(struct squadra *squadre);
int stampaPerCodice(const struct squadra *squadre, const int codiceRicerca);
void stampa(struct squadra squadraSingola);
void stampaPerIGoal(const struct squadra *squadre);

int main(){
	struct squadra squadre[GRUPPI];
	
	int codiceRicerca, ris;
	
	insert(squadre);
	
	printf("\nInserire un codice di una squadra: ");
	scanf("%d", &codiceRicerca);
	
	ris = stampaPerCodice(squadre,codiceRicerca);
		
	if(!ris){
		printf("\nSquadra non trovata!");
	}
	
	printf("\n\nSTAMPA LE SQUADRE PER I GOAL:");
	
	stampaPerIGoal(squadre);
	
	return 0;
}

void insert(struct squadra *squadre){
	for(int i=0;i<GRUPPI;i++){
		
		printf("\nInserire il nome della squadra: ");
		scanf("%s",squadre[i].nome);
		
		printf("Inserire il codice identificativo della squadra: ");
		scanf("%d",&squadre[i].codiceSquadra);
	
		printf("Inserire il numero di goal fatti dalla squadra: ");
		scanf("%d",&squadre[i].goalFatti);
		
		printf("Inserire il numero di goal subiti dalla squadra: ");
		scanf("%d",&squadre[i].goalSubiti);
	}
}

int stampaPerCodice(const struct squadra *squadre, const int codiceRicerca){
	for(int i=0;i<GRUPPI;i++){
		if(squadre[i].codiceSquadra == codiceRicerca){
			stampa(squadre[i]);
			return 1;
		}
	}
	
	return 0;
}

void stampa(struct squadra squadraSingola){
	printf("\n\nIl nome della squadra e %s", squadraSingola.nome);
	printf("\nIl codice della squadra e %d",squadraSingola.codiceSquadra);
	printf("\nI goal fatti dalla squadra %d", squadraSingola.goalFatti);
	printf("\nI goal subiti dalla squadra %d", squadraSingola.goalSubiti);
}

void stampaPerIGoal(const struct squadra *squadre){
	for(int i=0;i<GRUPPI;i++){
		if(squadre[i].goalFatti>squadre[i].goalSubiti){
			stampa(squadre[i]);
		}
	}
}
