#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 5
#define COL 7
int main(){
    int m[ROW][COL],i,j,somma,sommamax,posmax,pos;
    srand(time(NULL));
    posmax=0;
    sommamax=0;
    //caricamento dell'array
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            m[i][j]=rand()%9+1;
        }
    }
    //visualizzazione dell'array
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("%2d",m[i][j]);
        }
        putchar('\n');
    }
    //colonna max
    for(j=0;j<COL;j++){
        for(i=0;i<ROW;i++){
            somma=somma+m[i][j];
            pos=j;
        }
        if(somma>sommamax){
            sommamax=somma;
            posmax=pos;
        }
        somma=0;
    }
    //visualizzazione colonna max
    putchar('\n');
    for(i=0;i<ROW;i++){
        printf("%2d",m[i][posmax]);
    	putchar('\n');
	}
    return 0;
}
