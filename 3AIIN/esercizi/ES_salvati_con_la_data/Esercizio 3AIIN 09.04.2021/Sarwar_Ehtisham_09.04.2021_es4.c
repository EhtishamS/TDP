/*
Generare un file di password casuali, in formato CSV con la seguente struttura: 

utente;password;
u0001;USKEL
u0002;SLMDO
u0003;QODGE

Il programma richiede all'utente:
	- Nome del file da generare. Se il file esiste già occorre avvertire l'utenza.
	- Numero di password da inserire nel file.
	- Lunghezza della password. Tutte le password avranno la stessa lunghezza e la lunghezza minima è 4

Ogni password è composta exclusivamente da lettere maiuscole. Il file di esempio è stato
generato con: un numero_password = 3, lunghezza_password = 5.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

#define NOME_FILE 20+1
#define CON_EXTENTION 25+1
#define PASS_MAX 100
#define EXTENTION ".csv"
#define MAX 4+1

void generaPassword(char password[], int lunghezza_password);
int controlloFile(char nomeFile[]);
void cont(char vet[]);
void writeFile(char nomeFile[],char vet[], char password[], int numero_password, int lunghezza_password);

int main(){
	int numero_password, lunghezza_password;
	char nomeFile[NOME_FILE], vet[MAX] = "0000", password[PASS_MAX];
	
	srand(time(NULL));
	
	do{
		printf("Come vuoi chiamare il nome del file: ");
		scanf("%s", nomeFile);
	}while(strlen(nomeFile)<=0 || strlen(nomeFile)>(NOME_FILE-4));
	
	do{
		printf("Quante password voi generare: ");
		scanf("%d", &numero_password);
		printf("Quanto deve lunga una password: ");
		scanf("%d", &lunghezza_password);
	}while(numero_password<=0 || lunghezza_password<4);

	strcat(nomeFile,EXTENTION);

	if(controlloFile(nomeFile)){
		printf("\nEsiste gia' un file con lo stesso nome!");
		writeFile(nomeFile,vet,password,numero_password,lunghezza_password);
	} else {
		writeFile(nomeFile,vet,password,numero_password,lunghezza_password);
	}
	return 0;
}

void generaPassword(char password[], int lunghezza_password){
	int i;
	
	for(i=0;i<lunghezza_password;i++){
		password[i]=rand()%25+65;
	}	
	
}

int controlloFile(char nomeFile[]){
	
	FILE *fp = fopen (nomeFile, "r");
	
	if(fp!=NULL){
		fclose(fp);
		return 1;
	} else {
		return 0;
	}
}

void cont(char vet[]){
	int i;
	
	if(vet[3]<='9'){
		if(vet[3]=='9'){
			vet[2]++;
			vet[3] = '0';
		} else {
			vet[3]++;
		}
	} else if(vet[2] == '9'){
		vet[1]++;
		vet[2]= '0';
	} else if(vet[1] == '9'){
		vet[0]++;
		vet[1]='0';
	} else if(vet[0] == '9'){
		vet[3]='0';
		vet[2]='0';
		vet[1]='0';
		vet[0]='0';
	}
}

void writeFile(char nomeFile[],char vet[], char password[], int numero_password, int lunghezza_password){
	int i;
	FILE *fp = fopen(nomeFile, "w");
		fprintf(fp,"utente;password\n");
		if(fp!=NULL){
			for(i=0;i<numero_password;i++){
				generaPassword(password, lunghezza_password);
				cont(vet);
				fprintf(fp,"u%s;%s\n",vet,password);
			}
			fclose(fp);
			printf("\nfile creato con successo!");
		} else {
			printf("\nOps si e' verificato un errore!");
		}
}
