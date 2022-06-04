#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
void visualizzaframe(int [],int);
void carica(int []);
void caricamax(int [],int [],int []);
int main(){
    int v[DIM],v2[DIM],v3[DIM];
    srand(time(NULL));
    carica(v);
    carica(v2);
    visualizzaframe(v,3);
    visualizzaframe(v2,3);
    caricamax(v,v2,v3);
    visualizzaframe(v3,3);
    return 0;
}

void visualizzaframe(int v[DIM], int c){
    int i,j;
    for(i=0;i<DIM;i++){
        printf(" ");
        for(j=0;j<c;j++){
            printf("-");
        }
    }
    putchar('\n');
    for(i=0;i<DIM;i++){
        printf("|%3d",v[i]);
    }
    printf("|");
    putchar('\n');
    for(i=0;i<DIM;i++){
        printf(" ");
        for(j=0;j<c;j++){
            printf("-");
        }
    }
    putchar('\n');
}

void carica(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        v[i]=rand()%100+1;
    }
}

void caricamax(int v[DIM],int v2[DIM],int v3[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        if(v[i]<v2[i]){
            v3[i]=v2[i];
        } else {
            v3[i]=v[i];
        }
    }

}
