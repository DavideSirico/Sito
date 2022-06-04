#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
void visualizza(int [],int);
void carica(int []);
void scambia(int []);
int main(){
    int v[DIM];
    srand(time(NULL));
    carica(v);
    visualizza(v,3);
    scambia(v);
    visualizza(v,3);
    return 0;
}
void visualizza(int v[DIM], int c){
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
        v[i]=rand()%90+10;
    }
}
void scambia(int v[DIM]){
    int i,temp;
    for(i=0;i<DIM-1;i=i+2){
        temp=v[i];
        v[i]=v[i+1];
        v[i+1]=temp;
    }
}
