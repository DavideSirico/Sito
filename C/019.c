#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
int main(){
    int v[DIM],N,i,c;
    c=0;
    srand(time(NULL));
    for(i=0;i<DIM;i++)
        v[i]=rand()%100+1;
    for(i=0;i<DIM;i++)
    	printf("%3d",v[i]);
    putchar('\n');    
    do{
        printf("Inserire un numero maggiore di 0: ");
        scanf("%d",&N);
    }while(N<=0);
    for(i=0;i<DIM;i++){
        if(v[i]==N)
            c++;
    }
    putchar('\n');
    printf("%d e' presente %d volte",N,c);
    return 0;
}
