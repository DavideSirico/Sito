/*69> Algoritmo ricorsivo per la visualizzazione di un vettore di 
interi*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
void carica(int []);
int visualizza(int [],int );
int main(){
    int v[DIM];
    int i;
    srand(time(NULL));
    carica(v);
    visualizza(v, i);
    return 0;
}
int visualizza(int v[DIM],int i){
    if(i==DIM){
        return 0;
    }else{
        printf("%d ", v[i]);
        return visualizza(v, i+1);
    }
}
void carica(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        v[i]=rand()%10+1;
    }
}

