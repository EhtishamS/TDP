#include<stdio.h>

int main() {
	int n,i=0;
	
	do
	{	
	printf("dire il numero: ");
	scanf("%d",&n);
	}while(n<0);
	
	i=n--;
	
	while(i>=0)
	{
		printf("%d, ",i);
		i--;
	}
	
	printf("FINE!");
	
}
