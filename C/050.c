#include <stdio.h>
#define DIM 10

void visualizza(int []);
int trovamax(int []);
int trovamin(int []);
int main(){
    //int v[DIM]={2,9,5,7,2,1,6,4,6,5}; //esempio ordine decrescente
    int v[DIM]={2,1,5,7,2,1,9,4,6,5}; //esempio ordine crescente
    int posmax,min,i,j,box;
    visualizza(v);
    posmax=trovamax(v);
    min=trovamin(v);
    if(posmax<min){
        for(i=posmax;i<min;i++){
            for(j=posmax+1;j<min;j++){
                if(v[j-1]<v[j]){
                    box=v[j-1];
                    v[j-1]=v[j];
                    v[j]=box;
                }
            }
        }
    } else {
        for(i=min;i<posmax;i++){
            for(j=min+1;j<posmax;j++){
                if(v[j-1]>v[j]){
                    box=v[j-1];
                    v[j-1]=v[j];
                    v[j]=box;
                }
            }
        }
    }
    visualizza(v);
    return 0;
}

int trovamax(int v[DIM]){
    int max,posmax,i;
    posmax=0;
    max=v[0];
    for(i=1;i<DIM;i++){
        if(v[i]>max){
            max=v[i];
            posmax=i;
        }
    }
    return posmax;
}

int trovamin(int v[DIM]){
    int min,posmin,i;
    posmin=0;
    min=v[0];
    for(i=1;i<DIM;i++){
        if(v[i]<min){
            min=v[i];
            posmin=i;
        }
    }
    return posmin;
}

void visualizza(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}