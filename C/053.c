#include <stdio.h>
#define DIM 8
int main(){
    int v[DIM];
    int n,i;
    do{
        printf("Inserire un numero minore di 255: ");
        scanf("%d",&n);
        fflush(stdin);
    }while(n>256);

    for(i=DIM-1;i>=0;i--){
        if(n%2==0){
            v[i]=0;
        } else {
            v[i]=1;
        }
        n=n/2;
    }
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }


    return 0;
}