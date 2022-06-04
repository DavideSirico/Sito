/*220325
======
66> Calcolare il massimo di un vettore v dimensionato DIM con procedimento ricorsivo.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
int massimo(int [], int, int);
void carica(int []);
int main(){
    int v[DIM]={10,2,5,3,26,39,8,14,9,7};
    int i=1;
    int max=v[0];
    printf("massimo=%d\n", massimo(v,i,max));
    return 0;
}
int massimo(int v[DIM], int i, int max){
    if(i==DIM-1){
        return (max);
    }else{
        if(v[i]>max)
            max=v[i];
        return(massimo(v,i+1,max));
    }
}