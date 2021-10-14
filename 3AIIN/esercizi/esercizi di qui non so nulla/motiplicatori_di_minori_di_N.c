#include<stdio.h>
#include<math.h>
#define MAX 15

void output(int N);
void clear();

int main()
{
	int N;
	
	do
	{
		printf("Inserire un numero (numero<=15): ");
		scanf("%d", &N);
	}while(N<=1 || N>MAX);
	
	output(N);
}

void output(int N)
{
	long long int  x;
	int i, j;
	clear();
	
	for(i=1;i<=N;i++)
	{
		x=x*x;
		printf("%d^%d = %lld\n", i, i, x);
	}
}

void clear()
{
	system("cls");
}
