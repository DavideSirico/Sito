#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shift(FILE *fp,int spostamento);
int main(){
    FILE *fp;
    fp=fopen("input.txt","r+");
	if(fp==NULL){
		perror("Errore nell'apertura del file");
		exit(1);
	}

    char stringa[]="cor";
    int dim=strlen(stringa);
    char buffer[dim];
    char sotto_stringa[]="cuore";
    int dim_sotto=strlen(sotto_stringa);

    while(fread(buffer,1,dim,fp)>=dim){
        if(strcmp(buffer,stringa)==0){
            fseek(fp,-dim,1);
            shift(fp,(dim_sotto-dim));
			fprintf(fp,"%s",sotto_stringa);
        } else {
            fseek(fp,-(dim-1),1);
        }
    }

    fclose(fp);
    return 0;
}

void shift(FILE *fp,int spostamento){
    int pos_inizio=ftell(fp);

    fseek(fp,0,2);
    int i;
    for(i=0;i<spostamento;i++){
        fputc(' ',fp);
    }

    fseek(fp,0,2);
    int pos=ftell(fp);
    char buffer;
    while(pos>pos_inizio && pos!=spostamento+1){
        fseek(fp,-(spostamento+1),1);
        fread(&buffer,1,1,fp);
        fseek(fp,spostamento-1,1);
        fwrite(&buffer,1,1,fp);
        fseek(fp,-1,1);
        pos=ftell(fp);
    }

    fseek(fp,pos_inizio,0);
}