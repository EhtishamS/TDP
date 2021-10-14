#include<stdio.h>

int main (){
	unsigned char minuscolo;
	
	do{
		printf("Inserire un carattere in minuscolo: ");
		scanf("%c", &minuscolo);
	}while(minuscolo<'a' || minuscolo>'z');

	minuscolo-=32;
	printf("Il inserito corrisponde a: %c", minuscolo);
	
	return 0;
}
