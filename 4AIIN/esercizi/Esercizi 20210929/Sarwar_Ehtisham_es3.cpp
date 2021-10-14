#include<iostream>
#include<math.h>

using namespace std;

class Frazione{
	private:
		int num;
		int denum;
		
		void semplifica();
	public:
		Frazione (); // (1) inizializza a 1 il numeratore e il denominatore
		
		Frazione (int n, int d); // (2) Posso inizializzare la frazione tramite l'utente.
		
		void setNum(int n); // (3) Set prendono sempre un parametro dentro
		
		void setDenum(int d); // (4) Nel denum devo stare attento il denominatore perch� non pu� essere nullo.
	
		int getNum();
		
		int getDenum();
		
		void input();
		
		void stampa();
		
		void aggiungi(Frazione &f2);
		
		void sottrai(Frazione &f2);
		
		void moltiplicaPer(Frazione &f2);
		
		void dividiPer(Frazione &f2);
		
		int confrontaCon(Frazione &f2);
		
};

int MCD(int a, int b);

int main(){
	Frazione f1, f2;

	char segno;
	
	cout<<"Inserisci frazione: \n";
	f1.input();

	do{
		cout<<"Inserisci l'operazione: ";
		cin>>segno;

		cout<<"Inserisci frazione: \n";
		f2.input();		

		switch(segno){
			case '+': 
				f1.aggiungi(f2);
				cout<<"Risultato: ";
				f1.stampa();
				cout<<"\n";
				break;
			case '-':
				f1.sottrai(f2);
				cout<<"Risultato: ";
				f1.stampa();
				cout<<"\n";
				break;
			case '*':
				f1.moltiplicaPer(f2);
				cout<<"Risultato: ";
				f1.stampa();
				cout<<"\n";
				break;
			case '/':
				f1.dividiPer(f2);
				cout<<"Risultato: ";
				f1.stampa();
				cout<<"\n";
				break;
			default:
				cout<<"\nInserire una operazione valida, premere q per uscire!\n";
				break;
		}
		
	}while(segno != 'q');

	cout<<"Fine";
	
	return 0;
}

int MCD(int a, int b) {
	if (a<0) a=-a;
	if (b<0) b=-b;
	if (b == 0) return a; 
	int r = a % b; 
	while(r != 0) {
		a = b;
		b = r;
		r = a % b;
	}	
	return b; 
}

Frazione::Frazione (){ 
	num = 1;
	denum = 1;
}

Frazione::Frazione (int n, int d){ 
	num = n;
	denum = d;
}

void Frazione::setNum(int n){ 
	num = n;
}

void Frazione::setDenum(int d){ 
	if(d!=0)
		denum = d;
	else{
		cout<<"Non puoi impostare il denominatore a zero.";
		exit(-1);
	}
}

int Frazione::getNum(){
	return num;
}
		
int Frazione::getDenum(){
	return denum;
}
		
void Frazione::input(){
	cout<<"Inserire il numeratore: ";
	cin>>num;
			
	cout<<"Inserire il denominatore: ";
	cin>>denum;
	
	if(denum==0){
		cout<<"Denominatore nullo!";
		exit(-1);
	}
}

void Frazione::stampa(){
	if(num<0 ^ denum<0){
		cout<<"-"<<abs(num)<<"\\"<<abs(denum);
	} else if(denum == 1){
		cout<<num;
	} else {
		cout<<abs(num)<<"\\"<<abs(denum);
	}
}

void Frazione::semplifica(){
	int div = MCD(num, denum);
	
	num /= div;
	denum /= div;
}

void Frazione::aggiungi(Frazione &f2){
	int numeratore = (num*f2.denum) + (denum*f2.num);
	int denominatore = denum * f2.denum;
	num = numeratore;
	denum = denominatore;	
	
	semplifica();
}

void Frazione::sottrai(Frazione &f2){
	int numeratore = (num* f2.denum) - (denum*f2.denum);
	int denominatore = denum * f2.denum;
	num = numeratore;
	denum = denominatore;
	
	semplifica();
}

void Frazione::moltiplicaPer(Frazione &f2){
	num *= f2.num;
	denum *= f2.denum;
	
	
	semplifica();
}

void Frazione::dividiPer(Frazione &f2){
	moltiplicaPer(f2);
}

int Frazione::confrontaCon(Frazione &f2){
	double fraz1, fraz2;

	fraz1 = (double) num/denum;
	fraz2 = (double) f2.num/f2.denum;

	if(fraz1>fraz2){
		return 1;
	} else if(num == f2.num && denum == f2.denum){
		return 0;
	}

	return -1;
}
