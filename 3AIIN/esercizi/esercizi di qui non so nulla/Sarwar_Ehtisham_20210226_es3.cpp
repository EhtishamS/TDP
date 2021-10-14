#include<iostream>
#define MAX_M 2
#define MAX_P 3
#define MAX_N 2
using namespace std;

void insert1(int mtr[][MAX_P], int num_colonne, int num_righe);
void insert2(int mtr[][MAX_N], int num_colonne, int num_righe);
void prodotto(int mtr1[][MAX_P], int mtr2[][MAX_N], int mtr3[][MAX_N],int num_righe, int num_colonne_righe, int num_colonne);


int main (){
	int mtr1[MAX_M][MAX_P], mtr2[MAX_P][MAX_N], mtr3[MAX_M][MAX_N];
	
	cout<<"Inserimento matrice 1:\n";
	insert1(mtr1,MAX_P,MAX_M);
	cout<<"Inserimento matrice 2:\n";
	insert2(mtr2,MAX_N,MAX_P);
	prodotto(mtr1, mtr2, mtr3, MAX_M, MAX_P, MAX_N);
}

void insert1(int mtr[][MAX_P], int num_colonne, int num_righe){
	int i, j;
	
	for(i=0;i<num_righe;i++){
		for(j=0;j<num_colonne;j++){
			cout<<"Inserire il numero per la cella ["<<i<<"] ["<<j<<"]: ";
			cin>>mtr[i][j];
		}
	} 
}

void insert2(int mtr[][MAX_N], int num_colonne, int num_righe){
	int i, j;
	
	for(i=0;i<num_righe;i++){
		for(j=0;j<num_colonne;j++){
			cout<<"Inserire il numero per la cella ["<<i<<"] ["<<j<<"]: ";
			cin>>mtr[i][j];
		}
	} 
}

void prodotto(int mtr1[][MAX_P], int mtr2[][MAX_N], int mtr3[][MAX_N], int num_righe, int num_colonne_righe, int num_colonne){
	int i, j, k;
	
	for(i=0;i<num_righe;i++){
		for(j=0;j<num_colonne;j++){
			k=0;
			mtr3[i][j]=0;
			while(k<num_colonne_righe){
				mtr3[i][j]+=(mtr1[i][k]*mtr2[k][j]);
				k++;
			}
		}
	}
	
	cout<<"\n\n";
	for(i=0;i<num_righe;i++){
		for(j=0;j<num_colonne;j++){
			cout<<mtr3[i][j]<<"\t";
		}
		cout<<endl;
	}
}
