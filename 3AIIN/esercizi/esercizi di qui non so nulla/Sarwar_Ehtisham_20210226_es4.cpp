#include<iostream>
#define MAX 20
using namespace std;

void inputDati(int mtr[][MAX], int &dimensione);
void stampaDist(int mtr[][MAX], int dimensione);
void calcoloLunghezza(int mtr[][MAX], int dimensione);
void trovaStazioniRaggiungibili(int mtr[][MAX], int dimensione, int vet[], int &dim_vet);


int main (){
	int mtr[MAX][MAX], dimensione, vett[MAX], dimensione_vettore, i;
	
	inputDati(mtr,dimensione);
	stampaDist(mtr,dimensione);
	calcoloLunghezza(mtr,dimensione);
	trovaStazioniRaggiungibili(mtr,dimensione,vett,dimensione_vettore);
	
	cout<<"\nLe stazioni raggiungibili vicino alla tua stazione sono i seguenti: ";
	for(i=0;i<dimensione_vettore;i++){
		cout<<vett[i]<<" ";
	}
	
	return 0;
}

void inputDati(int mtr[][MAX], int &dimensione){
	int i, j, temp;
	do{
		cout<<"Quante stazioni vuole inserire: ";
		cin>>dimensione;
	} while(dimensione<=1 || dimensione > MAX);
	
	cout<<"\n\nINPUT DATI\n\n";
	for(i=0;i<dimensione;i++){
		for(j=0;j<=i;j++){
			if(j==i){
				mtr[i][j]=0;
			} else {
				do{
					cout<<"Inserire la distanza tra la stazione "<<i<<" e la stazione "<<j<<" (se non sono collegati scrivere 0): ";
					cin>>temp;
				}while(temp<0);
				mtr[i][j]=mtr[j][i]=temp;
			}			
		}
	}
}

void stampaDist(int mtr[][MAX], int dimensione){
	int i, j;
	
	cout<<"\n\nDISTANZA DALLE VARIE STAZIONI\n\n";
	for(i=0;i<dimensione;i++){
		for(j=0;j<i;j++){
			if(mtr[i][j]){
				cout<<"\nla distanza dalla "<<i<<" stazione fino alla "<<j<<" stazione e di "<<mtr[i][j]<<" Km";
			} else{
				cout<<"\nle stazioni "<<i<<" e "<<j<<" non sono collegati tra di loro!";	
			}
		}
	}
}

void calcoloLunghezza(int mtr[][MAX], int dimensione){
	int lunghezza, i, j;
	
	for(i=0;i<dimensione;i++){
		for(j=0;j<i;j++){
			if(j==i-1){
				lunghezza+=mtr[i][j];
			}
			if(i==dimensione-1 && j==0){
				lunghezza+=mtr[i][j];
			}
		}
	}
	cout<<"\n\n\nLUNGHEZZA DELLA METROPOLITANA\n\n";
	cout<<"La lunghezza totale dell'intera metropolitana e di "<<lunghezza<<" Km";
}


void trovaStazioniRaggiungibili(int mtr[][MAX], int dimensione, int vet[], int &dim_vet){
	int i, j, stazione;
	
	cout<<"\n\n\nRICERCARE STAZIONI VICINE\n\n";
	dim_vet=0;
	do{
		cout<<"Dire una stazione: ";
		cin>>stazione;
	}while(stazione<0 || stazione>dimensione-1);
	
	for(i=0;i<dimensione;i++){
		for(j=0;j<i;j++){
			if(stazione == j){
				if(mtr[i][j]!=0){
					vet[dim_vet]=i;
					dim_vet++;
				}
			}
			if(stazione == i){
				if(mtr[i][j]!=0){
					vet[dim_vet]=j;
					dim_vet++;
				}	
			}
		}
	}
}
