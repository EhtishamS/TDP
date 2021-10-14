#include<stdio.h>
#include<string.h>
#define MAX 100

int main(){
	char str[MAX];
	int i, lunghezza;
	
	do{
		printf("Inserire una stringa: ");
		scanf("%s", str);
		lunghezza = strlen(str);
	}while(lunghezza>MAX);
	
	for(i<0;i<lunghezza;i++){
		if(i%2==0){
			if(str[i]>='a' && str[i]<='z'){
				str[i]-=32;
			}
		} else {
			if(str[i]>='A' && str[i]<='Z'){
				str[i]+=32;
			}
		}
	}	
	
	printf("\nparola modificata: %s", str);
	return 0;
}
