#include <stdio.h>
#define DIM 15
int main(){
	int v[DIM],i,n,cv,j,flag;
	n=1;
	for(i=0;i<DIM;i++){
		flag=0;
		while(flag==0){
			for(j=1;j<=n/2;j++){
				if(n%j==0){
					cv+=1;
				}
			}
			if(cv==1){
				v[i]=n;
				flag=1;
			}
			n+=1;
			cv=0;
		}
	}
	for(i=0;i<DIM;i++){
		printf("%d ",v[i]);
	}
	return 0;
}
