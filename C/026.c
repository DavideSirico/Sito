#include <stdio.h>
#define DIM 10
void visualizzaframe(int [][DIM],int);
void carica(int [][DIM]);
int main(){
    int m[DIM][DIM];
    carica(m);
    visualizzaframe(m,3);
    return 0;
}
void visualizzaframe(int m[DIM][DIM], int c){
    int i,j,k;
    for(i=0;i<DIM;i++){
        putchar(' ');
        for(j=0;j<c;j++){
            putchar('-');
        }
    }
    putchar('\n');
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            printf("|%3d",m[i][j]);
        }
        putchar('|');
        putchar('\n');
        for(j=0;j<DIM;j++){
            putchar(' ');
            for(k=0;k<c;k++){
                putchar('-');
            }
        }
        putchar('\n');   
    }
    putchar('\n');
}
void carica(int m[DIM][DIM]){
    int i,j,c;
    c=1;
    for(i=0;i<DIM;i++){
        for(j=0;j<DIM;j++){
            m[i][j]=c;
            c=c+1;
        }
    }
}
