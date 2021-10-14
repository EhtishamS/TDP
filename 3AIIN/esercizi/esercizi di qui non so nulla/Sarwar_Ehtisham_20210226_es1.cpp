#include<iostream>
#include<string.h>
#define MAX 20
using namespace std;

int contiene(char *s1, char *s2);
int ricerca(char c, char *s);

int main (){
	char str1[MAX], str2[MAX];
	int ris;
	
	cout<<"Scrivere due parole: ";
	cin>>str1>>str2;
	
	ris = contiene(str1,str2);
	
	if(ris == 1){
		cout<<"Tutte le cifre della prima stringa sono presenti anche nel secondo!";
	} else {
		cout<<"Le cifre del primo non sono tutte contenute all'interno del secondo!";
	}
	
	return 0;
}

int contiene(char *s1, char *s2){
	int i, j, ris=1;
	char c;
	
	for(i=0;i<strlen(s1)&&ris==1;i++){
		c = s1[i];
		ris = ricerca(c, s2);
	}
	
	return ris;
}

int ricerca(char c, char *s){
	int i, trovato=0;
	
	for(i=0;i<strlen(s)&&trovato==0;i++){
		if(c==s[i]){
			trovato = 1;
		}
	}
	
	return trovato;
}
