/*220223
======
65> Dato un numero n inserito esternamente calcolare 
la somma dei primi N numeri pari (>0) positivi in maniera ricorsiva.*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int somma(int n);
int main(){
    int n;
    long int ris;
    printf("inserire n:");
    scanf("%d", &n);
    fflush(stdin);
    printf("%d", somma(n));
    return 0;
}
int somma(int n){
    int ctr=n;
    if(ctr==1){
        return (2);
    }else{
        return (ctr*2+somma(ctr-1));
    }
}