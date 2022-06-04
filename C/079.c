#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void caricaV(int *,int );
void visualizzaV(int *,int );
void maxV(int *,int );
void caricaM(int *,int ,int );
void visualizzaM(int *,int ,int );
void maxM(int *,int ,int );
int main()
{
	int row,col;
	printf("inserisci righe: ");
	scanf("%d",&row);
	fflush(stdin);
	printf("inserisci colonne: ");
	scanf("%d",&col);
	fflush(stdin);
	putchar('\n');
	int v[col],m[row][col];
	int *pv,*pm;
	pv=&v[0];
	pm=&m[0][0];
	srand(time(NULL));
	caricaV(pv,col);
	visualizzaV(pv,col);
	maxV(pv,col);
	caricaM(pm,row,col);
	visualizzaM(pm,row,col);
	maxM(pm,row,col);
	return 0;
}
void caricaV(int *pv,int col){
	int i;
	for(i=0;i<col;i++){
		*pv=rand()%50+1;
		pv++;
	}
}
void visualizzaV(int *pv,int col){
	int i;
	for(i=0;i<col;i++){
		printf("%d ",*pv);
		pv++;
	}
	putchar('\n');
}
void maxV(int *pv,int col){
	int i,max;
	max=*pv;
	for(i=0;i<col;i++){
		if(*pv>max){
			max=*pv;
		}
		pv++;
	}
	printf("maxV: %d",max);
	putchar('\n');
	putchar('\n');
}
void caricaM(int *pm,int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			*pm=rand()%50+1;
			pm++;
		}
	}
}
void visualizzaM(int *pm,int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%2d ",*pm);
			pm++;
		}
		putchar('\n');
	}
}
void maxM(int *pm,int row,int col){
	int i,j,max;
	max=*pm;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(*pm>max){
				max=*pm;
			}
			pm++;
		}
	}
	printf("maxM: %d",max);
	putchar('\n');
}
