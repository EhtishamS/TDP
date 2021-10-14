#include<stdio.h>

int main (){
    unsigned char x;

    do{
        printf("Inserire un carattere: ");
        scanf("%c", &x);
    }while(x<0 || x >255);

    printf("Il codice ASCII del carattere inserito e' il seguente: %d", x);

    return 0;
}