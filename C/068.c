/*68> Scrivere una funzione ricorsiva che, 
dati due numeri interi n1 ed n2, 
restituisca la somma di tutti gli interi compresi 
tra n1 ed n2 estremi esclusi.*/
#include <stdio.h>
#include <stdlib.h>
int somma(int , int );
int main(){
    int n1,n2;
    printf("inserire n1:");
    scanf("%d", &n1);
    fflush(stdin);
    printf("inserire n2:");
    scanf("\n%d", &n2);
    fflush(stdin);
    if(n1<n2)
        printf("\n%d", somma(n1, n2));
    else
        printf("\n%d", somma(n2, n1));
    return 0;
}
int somma(int n1, int n2){
    int sum;
    if(n1==n2-1){
        return (0);
    }else{
        sum=sum+(n1+1);
        return (sum+somma(n1+1,n2));
    }
}