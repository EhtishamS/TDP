#include<bits/stdc++.h>
using namespace std;

void div(int N);

int main(){
	int risultato, N;
	cout<<"inserisci un numero: ";
	cin>>N;
	div(N);
	
}

void div(int N){
	int div;
	cout<<"I divisori di sono: ";
	for(int i=1;i<=N;i++){
		if(N%i == 0){
			cout<<" "<<i;
		}
	}
}


