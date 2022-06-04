#include<stdio.h>
int main(){
	int m,n,i,numDivisori,somma;
	i=2;
	numDivisori=1;
	somma=1;
	do{
		printf("m:");
		scanf("%d",&m);
		fflush(stdin);
	}while(m<=0);
	do{
		printf("n:");
		scanf("%d",&n);
		fflush(stdin);
	}while(n<=0);
	printf("1 ");
	while(i<=m && i<=n){
		if(m%i==0 && n%i==0){
			printf("%d ",i);
			somma=somma+i;
			numDivisori=numDivisori+1;
		}
		i=i+1;	
	}
	printf("\nNumero divisori comuni=%d\n",numDivisori);
	printf("Somma=%d",somma);	
	return 0;	
}
