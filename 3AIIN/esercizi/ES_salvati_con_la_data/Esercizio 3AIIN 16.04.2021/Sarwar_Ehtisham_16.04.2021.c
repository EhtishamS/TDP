#include<stdio.h>
#include<string.h>

#define MAX_STR 20+1
#define MAX_BARCHE 30
#define LUNG_MIN 4
#define NOME_FILE 30+1
#define FORMATO ".csv"

typedef struct {
	char codiceNatante[MAX_STR];
	char proprietario[MAX_STR];
	double lunghezza;
	char provenienza[MAX_STR];
}informazione;

int menu();
void inizializza(informazione infoBarche[]);
void stampaBarcheDiLunghezzaData(informazione infoBarche[]);
void registrazioneDati(informazione infoBarche[], int *numBarche);
int controlloLunghezza(informazione infoBarche[]);
void salvataggioFile(informazione infoBarche[], int numBarche, char nomeFile[]);
informazione input(informazione infoBarca);

int main(){
	informazione infoBarche[MAX_BARCHE];
	int scelta, numBarche = 0;
	char nomeFile[MAX_STR];
	
	printf("Inserire il nome del File: ");
	scanf("%s", nomeFile);
	strcat(nomeFile,FORMATO);
	
	inizializza(infoBarche);
	
	do{
		scelta = menu();
		
		switch(scelta){
			case 1:
				stampaBarcheDiLunghezzaData(infoBarche);
				break;
			case 2:
				registrazioneDati(infoBarche,&numBarche);
				break;
			case 3:
				salvataggioFile(infoBarche,numBarche,nomeFile);
				break;
		}
	}while(scelta!=0);
	
	return 0;
}

int menu(){
	int scelta;
	
	do{
		printf("\n\n1. Stampare l'elenco delle barche superiori alla lunghezza data.");
		printf("\n2. Registrare i dati delle barche.");
		printf("\n3. Salvare tutto nel file csv");
		printf("\n0. Exit");
		printf("\nScegliere uno di questi: \n> ");
		scanf("%d", &scelta);
	}while(scelta<0 || scelta>3);
	
	return scelta;
}

void inizializza(informazione infoBarche[]){
	int i;
	
	for(i=0;i<MAX_BARCHE;i++){
		strcpy(infoBarche[i].codiceNatante,"None");
		strcpy(infoBarche[i].proprietario,"None");
		infoBarche[i].lunghezza = 0;
		strcpy(infoBarche[i].provenienza,"None");
	}
}

void stampaBarcheDiLunghezzaData(informazione infoBarche[]){
	double lunghezza;
	int i;
	
	do{
		printf("\nInserire la lunghezza: ");
		scanf("%lf", &lunghezza);		
	}while(lunghezza<=0);
	
	for(i=0;i<MAX_BARCHE;i++){
		if(infoBarche[i].lunghezza >= lunghezza && infoBarche[i].lunghezza!=0){
			printf("\n\nBarca [%d]", i+1);
			printf("\nCodice Natante: %s", infoBarche[i].codiceNatante);
			printf("\nProprietario: %s", infoBarche[i].proprietario);
			printf("\nLunghezza: %lf", infoBarche[i].lunghezza);
			printf("\nProvenienza: %s", infoBarche[i].provenienza);
		}
	}
}

void registrazioneDati(informazione infoBarche[], int *numBarche){
	double lenght;
	int controllo=-1;
	
	if(*numBarche<MAX_BARCHE){
		printf("\nInserire la lunghezza della barca: ");
		scanf("%lf", &lenght);
		while(getchar() != '\n');
		
		if(lenght<=LUNG_MIN){
			controllo = controlloLunghezza(infoBarche);
			if(controllo!=-2){
				infoBarche[controllo].lunghezza = lenght;
				infoBarche[controllo] = input(infoBarche[controllo]);

				printf("\nInserimento andato a buonfine!");
			} else if (controllo==-2 && *numBarche+((MAX_BARCHE-1)/2)<MAX_BARCHE){
				printf("\nPosto Finito per le barche minori di 4 metri, inserisco i dati nella seconda parte!\n\n");
				infoBarche[*numBarche+((MAX_BARCHE-1)/2)].lunghezza = lenght;
				infoBarche[*numBarche+((MAX_BARCHE-1)/2)] = input(infoBarche[*numBarche+((MAX_BARCHE-1)/2)]);
				
				*numBarche +=1;
			}
		} else if (*numBarche+((MAX_BARCHE-1)/2)<MAX_BARCHE) { 
			infoBarche[*numBarche+(MAX_BARCHE/2)].lunghezza = lenght;
			infoBarche[*numBarche+(MAX_BARCHE/2)] = input(infoBarche[*numBarche+(MAX_BARCHE/2)]);		

			printf("\nInserimento andato a buonfine!");
			*numBarche += 1;
		}
	} else{
		printf("\nAbbiamo finito lo spazio per inserire i dati!");
	}
}

int controlloLunghezza(informazione infoBarche[]){
	int i;
	for(i=0;i<MAX_BARCHE/2;i++){
		if(infoBarche[i].lunghezza == 0){
			return i;
		}
	}
	return -2;
}

void salvataggioFile(informazione infoBarche[], int numBarche, char nomeFile[]){
	int i;
		
	FILE *fp;
	
	fp = fopen(nomeFile, "w");
	
	if(fp!=NULL){
		fprintf(fp,"Codice Natante; Proprietario; Lunghezza; Provenienza;");
		for(i=0;i<MAX_BARCHE;i++){
			if(infoBarche[i].lunghezza != 0){
				fprintf(fp,"\n%s;%s;%.2lf;%s", infoBarche[i].codiceNatante,infoBarche[i].proprietario, infoBarche[i].lunghezza,infoBarche[i].provenienza);
			}
		}
		fclose(fp);
		printf("\nSalvataggio eseguito!");
	} else {
		printf("\nNon si e' riuscito ad aprire il file!");
	}
}

informazione input(informazione infoBarca){
	printf("Inserire il Codice Natante: ");
	gets(infoBarca.codiceNatante);
	printf("Inserire il nome del proprietario: ");
	gets(infoBarca.proprietario);
	printf("Inserire la provenienza della barca: ");
	gets(infoBarca.provenienza);
	
	return infoBarca;
}

