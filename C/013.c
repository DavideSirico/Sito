#include <stdio.h>
#define DIM 10
int main(){
	int temp,v[DIM]={1,2,3,4,5,6,7,8,9,10},i;
    temp=v[DIM-1];
    for(i=0;i<DIM;i++)
        printf("%3d ",v[i]);
    putchar('\n');
    for(i=DIM-1;i>0;i--)
        v[i]=v[i-1];
    v[0]=temp;
    for(i=0;i<DIM;i++)
        printf("%3d ",v[i]);
}
