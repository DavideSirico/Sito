#include <stdio.h>
#define DIM 10
int main(){
	int v[DIM],n,flag,i,j;
	for(i=0;i<DIM;i++){
		do{
			flag=0;
			printf("Inserisci elemento n%d: ", i+1);
			scanf("%d", &n);
			fflush(stdin);
			for(j=0; j<i; j++){
				if(v[j]==n){
					flag=1;
				}
			}
		}while(flag==1);
		v[i]=n; 
	}
	for(i=0; i<DIM; i++){
		printf("%2d ", v[i]);
	}
}
