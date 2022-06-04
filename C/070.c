/*70> Algoritmo ricorsivo per la ricerca di un 
intero in un vettore*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
void carica(int []);
int visualizza(int [],int );
int ricerca(int [],int , int );
int main(){
    int v[DIM];
    int i=0;
    int n=0;
    srand(time(NULL));
    carica(v);
    visualizza(v, i);
    printf("\ninserire n:");
    scanf("%d", &n);
    fflush(stdin);
    if(ricerca(v,i,n)==1){
        printf("\ntrovato");
    }else{
        printf("non trovato");
    }
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
int ricerca(int v[DIM],int i, int n){
    if(i==DIM){
        return 0;
    }else{
        if(n==v[i]){
            return 1;
        }
        ricerca(v, i+1, n);
    }
}

