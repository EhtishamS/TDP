#include<stdio.h>
#include<math.h>

struct equazione{
    int a, b, c, ris;
};

struct equazione delta (struct equazione d);
void delta_positivo(int a, int b, int ris, int* x1, int* x2, int* flag);
float type(int rad, float* del);


int main (){
    struct equazione eq;
    int x1, x2, flag;

    printf("Inserire l'equazione di grado 2 in questo formato (a b c): ");
    scanf("%d" "%d" "%d", &eq.a, &eq.b, &eq.c);

    eq = delta(eq);
    delta_positivo(eq.a, eq.b, eq.ris, &x1, &x2, &flag);

    if(flag == 0){
        printf("\nil X1 e' uguale a: %d+ -/%d", x1, eq.ris);
        printf("\nil X2 e' uguale a: %d- -/%d", x2, eq.ris);
    } else if(flag == 1){
        printf("\nil X1 e' uguale a: (%d+ -/%d)/%d", eq.b, eq.ris, eq.a);
        printf("\nil X2 e' uguale a: (%d- -/%d)/%d", eq.b, eq.ris, eq.a);
    } else if (flag == 2){
        printf("\nil X1 e' uguale a: %d", x1);
        printf("\nil X2 e' uguale a: %d", x2);
    } else if (flag == 3){
        printf("\nil X1 e' uguale a: %d", x1);
        printf("\nil X2 e' uguale a: %d/%d", x2,eq.a);
    } else {
        printf("\nil X1 e' uguale a: %d", x1);
        printf("\nil X2 e' uguale a: %d", x2);
    }


    return 0;
}

struct equazione delta (struct equazione d){
    d.ris = (d.b*d.b) - 4*(d.a)*(d.c);
    printf("delta: %d", d.ris);
    return d;
}

float type(int rad, float* del){
    float radice_d, radice_i, fine, temp;
    int intera; 

    temp=rad;
    radice_d = sqrt(temp);
    intera = radice_d;
    radice_i = intera;
    fine = radice_i - radice_d;
    *del = radice_d;

    return fine;
}



void delta_positivo(int a, int b, int ris, int* x1, int* x2, int* flag){
    float prod_fine, radice_delta;

    prod_fine = type (ris, &radice_delta);

    float X1, X2, cont1, cont2;
    int temp1, temp2, somma1, somma2, rest;
  
    b=b*-1;
    a=2*a;

    if(prod_fine==0){
        X1 = (b+radice_delta)/a;
        X2 = (b-radice_delta)/a;
        
        temp1 = X1;
        temp2 = X2; 

        cont1 = temp1 - X1;
        cont2 = temp2 - X2;
        somma1 = b+radice_delta;
        somma2 = b-radice_delta;
        
        if(cont1==0 && cont2==0){
            *flag == 2;
            *x1 = temp1;
            *x2 = temp2;
        } else if(cont1==0 && cont2!=0) {
            *flag == 3;
            *x1 = temp1;
            *x2 = somma2;
        } else {
            *x1 = somma1;
            *x2 = temp2;
        }
    } else {
        if(b%a==0){
            *flag = 0;
            rest = b/a;
            *x1 = rest;
            *x2 = rest;
        } else{
            *flag = 1;
        }
    }
}