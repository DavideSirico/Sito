#include<stdio.h>
int main(){
	int n,i,c;
	i=2;
	c=0;
	printf("n:");
	scanf("%d",&n);
	fflush(stdin);
	while(i<=n){
		if(n%i==0){	
			printf("%d ",i);
			c=c+1;
		}
		i=i*2;	
	}
	printf("\nNumero divisori di %d uguali a potenze di 2 = %d",n,c);
	return 0;	
}
