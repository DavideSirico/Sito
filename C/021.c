#include <stdio.h>
#define DIM 10
int main(){
    int v[DIM],i;
    v[0]=v[1]=1;
    for(i=2;i<DIM;i++)
        v[i]=v[i-1]+v[i-2];
    for(i=0;i<DIM;i++)
        printf("%d ",v[i]);
    return 0;
}
