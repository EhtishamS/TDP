#include<stdio.h>
#include<string.h>

#define MAX_NOME 20+1
#define MAX_BIRRE 50
#define MAX_TEST 80+1
#define TIPO_MAX 6+1

typedef struct{
    char nome[MAX_NOME];
    int tipo;
    double prezzo;
}Birreria;

void InsertBirre(Birreria birra[], int numBirre);
void stampaBirre(Birreria birra[], int numBirre); // A
void stampaBirra(Birreria birra);
void birraPiuMenoCara(Birreria birra[], int numBirre); // B
void nomeBirra(Birreria birra[], char nomeBirra[], int numBirre); //C
void stampaTipi(Birreria birra[], int numBirre); // D
void convertitore(char nome[]);
void sortPerPrezzo(Birreria birra[], int numBirre);
int menu();


int main(){
    Birreria birra[MAX_BIRRE];
    int numBirre, scelta;
    char nomeDrink[MAX_NOME], test[MAX_TEST];
    
    do{
    	scelta = menu();
    	switch(scelta){
    		case 1:
				do{
        			printf("Quante birre vuole inserire: ");
        			scanf("%d", &numBirre);
    			}while(numBirre<=0 || numBirre>MAX_BIRRE);
    			InsertBirre(birra,numBirre);
    			sortPerPrezzo(birra, numBirre);
    			break;
    		case 2:
    			stampaBirre(birra, numBirre);
    			break;
    		case 3:
    			birraPiuMenoCara(birra,numBirre); 
    			break;
    		case 4:
    			do{
			    	while(getchar()!='\n');
			        printf("Inserire il nome della birra: ");
			        gets(test);
			    }while(strlen(test)>MAX_NOME);
			    strcpy(nomeDrink,test);
			    nomeBirra(birra,nomeDrink,numBirre);
			    break;
    		case 5:
    			stampaTipi(birra, numBirre);
    			break;
		}
	}while(scelta!=0);
    
    return 0;
}

void InsertBirre(Birreria birra[], int numBirre){
    int i;
    char test[MAX_TEST];
    
    for(i=0;i<numBirre;i++){
        printf("\nBirra [%d]\n", i+1);
        while(getchar()!='\n');
        do{
            printf("Inserire il nome della birra (<20): \n>");
            gets(test);
        }while(strlen(test)>MAX_BIRRE);
        strcpy(birra[i].nome,test);
	 	
		convertitore(birra[i].nome);
	 	
        do{
            printf("\nInserire il tipo di birra: \n");
            printf("1 Chiara\n");
            printf("2 Scura\n");
            printf("3 Rossa\n");
            printf("4 Ale\n");
            printf("5 Doppio malto\n");
            printf("6 Weiss\n\n");
            printf("Inserire uno di questi: \n>");
            scanf("%d", &birra[i].tipo);
        }while(birra[i].tipo<=0 || birra[i].tipo>6);

        printf("Inserire il prezzo della birra: \n>");
        scanf("%lf", &birra[i].prezzo);
    }
}

void convertitore(char nome[]){
	int i;
	
	for(i=0;nome[i]!= '\0';i++){
		if(nome[i]>='a' && nome[i]<='z'){
			nome[i]=nome[i]-32;
		}
	}
}

void stampaBirre(Birreria birra[], int numBirre){
    int i;

    printf("\n");

    for(i=0; i<numBirre; i++){
        printf("\nBirra [%d]\n", i+1);
        stampaBirra(birra[i]);
        printf("\n\n");
    }
}

void stampaBirra(Birreria birra){
    printf("Nome: %s", birra.nome);
    switch(birra.tipo){
        case 1: 
            printf("\nTipo: Chiara");
            break;
        case 2: 
             printf("\nTipo: Scura");
            break;
        case 3: 
            printf("\nTipo: Rossa");
            break;
        case 4:
            printf("\nTipo: Ale");
            break;
        case 5:
            printf("\nTipo: Doppio malto");
            break;
        case 6:
            printf("\nTipo: Weiss");
            break;
    }
    printf("\nPrezzo: %.2lf euro\n", birra.prezzo);
}

void birraPiuMenoCara(Birreria birra[], int numBirre){
    printf("La Birra piu cara: \n");
    stampaBirra(birra[0]);
    printf("\n\nLa Birra meno cara: \n");
    stampaBirra(birra[numBirre-1]);
}

void nomeBirra(Birreria birra[], char nomeBirra[], int numBirre){
    int i, j, non_trovato, lunghezza;

    for(i=0;i<numBirre;i++){
        if(strcmp(nomeBirra,birra[i].nome)==0){
            printf("\n\nLa birra ricercata: \n");
            stampaBirra(birra[i]);
            break;
        }
    }
}

void stampaTipi(Birreria birra[], int numBirre){
	int i;
	int contTipi[TIPO_MAX];
	
	for(i=0;i<TIPO_MAX;i++){
		contTipi[i]=0;
	}

	for(i=0;i<numBirre;i++){
		contTipi[birra[i].tipo]++;
	}
	
	printf("\nChiara: %d", contTipi[1]);
	printf("\nScura: %d", contTipi[2]);
	printf("\nRossa: %d", contTipi[3]);
	printf("\nAle: %d", contTipi[4]);
	printf("\nDoppio malto: %d", contTipi[5]);
	printf("\nWeiss: %d", contTipi[6]);
}

int menu(){
	int scelta;
	do{
		printf("\n\n");
		printf("\n1 Inserire i dati");
		printf("\n2 Stampare elenco birre");
		printf("\n3 visualizzare la birra pi costosa e quella meno costosa");
		printf("\n4 Cercare una birra");
		printf("\n5 Guadare i tipi");
		printf("\n0 Fine lavoro\n\n");
		printf("Inserire una scelta: \n>");
		scanf("%d", &scelta);
	}while(scelta<0 || scelta>5);
	return scelta;
}

void sortPerPrezzo(Birreria birra[], int numBirre){
	int i, j;
	Birreria temp;
	
	for(i=0;i<numBirre-1;i++){
		for(j=i;j<numBirre;j++){
			if(birra[j].prezzo<birra[i].prezzo){
				temp = birra[j];
				birra[j] = birra[i];
				birra[i] = temp;
			}
		}	
	}
}
