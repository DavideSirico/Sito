#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
int main(){
    int i,v[DIM],k,prossimo,distanza,distanzamin,distanzaposizione;
    distanzamin=10;
    printf("Inserire numero K: ");
    scanf("%d",&k);
	for(i=0;i<DIM;i++)
		v[i]=rand()%100+1;		
    for (i=0;i<DIM;i++){
        if(k>v[i]){
            distanza=k-v[i];
            if(distanza<distanzamin){
                distanzamin=distanza;
                prossimo=v[i];
                distanzaposizione=i;
            }
        } else {
            distanza=v[i]-k;
            if(distanza<distanzamin){
                distanzamin=distanza;
                prossimo=v[i];
                distanzaposizione=i;
            }
        }

    }
    for (i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    printf("\ndistanza posizione=%d",distanzaposizione+1);
    printf("\nprossimo=%d",prossimo);
    return 0;
}

