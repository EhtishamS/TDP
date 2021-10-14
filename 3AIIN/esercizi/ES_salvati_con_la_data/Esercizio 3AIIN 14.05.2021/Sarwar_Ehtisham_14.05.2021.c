#include<stdio.h>

#define INFILE "input.txt"
#define OUTFILE "output.txt"


int main(){
	FILE *fp1, *fp2;
	char car;
	
	fp1 = fopen(INFILE, "rb");
	fp2 = fopen(OUTFILE, "wb");
	
	if(fp1 != NULL && fp2 != NULL){
		fread(&car,sizeof(char),1,fp1);
		while(!feof(fp1)){
			if(car != '\r'){
				fwrite(&car, sizeof(char),1,fp2);
			}
			fread(&car,sizeof(char),1,fp1);
		}
		fclose(fp1);
		fclose(fp2);
		printf("\nConversione completata!");
	} else{
		printf("Impossible aprire i file!");
	}
	return 0;
}
