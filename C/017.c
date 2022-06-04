#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 5
#define COL 7
int main(){
    int m[ROW][COL],i,j,somma,sommamax,posmax,pos,sommamin,posmin,temp;
    srand(time(NULL));
    posmax=0;
    sommamax=0;
    sommamin=0;
    //caricamento della matrice
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            m[i][j]=rand()%9+1;
        }
    }
    //visualizzazione della matrice
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            printf("%2d",m[i][j]);
        }
        putchar('\n');
    }
    //init sommamax, sommamin
    for(i=0;i<ROW;i++){
        somma=somma+m[i][0];
        pos=j;
    }
    sommamax=somma;
    sommamin=somma;
    somma=0;
    //colonna max e min
    for(j=0;j<COL;j++){
        for(i=0;i<ROW;i++){
            somma=somma+m[i][j];
            pos=j;
        }
        if(somma>sommamax){
            sommamax=somma;
            posmax=pos;
        }
        if(somma<sommamin){
            sommamin=somma;
            posmin=pos;
        }
        somma=0;
    }
    for(j=0;j<ROW;j++){
        temp=m[j][posmin];
        m[j][posmin]=m[j][posmax];
        m[j][posmax]=temp;
    }
    //visualizzazione matrice
    for(i=0;i<ROW;i++){
        putchar('\n');
        for(j=0;j<COL;j++){
            printf("%2d",m[i][j]);
        }
    }
    return 0;    
}
