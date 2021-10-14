#include<iostream>

using namespace std;

class Orario{
	private:
		int hh;
		int mm;
		int ss;
		
		bool valido();
	public:
		Orario();
		Orario(int hours, int minutes, int seconds);
		
		void setHour(int hour);
		void setMinute(int minutes);
		void setSecond(int seconds);
		
		int getHour();
		int getMinutes();
		int getSeconds();
		
		void acquisisci();
		void stampa();
		void avanza(int n);
		int confronto(Orario &o2);
		int differenza(Orario &o2);
};

int main(){
	Orario hour;
	int n;
	bool valid;
	
	hour.acquisisci();
	hour.stampa();
	
	do{
		cout<<"\nInserire i secondi che vuole aggiungere all'orario: ";
		
		valid = true;
		
		if(!(cin>>n)){
			cout<<"Inserire un numero!";
			valid = false;
			cin.clear();
			while(cin.get()!='\n');
			continue;
		}
		
		if(n<0){
			cout<<"Inserire un numero positivo o nullo!";
			valid = false;
		}
	}while(!valid);
	
	hour.avanza(n);
	hour.stampa();
	
	return 0;
}

Orario::Orario(){
	hh = 0;
	mm = 0;
	ss = 0;
}

Orario::Orario(int hours, int minutes, int seconds){
	hh = hours;
	mm = minutes;
	ss = seconds;
	
	if(!valido()){
		cout<<"This time is invalid!";
		hh = 0;
		mm = 0;
		ss = 0;
	} 
}


bool Orario::valido(){
	if(hh>=0 && hh<=23){
		if(mm>=0 && mm<=59){
			if(ss>=0 && ss<=59){
				return true;
			}
		}
	}
	
	return false;
}

void Orario::setHour(int hour){
	if(hour>=0 && hour<= 23){
		hh = hour;
	} else {
		cout<<"\nThe inserted hour is invalid!";
	}
}

void Orario::setMinute(int minutes){
	if(minutes>=0 && minutes<=59){
		mm = minutes;
	} else{
		cout<<"The inserted minutes are invalid";
	}
}

void Orario::setSecond(int seconds){
	if(seconds>=0 && seconds<=59){
		ss = seconds;
	} else{
		cout<<"The inserted seconds are invalid";
	}
}

int Orario::getHour(){
	return hh;
}

int Orario::getMinutes(){
	return mm;
}

int Orario::getSeconds(){
	return ss;
}

void Orario::acquisisci(){
	bool valid;
	char c;
	
	do{
		cout<<"\nInserire un orario: ";
		
		valid = true;
		
		if(!(cin>>hh)){
			cout<<"\nInserire un numero!";
			valid=false;
			cin.clear(); // resetta il valore della cin per leggere altri valori.
			while(cin.get()!='\n');
			continue;
		}
		
		c = cin.get(); // consumo i caratteri " " o "\n"
		while(c==' ' || c=='\n'){
			c = cin.get();
		}
		
		
		if(c!=':'){
			cout<<"\nDeve separare l'ora dai minuti tramite \":\"";
			valid = false;
			while(cin.get()!='\n');
			continue;
		}
		
		if(!(cin>>mm)){
			cout<<"\nInserire un numero!";
			valid=false;
			cin.clear();
			while(cin.get()!='\n');
			continue;
		}
		
		c = cin.get(); // consumo i caratteri " " o "\n"
		while(c==' ' || c=='\n'){
			c = cin.get();
		}
		
		
		if(c!=':'){
			cout<<"\nDeve separare i minuti dai secondi tramite \":\"";
			valid = false;
			while(cin.get()!='\n');
			continue;
		}
		
		if(!(cin>>ss)){
			cout<<"\nInserire un numero!";
			valid=false;
			cin.clear();
			while(cin.get()!='\n');
			continue;
		}
		
		
		
	}while(!valid || !valido());
}

void Orario::stampa(){
	if(hh<10)
		cout<<"0"<<hh<<"h:";
	else 
		cout<<hh<<"h:";	
	
	if(mm<10)
		cout<<"0"<<mm<<"m:";
	else 
		cout<<mm<<"m:";
	
	if(ss<10)
		cout<<"0"<<ss<<"s";
	else 
		cout<<ss<<"s";
}

void Orario::avanza(int n){
	int cont = 0;
	ss += n;
	
	while(ss>59){
		ss-=60;
		cont++;
	}
	
	mm += cont;
	
	cont=0;
	while(mm>59){
		mm-=60;
		cont++;
	}
	
	hh +=cont;
	
	cont=0;
	
	while(hh>23){
		hh-=24;
	}
}

int Orario::confronto(Orario &o2){
	if(hh > o2.getHour() && mm > o2.getMinutes() && ss > o2.getSeconds())
		return 1;
	else if(hh == o2.getHour() && mm == o2.getMinutes() && ss == o2.getSeconds())
		return 0;
	
	return -1;
}

int Orario::differenza(Orario &o2){
	int ris = confronto(o2);
	
	if(ris == 0)
		return 0;
	else if(ris>0){
		int hour = hh-o2.getHour();
		int minutes = (mm-o2.getMinutes()) + (hour*60);
		int seconds = (ss-o2.getSeconds()) + (minutes*60);
		
		return seconds; 
	} else {
		int hour = o2.getHour()-hh;
		int minutes = (o2.getMinutes()-mm) + (hour*60);
		int seconds = (o2.getSeconds()-ss) + (minutes*60);
		
		return seconds; 
	}
}
