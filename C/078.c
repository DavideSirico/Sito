#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("ricordi.old","r+");
    if(fp==NULL){
        printf("Errore nell'apertura del file");
        exit(1);
    }
    char buffer;
    while((buffer=fgetc(fp))!=EOF){
        if(buffer=='.'){
            fseek(fp,2,1);
            buffer=fgetc(fp);
            if(buffer==EOF){
                break;
            }
            fseek(fp,-1,1);
            buffer=buffer-32;
            fputc(buffer,fp);
        }
    }
    fclose(fp);
    return 0;
}