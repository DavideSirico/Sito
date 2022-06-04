#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define DIM 10

void visualizza(int []);
void carica(int []);
void sort_bubble(int []);
void sort_insertion(int []);
void sort_sel(int []);
int main(){
    int n,v[DIM],v2[DIM];
    srand(time(NULL));
    while(1){
        printf("0: exit\n1:carica\n2:visualizza\n3:bubble sort\n4:selection sort\n5:insertion sort\n");
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
                visualizza(v);
            break;
            case 3:
                sort_bubble(v);
            break;
            case 4:
                sort_sel(v);
            break;
            case 5:
                sort_insertion(v);
            break;
            default:
                printf("Numero non valido");
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

void visualizza(int v[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        printf("%d ",v[i]);
    }
    putchar('\n');
}


void sort_bubble(int v[DIM]){
    int i,j,temp;
    for(i=0;i<DIM-1;i++){
        for(j=i+1;j<DIM;j++){
            if(v[j]<v[i]){
                temp=v[j];
                v[j]=v[i];
                v[i]=temp;
            }
        }
    }
}

void sort_insertion(int v[DIM]){
	int i,j,min;
    for(i=1;i<DIM;i++){
        min=v[i];
        for(j=i-1;(j>=0) && (min<v[j]);j--){
            v[j+1]=v[j];
        }
        v[j+1]=min;
    }
}

void sort_sel(int v[DIM]){
	int i,j,imin,temp;
	for(i=0;i<(DIM-1);i++){
		imin=i;
		for(j=i+1;j<DIM;j++){
			if(v[imin]>v[j]){
				imin=j;
			}
		}
		if(i!=imin){
            temp=v[i];
            v[i]=v[imin];
            v[imin]=temp;
		}
	}
}