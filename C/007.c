#include <stdio.h>
#define DIM 10
int main(){
    int v[DIM], i, max, min,somma;
    somma=0;
    srand(time(NULL));
    for (i=0;i<DIM;i++){
        v[i]=rand()%45+55;
    }
    for(i=0;i<DIM;i++)
    	printf("%3d",v[i]);
    putchar('\n');
    max=v[0];
    min=v[0];
    for (i=1;i<DIM;i++){
        if(v[i]>max){
            max=v[i];
        }
        if(v[i]<min){
            min=v[i];
        }
    }
    for(i=0;i<DIM;i++)
    	somma=somma+v[i];
    printf("Max=%d",max);
    printf("\nMin=%d",min);
    printf("\nSomma=%d",somma);    
    return 0;
}
