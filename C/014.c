#include <stdio.h>
#define DIM 10
int main(){
	int temp,v[DIM]={1,2,3,4,5,6,7,8,9,10},i;
    temp=v[0];
    for(i=0;i<DIM;i++)
        printf("%d ",v[i]);
    for(i=0;i<DIM-1;i++)
        v[i]=v[i+1];
    putchar('\n');
    v[DIM-1]=temp;
    for(i=0;i<DIM;i++)
        printf("%d ",v[i]);
    return 0;
}
