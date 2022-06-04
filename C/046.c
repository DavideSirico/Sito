#include <stdio.h>
int data(int, int, int);
int diff(int, int, int, int, int, int);
int bisestile(int);
int main(){
    int gg1,gg2,mm1,mm2,aaaa1,aaaa2;
    int max,n;
    do{
        putchar('\n');
        printf("Inserire giorno 1:");
        scanf("%d", &gg1);
        fflush(stdin);
        printf("Inserire mese 1:");
        scanf("%d", &mm1);
        fflush(stdin);
        printf("Inserire anno 1:");
        scanf("%d", &aaaa1);
        fflush(stdin);
    }while(!data(gg1, mm1, aaaa1));
    printf("\nData 1 valida!\n");
    do{
        putchar('\n');
        printf("Inserire giorno 2:");
        scanf("%d", &gg2);
        fflush(stdin);
        printf("Inserire mese 2: ");
        scanf("%d", &mm2);
        fflush(stdin);
        printf("Inserire anno 2: ");
        scanf("%d", &aaaa2);
        fflush(stdin);
    }while(!data(gg2, mm2, aaaa2));
    printf("\nData 2 valida!\n");
    n=diff(gg1,mm1,aaaa1,gg2,mm2,aaaa2);
    printf("\nLa differenza tra le 2 date e' di %d giorni",n);
    return 0;
}
int bisestile(int a){
    if(a%4==0){
        if(a%100==0){
            if(a%400==0){
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}
int diff(int g1, int m1, int a1, int g2, int m2, int a2){
    int giornitot[] = {0,31,59,90,120,151,181,212,243,273,304,334};//giorni dal primo Gennaio alla fine del mese di numero indice -1
    int bisgiornitot[] = {0,31,60,91,121,152,182,213,244,274,305,335}; //(bisestile)
    int totg,aa,delta1,delta2;
    totg=0;
    if(a1==a2){ //stesso anno
        if(bisestile(a1)){
            delta1=bisgiornitot[m1-1]+g1;
            delta2=bisgiornitot[m2-1]+g2;
            if(delta1>delta2){
                return (delta1-delta2);
            } else {
                return (delta2-delta1);
            }       
        } else {
            delta1=giornitot[m1-1]+g1;
            delta2=giornitot[m2-1]+g2;
            if(delta1>delta2){
                return (delta1-delta2);
            } else {
                return (delta2-delta1);
            }
        }
    }
    if(bisestile(a1)){
        totg=totg+366-(bisgiornitot[m1-1]+g1);
    } else {
        totg=totg+365-(giornitot[m1-1]+g1);
    }
    aa=a1+1;
    while(aa<a2){
        if(bisestile(aa)){
            totg=totg+366;
        }else{
            totg=totg+365;
        }
        aa=aa+1;
    }
    if(bisestile(a2)){
        totg=totg+(bisgiornitot[m2-1]+g2);
    }else{
        totg=totg+(giornitot[m2-1]+g2);
    }
    return totg;
}
int data(int gg, int mm,int aa){
	int v[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(aa<0){
		printf("Data non esistente\n");
		return 0;
	}
    if(bisestile(aa)){
        v[2]=29;
    }
	if(mm>12 || mm<=0){
		printf("Data non esistente\n");
		return 0;
	}
	if(gg>v[mm]){
		printf("Data non esistente\n");
		return 0;
	}
	return 1;
}
