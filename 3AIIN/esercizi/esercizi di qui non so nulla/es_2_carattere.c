#include<stdio.h>

int main(){
    unsigned char x;

    do{
        printf("Inserire in codice ASCII: ");
        scanf("%d", &x);
    }while(x<0 || x>255);

    printf("Il carattere ASCII stampato: %c", x);

    return 0;
}