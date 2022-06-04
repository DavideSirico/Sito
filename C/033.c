#include <stdio.h>
#define DIM 5
int main(){
    int i,n,v[DIM],cifra;
    i=1;
    printf("Inserire un numero: ");
    scanf("%d",&n);
    fflush(stdin);
    while(n>0){
        cifra=n%10;
        n=n-cifra;
        n=n/10;
        v[DIM-i]=cifra;
        i++;
    }
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    return 0;
}
