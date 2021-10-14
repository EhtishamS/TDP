#include<stdio.h>

void massacorp (float alt, float pes);
void cls();

int main()
{
	float alt, pes;
	
	do
	{
		printf("inserire l'altezza: ");
		scanf("%f", &alt);
	}while(alt<0);
	
	do
	{
		printf("inserire il peso: ");
		scanf("%f", &pes);
	}while(pes<0);
	
	massacorp(alt, pes);
}

void massacorp (float alt, float pes)
{
	float massa;
	
	massa = pes/(alt*alt);
	clear();
	printf("altezza corporea = %.2f\n", alt);
	printf("peso corporeo = %.0f\n", pes);
	printf("IMC = %.0f kg/( %.2f m* %.2f m) = %.0f kg/%.2f m2 = %.2f kg/m2", pes, alt, alt, pes, alt, massa);
	
}

clear()
{
	system("cls");
}
