#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void clear()
{
	system("cls");
}

int main()
{
	int vetA[MAX], vetB[MAX];
	int A,B,i,j,lamp;

	do
	{
		printf("definire vettore A (minore di 100):\n");
		scanf("%d", &A);
		clear();	
	}while(A<=0 || A>MAX);
	
	do
	{
	printf("definire vettore B (minore di 100):\n");
		scanf("%d", &B);
		clear();
	}while(B<=0 || B>MAX);
	
	for(i=0;i<A;i++)
	{
		do
		{	
			printf("inserisci  nella cella [%d] per A:\n", i);
			scanf("%d", &vetA[i]);
			for(j=0;j<A;j++)
			{
				if(j==i)
				{
					j++;
				}
				
				while(vetA[i]==vetA[j])
				{
					printf("ha inserito il numero della cella %d, deve inserire di nuovo un numero:\n", j);
					scanf("%d", &vetA[i]);
				}
			}
			clear();
		}while(vetA[i]<0);
 	}
	
	for(i=0;i<B;i++)
	{
		do
		{
			printf("inserisci valori nella cella [%d] per B:\n", i);
			scanf("%d", &vetB[i]);
			for(j=0;j<B;j++)
			{
				if(j==i)
				{
					j++;
				}
				while(vetB[i]==vetB[j])
				{
					printf("ha inserito il numero della cella %d, deve inserire di nuovo un numero:\n", j);
					scanf("%d", &vetB[i]);	 
				}
			}
			clear();
		}while(vetB[i]<0);
	}
	
	printf("Unione: ");
	
	for(i=0;i<A;i++)
	{
		printf("%d ", vetA[i]);
	}
    
    for(i=0;i<B;i++)
    {
    	lamp=1;
    	for(j=0;j<A;j++)
		{
		 	if(vetB[i]==vetA[j]) 
		 	{
		 		lamp = 0; 
			}
		}
		
		if(lamp != 0)  
		{
			printf("%d ", vetB[i]);
		}
	}
	
	printf("\nIntesezione: ");
	
	for(i=0;i<B;i++)
	{
		lamp = 0; 
		for(j=0;j<A;j++)
		{
			if(vetB[i]==vetA[j])
			{
				lamp = 1; 
			}
		}
		
		if(lamp == 1) 
		{
			printf("%d ",vetB[i]);
		}
	}
	return 0;
}
