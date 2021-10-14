/*
Utility Copia File. Si vuole realizzare un programma che consenta di duplicare N volte un file qualsiasi il cui nome è fornito dall'utente. Il file deve trovarsi nella 
cartella corrente del programma. Il valore di N è fornito dall'utente. Ad esempio, supponiamo che nella cartella del programma sia presente il file "prova.jpg", e 
l'utente fornisca il seguente input:
Nome file: prova.jpg
Numero copie: 10
Il programma deve generare nella cartella corrente 10 file identici, nominati  prova1.jpg,  prova2.jpg, ... prova10.jpg  tutti contenenti la stesa immagine.
*/

#include<stdio.h>
#include<string.h>

#define MAX 30+1
#define MAX_NUM 5
#define MAX_COPY 254

int controlloFile(char nomeFile[]);
void nCopie(char nome[], char estensione[], int N, char nomeFile[]);
void fileCopy(char nome[], int numFile, char nomeFile[], char estensione[]);
void numInCar(char num[], int N);
void creoFile(char nomeFile[], char customeName[]);

int main(){
    int N;
    char nomeFile[MAX], nome[MAX], estensione[MAX];
    FILE *inFile;
	
    printf("Inserire il nome del file con l'estensione: \n> ");
	scanf("%s", nomeFile);
	
	do{
		printf("Quante copie vuole fare del file: \n> ");
		scanf("%d", &N);
	}while(N<=0 || N>MAX_COPY);
	

    if(controlloFile(nomeFile)){
    	// per separare il nome dall'estensione (ho provato a farlo con la funzione ma dava un certo errore!)
        int lunghezza = strlen(nomeFile);
		int interruzione = 1, cont = 1, i, temp = lunghezza-1, contEstens = 0;
		
	    while(temp>0 && interruzione){
	        if(nomeFile[temp] == '.'){
	            interruzione = 0;
	        } else {
	            cont++;
	        }
	        temp--;
	    }
		
		for(i=0;i<lunghezza;i++){
			if(i>=lunghezza-cont){
				estensione[contEstens] = nomeFile[i];
				contEstens++;
			} else {
				nome[i] = nomeFile[i];
			}
		}
				
		nCopie(nome,estensione,N,nomeFile);
    } else {
        printf("Il file non esiste!");
    }
    return 0;
}

int controlloFile(char nomeFile[]){
    FILE* fp;

    fp = fopen(nomeFile, "r");

    if(fp!=NULL){
        fclose(fp);
        return 1;
    }

    return 0;
}

void nCopie(char nome[], char estensione[], int N, char nomeFile[]){
	int i;
	char temp[MAX];
	
	for(i=1;i<=N;i++){
		strcpy(temp,nome);
		fileCopy(temp, i, nomeFile, estensione);
		creoFile(nomeFile, temp);
	}
}

//aggiunge il numero e crea il nome nuovo da dare al file
void fileCopy(char nome[], int numFile, char nomeFile[], char estensione[]){
	char numCar[MAX_NUM] = "000";
	
	numInCar(numCar, numFile);	
	
	if(numFile>0 && numFile<10){	
		strcat(nome,&numCar[3]);
		strcat(nome,estensione);
	} else if(numFile>=10 && numFile<100){
		strcat(nome,&numCar[2]);
		strcat(nome,estensione);
	} else if(numFile>=100 && numFile <=254){
		strcat(nome,&numCar[1]);
		strcat(nome,estensione);
	}

}

//converte il numero in carattere
void numInCar(char num[], int N){
	
	if(N> 0 && N <=9){
		num[3] = N+'0';
	} else if(N >= 10 && N<=99){
		num[3] = (N%10)+'0';
		N /= 10;
		num[2] = N+'0';
	} else if (N >= 100 && N <= 999){
		num[3] = (N%10)+'0';
		N /=10;
		num[2] = (N%10)+'0';
		N /=10;
		num[1] = N+'0';
	}
}

//crea il file con il nuovo nome ma anche il suo contenuto
void creoFile(char nomeFile[], char customeName[]){
	char car;
	FILE *fileDaCopiare, *fileNuovo;
	
	fileDaCopiare = fopen(nomeFile, "rb");
	fileNuovo = fopen(customeName, "wb");
	
	if(fileDaCopiare != NULL && fileNuovo != NULL ){
		fread(&car, sizeof(car), 1, fileDaCopiare);
		while(!feof(fileDaCopiare)){
			fwrite(&car,sizeof(car),1,fileNuovo);
			fread(&car, sizeof(car),1,fileDaCopiare);
		}
	} else {
		printf("Impossibile aprire i file!");
	}
}

