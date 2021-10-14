#include<iostream>
#define MAX 20

using namespace std;

void insert(int mtr[][MAX], int &numElem);
void isPredominanzaDiagonale(int mtr[][MAX], int numElem);
void stampa(int mtr[][MAX], int numElem);

int main (){
	int mtr[MAX][MAX], n;
	
	insert(mtr,n);
	isPredominanzaDiagonale(mtr,n);
	stampa(mtr,n);
	
	return 0;
}

void insert(int mtr[][MAX], int &numElem){
	int i, j;
	
	do{
		cout<<"Dire la dimensione della matrice: ";
		cin>>numElem;
	}while(numElem<=1);
	
	for(i=0;i<numElem;i++){
		for(j=0;j<numElem;j++){
			cout<<"Inserire il valore per la cella ["<<i<<"] ["<<j<<"]: ";
			cin>>mtr[i][j];
		}
	}
}
void isPredominanzaDiagonale(int mtr[][MAX], int numElem){
	int i, j, max, nonpredominante=0;
	
	for(i=0;i<numElem&&nonpredominante==0;i++){
		max = mtr[i][0];
		
		for(j=0;j<numElem;j++){
			if(mtr[i][j]>max){
				max = mtr[i][j];
			}	
		}
		
		for(j=0;j<numElem&&nonpredominante==0;j++){
			if(j==i){
				if(max>mtr[i][j]){
					nonpredominante=1;
				}
			}
		}
	}
	
	if(nonpredominante==0){
		cout<<"questa matrice e' a predominanza diagonale!";
	} else {
		cout<<"questa matrice non e' a predominanza diagonale!";
	}
}

void stampa(int mtr[][MAX], int numElem){
	int i, j;
	
	cout<<"\n\n";
	for(i=0;i<numElem;i++){
		for(j=0;j<numElem;j++){
			cout<<mtr[i][j]<<"\t";
		}
		cout<<endl;
	}
}
