#include <stdio.h>

int main()
{
	int k,n,i=1,m;
	
	printf("dire il numero: ");
	scanf("%d",&n);
	printf("quanti multipli vuole: ");
	scanf("%d",&k);
	
	for(i;i<=k;i++)
	{
		m=n*i;
		printf("%d x %d = %d \n",n,i,m);
	}
}
