#include<stdio.h>

// struttura
struct data {
    int a, m, g, maxg, b;
};

//prototipi
int bisestile (int anno);
int valida (struct data d);
void prossima_data(struct data next);
int maxgiorni(struct data max);
int confronto(struct data d1, struct data d2);
void aggdata(struct data data1);
void stampadata(struct data stamp);
int differenza(struct data data1, struct data data2);


int main (){
    int ris;

    //data valida;
    struct data valid;

    printf("Inserire una data (gg mm aaaa): ");
    scanf("%d" "%d" "%d", &valid.g, &valid.m, &valid.a);

    ris = valida(valid);

    if(ris==1){
        printf("Data valida!");
        printf("\n");
    } else {
        printf("Data non valida!");
        printf("\n");
    }

    //prossima data
    struct data pros;

    printf("\nInserire la data (gg mm aaaa): ");
    scanf("%d" "%d" "%d", &pros.g, &pros.m, &pros.a);

    prossima_data(pros);

    //confronto
    struct data conf1, conf2;

    printf("\nInserire prima data (gg mm aaaa): ");
    scanf("%d" "%d" "%d", &conf1.g, &conf1.m, &conf1.a);

    printf("Inserire seconda data (gg mm aaaa): ");
    scanf("%d" "%d" "%d", &conf2.g, &conf2.m, &conf2.a);

    ris = confronto(conf1, conf2);

    if(ris==2){
        printf("Una delle due e' sbagliato, confronto non e' possibile!");
        printf("\n");
    } else if (ris==0){
        printf("Le data sono uguali!");
        printf("\n");
    } else if(ris==1){
        printf("Le date sono in ordine crescente!");
        printf("\n");
    } else {
        printf("Le date sono in ordine decrescente!");
        printf("\n");
    }
    
    //aggungi giorni
    struct data agg;

    printf("\nInserire una data (gg mm aaaa): ");
    scanf("%d" "%d" "%d", &agg.g, &agg.m, &agg.a);

    aggdata(agg);

    //stampa data
    struct data date;

    printf("\nInserire una data (gg mm aaaa): ");
    scanf("%d" "%d" "%d", &date.g, &date.m, &date.a);

    stampadata(date);

    //differenza giorni
    struct data diff1, diff2;

    printf("\nInserire la prima data (gg mm aaaa): ");
    scanf("%d" "%d" "%d", &diff1.g, &diff1.m, &diff1.a);
    printf("Inserire la seconda data (gg mm aaaa): ");
    scanf("%d" "%d" "%d", &diff2.g, &diff2.m, &diff2.a);

    ris = differenza(diff1, diff2);

    if(ris==0){
        if(diff1.g==diff2.g && diff1.m==diff2.m && diff1.a==diff2.a){
            printf("Le date sono uguali");
        } else {
            printf("Una delle due data sbagliata!");    
        }
    }  else if(ris<0){
        printf("La differenza di giorni tra %d/%d/%d e %d/%d/%d e' uguale: %d", diff1.g, diff1.m, diff1.a, diff2.g, diff2.m, diff2.a, ris);
    } else {
        printf("La differenza di giorni tra %d/%d/%d e %d/%d/%d e' uguale: %d", diff1.g, diff1.m, diff1.a, diff2.g, diff2.m, diff2.a, ris);
    }

    return 0;
}

// funzioni

int maxgiorni(struct data max){
    
    max.b = bisestile(max.a);
    if(max.m == 1 || max.m == 3 || max.m == 5 || max.m == 7 || max.m == 8 || max.m == 10 || max.m == 12){
        max.maxg=31;
    } else if (max.m==2){
        if(max.b==1){
            max.maxg=29;
        } else {
            max.maxg=28;
        }
    } else {
        max.maxg=30;
    }
     
    return max.maxg;
}

int bisestile(int anno) { 
	if (anno % 400 == 0 || (anno % 100 != 0 && anno % 4 == 0))   
		return 1;  
	else    
		return 0;
}

int valida(struct data d){

    int ris;
    d.b= bisestile(d.a);
    d.maxg=maxgiorni(d);

    if(d.a>0){
        if(d.m>0 && d.m<=12){
            if(d.g>0 || d.g<=d.maxg){
                ris=1;
            } else {
                ris=0;
            }
        } else {
            ris=0;
        }
    } else {
        ris=0;
    }
    return ris;
}

void prossima_data(struct data next){
    int ris;

    ris = valida(next);
    next.b= bisestile(next.a);
    next.maxg= maxgiorni(next);

    if(ris==1){
        if(next.g<next.maxg){
            next.g++;
        } else if (next.g==next.maxg && next.m<12){
            next.m++;
            next.g=1;
        } else {
            next.a++;
            next.m=1;
            next.g=1;
        }
        printf("La data successiva e' questa: %d/%d/%d", next.g, next.m, next.a);
        printf("\n");
    } else {
        printf("Data sbagliata!");
        printf("\n");
    }
}

int confronto(struct data d1, struct data d2){
    int v1, v2;

    v1=valida(d1);
    v2=valida(d2);

    if(v1==0 || v2==0){
        return 2;
    } else if (d1.a==d2.a && d1.m==d2.m && d1.g==d2.g){
        return 0;
    } else if (d1.a<d2.a){
        return 1;
    } else if (d1.a==d2.a && d1.m<d2.m){
        return 1;
    } else if (d1.a==d2.a && d1.m==d2.m && d1.g<d2.g){
        return 1;
    } else {
        return -1;
    }
}

void aggdata(struct data data1){
    int ris, n, i;

    ris=valida(data1);
    
    if(ris==1){

        do{
            printf("Quanti giorni vuole aggungere: ");
            scanf("%d", &n);
        }while(n<=0);

        for(i=0;i<n;i++){
            data1.maxg=maxgiorni(data1);
            data1.b=bisestile(data1.a);
            if(data1.g<data1.maxg){
                data1.g++;
            } else if (data1.g==data1.maxg && data1.m<12){
                data1.m++;
                data1.g=1;
            } else {
                data1.a++;
                data1.m=1;
                data1.g=1;
            } 
        }

        printf("La data dopo %d giorni e' la seguente: %d/%d/%d\n", n, data1.g, data1.m, data1.a);
    } else {
        printf("Data non valida!\n");
    }

}

void stampadata(struct data stamp){
    int ris;

    ris=valida(stamp);

    if(ris==1){
        printf("La sua data stampata nel seguente formato e: %d %d %d --> %d/%d/%d\n", stamp.g, stamp.m, stamp.a, stamp.g, stamp.m, stamp.a);
    } else {
        printf("La data e sbagliata!\n");
    }
}

int differenza(struct data data1, struct data data2){
    int val1, val2, rist=0, ord;

    val1 = valida (data1);
    val2 = valida (data2);

    if(val1==0 || val2==0){
        rist=0;
    } else {
        ord = confronto(data1, data2);
        if (ord==0){
            rist=0;
        } else if (ord==1){
            while(ord!=0){
                
                data1.maxg=maxgiorni(data1);

                if(data1.g<data1.maxg){
                    data1.g++;
                } else if (data1.g==data1.maxg && data1.m<12){
                    data1.m++;
                    data1.g=1;
                } else {
                    data1.a++;
                    data1.m=1;
                    data1.g=1;
                }
                rist++;
                ord = confronto(data1, data2);
            }
        } else {
            ord = confronto(data1, data2);
            while (ord!=0){

                data2.maxg=maxgiorni(data2);

                if(data2.g>0){
                    data2.g--;
                } else if (data2.g==0 && data2.m>1){
                    data2.m--;
                    data2.g=data2.maxg;
                } else {
                    data2.a--;
                    data2.m=12;
                    data2.g=31;
                }
                
                ord = confronto(data1, data2);
                
                rist++;
            }
            rist=rist*-1;
        } 
    }
    return rist;
}

