//220218_063_Sirico_Davide.c
/*
63> dato un vettore numerico v dimensionato DIM=20 con caricamento random [1..9] 
visualizzare la cifra che presenta più occorrenze
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 20

void visualizza(int []);
void occ(int []);
void sort(int []);
void carica(int []);
int main(){
    srand(time(NULL));
    int v[DIM];
    carica(v);
    visualizza(v);
    occ(v);
    return 0;
}

void visualizza(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}

void carica(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        v[i]=rand()%9+1;
    }
}

void sort(int v[DIM]){
    int i,j;
    int temp;
    for(i=0;i<DIM-1;i++){
        for(j=i+1;j<DIM;j++){
            if(v[i]>v[j]){
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
}

void occ(int v[DIM]){
    int i,j,max,maxi,c;
    max=0;
    sort(v);
    i=0;
    while(i<DIM-1){
        c=1;
        while(v[i]==v[i+1]){
            c++;
            i++;
        }
        if(max<c){
            max=c;
            maxi=i;
        }
        i++;
    }
    printf("numero con piu' occorrenze: %d\n",v[maxi]);
}
