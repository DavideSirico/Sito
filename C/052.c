#include <stdio.h>
#include <math.h>

int potenza(int,int);
int main(){
    int v[]={1,1,1,1,1,1,1,1};
    int i,ris,pot,dim;
    dim=sizeof(v)/sizeof(int);
    ris=0;
    pot=potenza(2,dim-1);
    for(i=0;i<dim;i++){
        ris=ris+(pot*v[i]);
        printf("%d\n",ris);
        pot=potenza(2,(dim-2)-i);
    }

    printf("Decimale: %d",ris);
    return 0;
}

int potenza(int n,int esp){
    int i,ris;
    ris=1;
    for(i=0;i<esp;i++){
        ris=ris*n;
    }
    return ris;
}