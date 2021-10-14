#include<stdio.h>
#define MAX 100
#define NOMEFILE "output.bin"

int main(){
	int N, num, i=0;
	FILE *fp;
	
	do{
		printf("Quanti numeri vuole inserire: ");
		scanf("%d", &N);
	}while(N<=0 || N>MAX);
	
	fp = fopen(NOMEFILE, "wb");
	
	if(fp!=NULL){
		while(i<N){
			printf("Inserire il numero: ");
			scanf("%d", &num);
			fwrite(&num,sizeof(num),1,fp);
			i++;
		}
		fclose(fp);
	} else {
		printf("Impossibile creare il file!");
	}
	
	fp = fopen(NOMEFILE, "rb");
	
	if(fp!=NULL){
		fread(&num,sizeof(num), 1, fp);
		while(!feof(fp)){
			printf("\nHo letto questo numero: %d", num);
			fread(&num,sizeof(num), 1, fp);
		}
		fclose(fp);
	} else {
		printf("Apertura del file non riuscita!");
	}
	
	return 0;
}
