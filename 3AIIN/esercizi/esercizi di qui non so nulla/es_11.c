#include<stdio.h>
#include<string.h>
#define MAX 100
int main (){
    char strvet[MAX], prima[MAX], dopo[MAX];
    int N, i;

    do{
        printf("Quante parole voi inserire: ");
        scanf("%d", &N);
    } while(N<=0);

    for(i=0;i<N;i++){
        printf("Inserire la parola [%d]: ", i);
        scanf("%s", strvet);
        if(i==0){
            strcpy(dopo, strvet);
            strcpy(prima, strvet);
        } 

        if(strvet[0]<prima[0]){
            strcpy(prima, strvet);
        }        

        if(strvet[0]>dopo[0]){
            strcpy(dopo, strvet);
        }
    }

    printf("La prima parola in ordine alfabetico, e' %s \nL'ultima parola, in ordina alfabetico, e' %s", prima, dopo);

    return 0;
}
