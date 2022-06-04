#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 5
void push(int []);
int pop(int []);
void visualizza(int []);
void clear(int []);
int isEmpty(int []);
int isFull(int []);
int main()
{
	int v[DIM]={1,2,3,4,5},scelta,res1,res2;
	scelta=0;
	srand(time(NULL));
	while(1){
		printf("0>esc\n");
		printf("1>inserisci elemento\n");
		printf("2>estrai elemento\n");
		printf("3>svuota stack\n");
		printf("4>visualizza stack\n");
		printf("5>verifica stack vuota\n");
		printf("6>verifica stack piena\n");
		printf("Scelta: ");
		scanf("%d",&scelta);
		putchar('\n');
		switch(scelta){
			case 0:
				return 0;
			break;
			case 1:
				push(v);
			break;
			case 2:
				printf("estratto elemento: %d\n\n",pop(v));
			break;
			case 3:
				clear(v);
			break;
			case 4:
				visualizza(v);
			break;
			case 5:
				res1=isEmpty(v);
				if(res1==1){
					printf("stack vuota\n\n");
				}else
				{
					printf("stack non vuota\n\n");
				}
			break;
			case 6:
				res2=isFull(v);
				if(res2==1){
					printf("stack piena\n\n");
				}else
				{
					printf("stack non piena\n\n");
				}
			break;
			default:
				printf("errore\n\n");
			break;
		}
	}
	
	return 0;
}
void push(int v[DIM]){
	//inserisci nel primo elemento della stack, perciò l'ultimo va perso
	int i;
	for(i=DIM-1;i>=0;i--){
		v[i]=v[i-1];
	}
	v[0]=rand()%9+1;
	printf("elemento random aggiunto in stack\n\n");
}
int pop(int v[DIM]){
	//estrai l'ultimo elemento della stack --> il primo elemento sarà a 0 per indicare la cella vuota
	int i,temp;
	temp=v[DIM-1];
	for(i=DIM-1;i>=0;i--){
		v[i]=v[i-1];
	}
	v[0]=0;
	return temp;
}
void visualizza(int v[DIM]){
	int i;
	for(i=DIM-1;i>=0;i--){
		printf("%d\n",v[i]);
	}
	putchar('\n');
}
void clear(int v[DIM]){
	//0 = cella vuota
	int i;
	for(i=0;i<DIM;i++){
		v[i]=0;
	}
	printf("stack svuotata\n\n");
}
int isEmpty(int v[DIM]){
	int i,flag;
	flag=0;
	for(i=0;i<DIM;i++){
		if(v[i]!=0){
			flag=1;
		}
	}
	if(flag==0){
		return 1;
	}else
	{
		return 0;
	}
}
int isFull(int v[DIM]){
	int i,flag;
	flag=0;
	for(i=0;i<DIM;i++){
		if(v[i]==0){
			flag=1;
		}
	}
	if(flag==0){
		return 1;
	}else
	{
		return 0;
	}
}
