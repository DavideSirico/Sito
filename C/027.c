#include <stdio.h>
#define DIM 9
void spirale(int [][DIM]);
void visualizza(int [][DIM]);
void azzera(int [][DIM]);
int main(){
    int m[DIM][DIM];
    azzera(m);
    visualizza(m);
    spirale(m);
    putchar('\n');
    visualizza(m);
    return 0;
}
void azzera(int m[DIM][DIM]){
    int i,j;
    for(i=0;i<DIM;i++)
        for(j=0;j<DIM;j++)
            m[i][j]=0;
}
void visualizza(int m[DIM][DIM]){
    int i,j;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            printf("%3d",m[i][j]);
        }
        putchar('\n');
    }
}
void spirale(int m[DIM][DIM]){
    int i;
    for(i=0;i<DIM-1;i++){
        //TOP
        m[0][i]=i+1;
        //RIGHT
        m[i][DIM-1]=i+DIM;
        //BOT
        m[DIM-1][DIM-i-1]=DIM+DIM+i-1;
        //LEFT
        m[DIM-i-1][0]=(DIM-1)*3+i+1;
    }
}
