/*
Un negozio di alimenti ha un archivio in cui vengono memorizzati
i prodotti presenti in magazzino. Per ogni prodotto in magazzino, si
dispone dei seguenti dati:
- La descrizione (stringa di al massimo 20 caratteri, incluso il 
terminatore).
- La quantità disponibile in magazzino (int).
- L'anno di scandenza (int).

Il programma deve memorizzare in un arrai di strutture tutti i
prodotti che sono da cancellare dell'archivio perché scaduti (in cui 
l'anno di scadenza è prima del 2010).
*/

#include<iostream>
using namespace std;

#define STR_MAX 20+1
#define MAX_MAGAZZINO 30
#define DATA_SCAD 2010

struct prodotto{
	char descrizione[STR_MAX];
	int quantita;
	int data;
};

void prodottiScaduti(prodotto *magazzino, prodotto *prodScad, int cont_magazzino, int &cont_scad);
void stampa(prodotto *prodScad, int cont_scad);

int main(){
	struct prodotto magazzino[MAX_MAGAZZINO] = {
	{"pere",150,2006},
	{"arance",210,2010},
	{"tonno",48,2007},
	{"melanzane",85,2009},
	{"olio",60,2015},
	{"aceto",49,2012},
	{"pomodoro",61,2005},
	{"pasta",75,2011}};
	
	prodotto prodScad[MAX_MAGAZZINO];
	
	int cont_magazzino = 8;
	int cont_scad = 0;

	prodottiScaduti(magazzino,prodScad,cont_magazzino,cont_scad);
	stampa(prodScad,cont_scad);
	
	return 0;
}

void prodottiScaduti(prodotto *magazzino, prodotto *prodScad, int cont_magazzino, int &cont_scad){
	for(int i=0;i<cont_magazzino;i++){
		if(magazzino[i].data < DATA_SCAD){
			prodScad[cont_scad] = magazzino[i];
			cont_scad++;
		}
	}
}

void stampa(prodotto *prodScad, int cont_scad){
	cout<<"PRODOTTI SCADUTI:\n";
	for(int i=0;i<cont_scad;i++){
		cout<<prodScad[i].descrizione<<" "<<prodScad[i].quantita<<" "<<prodScad[i].data<<"\n";
	}
}


