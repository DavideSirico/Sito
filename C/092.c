#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100
#define L 80

int main(){
    FILE *fp_read,*fp_write;
    fp_read=fopen("input.txt","r");
    fp_write=fopen("output.txt","w");
    if(fp_read==NULL || fp_write==NULL){
        printf("Errore nell'apertura del file");
        exit(1);
    }

    char parole[DIM][L];
    int i=0,j;
    int dim;
    while(fscanf(fp_read,"%s",parole[i])!=EOF){
        i++;
    }
    dim=i;
    i=0;
    char temp[L];
    for(i=0;i<dim-1;i++){
        for(j=i+1;j<dim;j++){
            if(strcmp(parole[i],parole[j])>0){
                strcpy(temp,parole[i]);        
                strcpy(parole[i],parole[j]);
                strcpy(parole[j],temp);
            }
        }
    }

    i=0;
    while(i<dim){
        fprintf(fp_write,"%s\n",parole[i]);
        i++;
    }

    fclose(fp_write);
    fclose(fp_read);
    return 0;
}
