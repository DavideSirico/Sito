#include <stdio.h>
void rettangolo(int,int);
int main(){
    int row,col;
    do{
        printf("Inserire righe: ");
        scanf("%d",&row);
        fflush(stdin);
        putchar('\n');
    }while(row<0);
    do{
        printf("Inserire colonne: ");
        scanf("%d",&col);
        fflush(stdin);
        putchar('\n');
    }while(col<0);
    putchar('\n');
    rettangolo(row,col);
    return 0;
}
void rettangolo(int row,int col){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("*");
        }
    printf("\n");
    }
}
