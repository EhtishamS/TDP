#include<stdio.h>

int massacorp(float alt, float pes);

int main(){
	float alt, pes, mascorp;
	
	do{
		printf("inserire l'altezza in metri: ");
		scanf("%f", &alt);
	}while(alt<0);
	
	do{
		printf("inserire l'peso in chilogrammi: ");
		scanf("%f", &pes);
	}while(pes<0);
	
	mascorp = massacorp(alt, pes);
	
	printf("\naltezza corporea: %.1f m", alt);
	printf("\naltezza corporea: %f kg", pes);
	printf("\nIMC: %f kg / (%f m*%f m) = %f kg/m2", pes, alt, alt, mascorp);
	
	return 0;
}

int massacorp(float alt, float pes){
	float mascorp;
	mascorp = pes/(alt*alt);
	printf("\nmassa corpo: %f", mascorp);
	return mascorp;
}
