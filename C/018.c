#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
int main(){
    int v[DIM],i,j,c_primo,k,cdiv,l,v2[DIM];
    k=0;
    l=0;
    c_primo=0;
    srand(time(NULL));
    for (i=0;i<DIM;i++)
        v[i]=rand()%19+1;
    //conto i numeri primi
    for(i=0;i<DIM;i++){
        for(j=1;j<=v[i]/2;j++){
            if(v[i]%j==0){ //conto i divisori
                cdiv++; 
            }
        }
        if(cdiv==1){
            c_primo++;
        }
        cdiv=0;
    }
    //ordino i numeri primi
    for(i=0;i<DIM;i++){
        for(j=1;j<=v[i]/2;j++){//conto i numeri primi
            if(v[i]%j==0){ //conto i divisori
                cdiv++;
            }
        }
        if(cdiv==1){
            v2[l]=v[i];//assegno nelle prime posizioni i numeri primi
            l++;
        } else {
            v2[k+c_primo]=v[i];//sommo all'indice il totale dei numeri primi e li assegno
            k++;
        }
        cdiv=0; // resetto il contatore dei numeri divisori
    }
    //visualizzazione primo array
    for (i=0;i<DIM;i++){
        printf("%3d",v[i]);
    }
    //visualizzazione secondo array
    putchar('\n');
    for (i=0;i<DIM;i++){
        printf("%3d",v2[i]);
    }
    return 0;
}
