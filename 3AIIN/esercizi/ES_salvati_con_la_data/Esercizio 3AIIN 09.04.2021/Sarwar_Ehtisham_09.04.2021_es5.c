/*
Modifica l'esercizio precendente (es4) in modo che ogni password generata contenga sempre:
	a. Almeno una lettera maiuscola
	b. Almeno una lettera minuscola
	c. Almeno una cifra
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
	int i, scelta;
	
	password[0]=rand()%25+65;
	password[1]=rand()%25+97;
	password[2]=rand()%9+48;
	
	for(i=3;i<lunghezza_password;i++){
		scelta = rand()%3;
		if(scelta == 0){
			password[i]=rand()%25+65;
		} else if(scelta == 1){
			password[i]=rand()%25+97;
		} else {
			password[i]=rand()%9+48;
		}
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
