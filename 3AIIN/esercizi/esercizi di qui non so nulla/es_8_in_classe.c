#include<stdio.h>
#define MAX 50

int main()
{
	int vet[MAX], i, N, j, cont=2, freq=0;
	
	do
	{
		printf("Quanti voti vuoi inserire? ");
		scanf("%d", &N);
	}while(N>MAX || N<=0);
	
	printf("Inserisci i voti: ");
	
	for(i=0;i<N;i++)
	{
		do
		{
			scanf("%d", &vet[i]);
		}while(vet[i]<2 || vet[i]>10);
	}
	
	printf("OUTPUT:\n");
	
	for(i=0;i<=8;i++)
	{	
		for(j=0;j<N;j++)
		{	
			if(vet[j]==cont)
			{
				freq++;
			}
		}
		printf("Voto=%d Freq=%d\n", cont, freq);
		freq=0;
		cont++;
	}
	return 0;
	
}
