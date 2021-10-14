#include<stdio.h>

int main (){
    char x;

    printf("Inserire un carattere: ");
    scanf("%c", &x);

    x++;

    printf("Il carattere successivo e': %c", x);
    return 0;
}