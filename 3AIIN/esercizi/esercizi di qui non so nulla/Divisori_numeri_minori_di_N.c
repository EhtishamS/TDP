#include<stdio.h>

int input();
void output(int N);
void clear();

int main ()
{
	int N;
	
	N = input();
	output(N);
}

int input(){
	int N;
	
	do
	{
		printf("Dire il numero: ");
		scanf("%d", &N);
	}while(N<=1);
	
	return N;
}

void output (int N)
{
	int i, j;
	
	clear();
	
	for(i=1;i<=N;i++)
	{
		printf("I divisori di %d sono:", i);
		for(j=1;j<=N;j++)
		{
			if(i%j==0)
			{
				printf(" %d", j);
			}
		}
		printf("\n");
	}
}

void clear ()
{
	system("cls");
}
