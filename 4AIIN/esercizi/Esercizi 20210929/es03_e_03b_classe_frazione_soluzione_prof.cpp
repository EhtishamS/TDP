#include <iostream>
#include <cstdlib>
using namespace std;

class Frazione 
{
	private:
	  int num; 
	  int den; 
	  int MCD(int a, int b);
	  void semplifica();
	  void errDenominatoreZero();
	public:
	  Frazione();
	  Frazione(int a, int b);
	  void setNumeratore(int num);
	  void setDenominatore(int den);
	  void input();
	  int getNumeratore();
	  int getDenominatore();
	  void somma(Frazione& f);
	  void sottrai(Frazione& f);
	  void moltiplica(Frazione& f);  
	  void dividi(Frazione& f);
	  void stampa();
};

char inputOperazione();

int Frazione::MCD(int a, int b) {
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

void Frazione::errDenominatoreZero() {
	cout << "\nErrore: Denominatore nullo \n";
	exit(EXIT_FAILURE);
}
	  
void Frazione::semplifica() {
  int mcd = MCD(num, den);
  num = num/mcd;
  den = den/mcd;
}
	  
Frazione::Frazione() {
  num = 1;
  den = 1;
}
	  
Frazione::Frazione(int num, int den){
  if ( den != 0 ) {
  	this->num = num;
  	this->den = den;
  	semplifica();
  }
  else {
  	errDenominatoreZero(); 
  }
}
	 
void Frazione::setNumeratore(int num) {
  this->num = num;
}
	  
void Frazione::setDenominatore(int den) {
  if (den!=0) 
	this->den = den;	
  else 
  	errDenominatoreZero(); 
}

void Frazione::input() {
   int n,d;
   char c;
   bool valido;
   do {
	   cout << " Inserisci frazione: ";

	   valido=true;
	   
	   if ( !(cin >> n ) ) {
	   		cout << " Errore di input: la frazione deve inziare con un numero \n";
	   		valido=false;
	   		cin.clear(); // resetta lo stato della cin per leggere altri valori.
	   		while(cin.get()!='\n'); // legge fino a "\n" e ferma l'andare all'infinito del programma per l'errore della lettura.
	   		continue;
	   }

		//consumo eventuali caratteri " " o "\n"
		c=cin.get();
		while( c==' ' || c=='\n' ) {
			c = cin.get();
		}
		   
		if ( c !='/') {
			cout << " Errore di input: la frazione deve contenere la barra (/) \n";
			valido=false;
			while(cin.get()!='\n');
			continue;
		}
		   
		if ( !( cin >> d ) ) {
			cout << " Errore di input: dopo la barra deve esserci un numero \n";
		   	valido=false;
		   	cin.clear();
		   	while(cin.get()!='\n');
		   	cout << "continuo\n";
		   	continue;
		}
		   
		if ( d==0 ) {
		   	cout << " Errore di input: denominatore non valido\n";
		   	valido=false;
		   	while(cin.get()!='\n');
		   	continue;
		}
	   
	}
	while( !valido );
	
   num = n;
   den = d;
   cin.get();
}
	  
int Frazione::getNumeratore() {
  return num;
}
	  
int Frazione::getDenominatore() {
  return den;
}
	 
void Frazione::somma(Frazione& f) {
  num = (num * f.den) + (den * f.num);	 
  den = den*f.den; 
  semplifica();	
}
	  
void Frazione::sottrai(Frazione& f) {
  num = (num * f.den) - (den * f.num);	 
  den = den * f.den; 
  semplifica();	
}

void Frazione::moltiplica(Frazione& f) {
  num = num * f.num;	 
  den = den * f.den; 
  semplifica();	
}

void Frazione::dividi(Frazione& f) {
  if ( f.num != 0 ) {
    num = num * f.den;	 
    den = den * f.num; 
    semplifica();	
  }
  else {
  	errDenominatoreZero();
  }
}

void Frazione::stampa() {
  // se il denominatore è negativo, lo rendo positivo e cambio il segno al numeratore
  // Esempio:  n=3 d=-2  , la frazione deve essere stampata come "-3/2" invece di "3/-2".
  if (den<0) {
  	den = -den;
  	num = -num;
  }
  if (den!=1) {
  	cout << num << "/" << den;
  }
  else {
  	cout << num ;  // quando il denominatore è 1 , non lo stampo.
  }  
}
	

void test() {
 	Frazione f1(2,3),f2(3,5);
 	
 	f1.somma(f2);  // dopo questa istruzione
 	               // f1 vale  (2/3 + 3/5) = 19/15 
					                
    f1.stampa();  // scrive 19/15	
}

int main() {
   cout << "\n Inserire le frazioni nel formato n/d. Premi 'q' per uscire. \n";
   char op;
   Frazione f1, f2;
   f1.input();
   do {
   	
	 op = inputOperazione();
     
     if (op!='q') {
		 f2.input();
		 switch(op) {
		 	case '+': f1.somma(f2); break;
		 	case '*': f1.moltiplica(f2); break;
		 	case '-': f1.sottrai(f2); break;
		 	case '/': f1.dividi(f2); break;
		 }  
		 cout << " Risultato: ";
		 f1.stampa();
		 cout << endl;
     }
   }
   while( op != 'q' );
   
   cout << "\n Fine. ";
}

char inputOperazione() {
	char op;
	do {
		cout << " Inserisci operazione: ";
		cin >> op;
		if ( !( op=='+' || op=='*' || op=='-' || op=='/' ) ) {
			cout << " Operazione non valida\n";
		}
	}
	while( !( op=='+' || op=='*' || op=='-' || op=='/' ) );
	return op;
}









