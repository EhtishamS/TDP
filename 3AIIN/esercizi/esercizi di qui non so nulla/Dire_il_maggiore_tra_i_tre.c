#include<stdio.h>
#define MAX 3

void ordina(int* a, int* b, int*c);

int main (){
	int num1, num2, num3;
	
	printf("Dire tre numeri: ");
	scanf("%d%d%d", &num1, &num2, &num3);
	
	ordina(&num1,&num2,&num3);
}

void ordina(int* a, int* b, int*c){
	int vet[]={*a,*b,*c}, i;
	
	for(i=0;i<MAX;i++){
		if(vet[i]>*c){
			*c=vet[i];
		} 
		if(vet[i]<*a){
			*a=vet[i];
		}
	}
	
	for(i=0;i<MAX;i++){
		if(vet[i]==*a || vet[i]==*c){
			vet[i]=0;
		} else {
			*b=vet[i];
		}
	}
	
	printf("\nmin: %d\nmed: %d\nmax:%d",*a,*b,*c);
}
