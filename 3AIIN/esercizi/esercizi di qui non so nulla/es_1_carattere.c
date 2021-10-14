#include<stdio.h>

int main (){
    unsigned char x;

    do{
        printf("Inserire un codice ascii: ");
        scanf("%d", &x);
    } while(x<0 || x>255);

    if(x>=48 && x<58){
        printf("Il carattere inserito e' un numero!");
    } else if((x>=65 && x<91) || (x>=97 && x<123)){
        if(x == 65 || x == 97 || x == 69 || x == 101 || x == 73 || x == 105 || x == 79 || x == 111 || x == 85 || x == 117 ){
            printf("Il carattere inserito e' una vocale!");
        } else {
            printf("Il carattere inserito e' una consonante!");
        } 
    } else {
        printf("Il carattere inserito e' un'altro simbolo!");
    }

    return 0;
}