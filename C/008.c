#include <stdio.h>
#define DIM 10

int main(){
    int v[DIM],i,min,max,contaMin,contaMax;
    srand(time(NULL));
    for(i=0;i<DIM;i++){
        v[i]=rand()%10+1;
    }
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    max=v[0];
    min=v[0];
    for(i=1;i<DIM;i++){
        if(v[i]>max){
            max=v[i];
            contaMax=i;
        }
        if(v[i]<min){
            min=v[i];
            contaMin=i;
        }
    }
    v[contaMin]=max;
    v[contaMax]=min;
    printf("\n");
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    return 0;
}