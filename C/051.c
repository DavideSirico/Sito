/*51> 
int v1[DIM]={23,11,34,76,99,23,67,83,88,10};
int i,j,box,c=0,cswap=0;
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			if(v[i]<v[j]){
				box=v[i];
				v[i]=v[j];
				v[j]=box;
				cswap++;
			}
			c++;
		}
	}
confronti? 100  swap? ..... ordina? si se si (C/D)
*/
#include <stdio.h>
#define DIM 10
int main(){
    int v[DIM]={23,11,34,76,99,23,67,83,88,10};
    int i,j,box,c=0,cswap=0;
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++){
			if(v[i]<v[j]){
				box=v[i];
				v[i]=v[j];
				v[j]=box;
				cswap++;
			}
			c++;
		}
	}
    for(i=0;i<DIM;i++){
        printf("%d ", v[i]);
    }
    printf("\n%d", c);
    printf("\n%d", cswap);
}