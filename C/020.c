#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
int main(){
	int m[DIM][DIM],i,j,temp;
	srand(time(NULL));
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++)
			m[i][j]=rand()%100+1;
	}
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++)
			printf("%3d",m[i][j]);
		putchar('\n');
	}
	for(i=0;i<DIM-1;i++){
		if(i%2==0){
			for(j=0;j<DIM;j++){
				temp=m[i][j];
				m[i][j]=m[i+1][j]; 
				m[i+1][j]=temp;
			}
		}
	}
	putchar('\n');
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++)
			printf("%3d",m[i][j]);
		putchar('\n');
	}
	return 0;
}
