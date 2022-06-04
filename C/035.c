#include <stdio.h>
long int potenza(int ,int );
int main(){
    int n,esp;
    printf("Inserire numero: ");
    scanf("%d",&n);
    fflush(stdin);
    do{
        printf("\nInserire esponente: ");
        scanf("%d",&esp);
        fflush(stdin); 
    }while(esp<0);
    printf("\nLa potenza vale: %ld",potenza(n,esp));
    return 0;
}
long int potenza(int n,int esp){
    long int pot;
    int i;
    pot=n;
    for(i=1;i<esp;i++){
        pot=pot*n;
    }
    return pot;
}
