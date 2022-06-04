#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
int main(){
    int m[DIM][DIM],i,j;
    srand(time(NULL));
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            if(i<=j)
                m[i][j]=rand()%9+1;
            else
                m[i][j]=0;
        }
    }
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++)
            printf("%2d",m[i][j]);
        putchar('\n');
    }
    return 0;
}
