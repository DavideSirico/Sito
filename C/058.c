#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DIM 10

void carica(int []);
void sort_bubble(int []);
void sort_insertion(int []);
void sort_sel(int []);
void incSwap();
void incComp();
void resetCounters();
void printCounters();

int swap_count=0;
int comp_count=0;

int main(){
    int n,v[DIM];
    srand(time(NULL));
    carica(v);
    while(1){
        printf("0: exit\n1:carica\n2:bubble sort\n3:selection sort\n4:insertion sort\n");
        printf("Inserire l'opzione: ");
        scanf("%d",&n);
        fflush(stdin);
        switch(n){
            case 0:
                return 0;
            case 1:
                carica(v);
            break;
            case 2:
                resetCounters();
                sort_bubble(v);
                printCounters();
            break;
            case 3:
                resetCounters();
                sort_sel(v);
                printCounters();
            break;
            case 4:
                resetCounters();
                sort_insertion(v);
                printCounters();
            break;
            default:
                printf("Numero non valido\n");
            break;
        }
    }
}

void carica(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        v[i]=rand()%99;
    }
}

void sort_bubble(int v[DIM]){
    int i,j,temp;
    int v2[DIM];
    long int temp1,temp2;
    
    for(i=0;i<DIM;i++){
        v2[i]=v[i];
        printf("%d ",v2[i]);
    }
    putchar('\n');
    temp1=clock();
    for(i=0;i<DIM-1;i++){
        for(j=i+1;j<DIM;j++){
            incComp();
             if(v2[j]<v2[i]){
                incSwap();
                temp=v2[j];
                v2[j]=v2[i];
                v2[i]=temp;
            }
        }
    }
    temp2=clock();
    for(i=0;i<DIM;i++){
        printf("%d ",v2[i]);
    }
    printf("\nTempo di esecuzione: %li",temp2-temp1);
    putchar('\n');
}

void sort_insertion(int v[DIM]){
	int i,j,min;
    int v2[DIM];
    long int temp1,temp2;
    
    for(i=0;i<DIM;i++){
        v2[i]=v[i];
        printf("%d ",v2[i]);
    }
    putchar('\n');
    temp1=clock();
    for(i=1;i<DIM;i++){
        min=v2[i];
        for(j=i-1;(j>=0) && (min<v2[j]);j--){
            v2[j+1]=v2[j];
        }
        incSwap();
        v2[j+1]=min;
    }
    temp2=clock();
    for(i=0;i<DIM;i++){
        printf("%d ",v2[i]);
    }
    
    printf("\nTempo di esecuzione: %li",temp2-temp1);
    putchar('\n');
}

void sort_sel(int v[DIM]){
	int i,j,imin,temp;
    int v2[DIM];
    long int temp1,temp2;
    
    for(i=0;i<DIM;i++){
        v2[i]=v[i];
        printf("%d ",v2[i]);
    }
    putchar('\n');
	temp1=clock();
    for(i=0;i<(DIM-1);i++){
		imin=i;
		for(j=i+1;j<DIM;j++){
            incComp();
			if(v2[imin]>v2[j]){
				imin=j;
			}
		}
		if(i!=imin){
            incSwap();
            temp=v2[i];
            v2[i]=v2[imin];
            v2[imin]=temp;
		}
	}
    temp2=clock();
    for(i=0;i<DIM;i++){
        printf("%d ",v2[i]);
    }
    printf("\nTempo di esecuzione: %li",temp2-temp1);
    putchar('\n');
}

void incSwap() { swap_count++; }
void incComp() { comp_count++; }
void resetCounters(){
    swap_count=0;
    comp_count=0;
}

void printCounters(){
    printf("Confronti effettuati: %d\n",comp_count);
    printf("Scambi effettuati: %d\n",swap_count);
}
