#include<stdio.h>
#define DIM 10
void visualizza(int []);
int binary_research(int [],int ,int ,int );
int main()
{
	int v[DIM]={11,56,64,77,88,102,113,145,154,161},N,fine,inizio,i,flag;
	inizio=0;
	fine=DIM-1;
	flag=0;
	visualizza(v);
	printf("inserisci numero: ");
	scanf("%d",&N);
	fflush(stdin);
	for(i=0;i<DIM;i++){
		if(v[i]==N){
			flag=1;
		}
	}
	if(flag==1){
		printf("il numero si trova alla posizione %d",binary_research(v,N,fine,inizio));
	}else
	{
		printf("numero non presente");	
	}
	return 0;
}
void visualizza(int v[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		printf("%d ",v[i]);
	}
	putchar('\n');
}
int binary_research(int v[DIM],int N,int fine,int inizio){
	int medio;
	medio=(inizio+fine)/2;
	if(N==v[medio]){
		return medio+1;
	}else
	{
		if(N>v[medio]){
			return binary_research(v,N,fine,medio+1);
		}else
		{	
			return binary_research(v,N,medio-1,inizio);
		}
	}
}
