#include<stdio.h>

int main ()
{
	int N,i=1,s=0;
	
	do
	{
		printf("dire il numero: \n");
		scanf("%d",&N);
	}while(N<=0);
	
	for(i;i<=N;i++)
	{
		if(i==N)
		{
			printf("%d",i);
			s+=i;
		}
		else
		{
			printf("%d+",i);
			s+=i;
		}
	}
	printf("=%d",s);
}
