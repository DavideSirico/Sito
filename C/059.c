/*
Caricare un vet v DIM=20 con numeri random a piacere.
Visualizzare v.
Ordinare la prima metà di v e poi la seconda metà di v.
Alla fine v risulterà ordinato.
Visualizzare nuovamente v.*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define DIM 20


void half_sort(int []);
void carica(int []);
void visualizza(int []);
int main(){
    int v[DIM];
    carica(v);
    visualizza(v);
    half_sort(v);
    visualizza(v);

    return 0;
}

void carica(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        v[i]=rand()%99;
    }
}

void visualizza(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}

void half_sort(int v[DIM]){
    int i,temp,j;
    for(i=0;i<(DIM/2)-1;i++){
        for(j=i+1;j<DIM/2;j++){
            if(v[i]>v[j]){
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
    for(i=DIM/2;i<DIM-1;i++){
        for(j=i+1;j<DIM;j++){
            if(v[i]>v[j]){
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
}