#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define DIM 10

void carica(int []);
void sort(int []);
void visualizza(int []);
int ricerca(int [],int);
int main(){
    int v[DIM],key,ris;
    srand(time(NULL));
    carica(v);
    visualizza(v);
    sort(v);
    visualizza(v);
    printf("Inserire un numero da cercare: ");
    scanf("%d",&key);
    fflush(stdin);
    ris=ricerca(v,key);
    if(ris==-1){
        printf("Valore non trovato");
    } else {
        printf("Valore trovato nella posizione %d",ris);
    }
    return 0;
}

void carica(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        v[i]=rand()%99+1;
    }
}

void visualizza(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}

void sort(int v[DIM]){
    int i,j,temp;
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

int ricerca(int v[DIM],int key){
    int i,s,m,e; //s=start m=mid e=end
    s=0;
    e=DIM-1;
    while(s<=e){
        m=(s+e)/2;
        if(v[m]==key){
            return m;
        }
        if(v[m]>key){
            e=m-1;
        } else {
            s=m+1;
        }
    }
    return -1;
}