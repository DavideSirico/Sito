//crea i file txt che non rompono gli html dai file c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char src[100]="C:\\Users\\david\\Il mio Drive\\Scuola\\2021-2022\\Informatica\\Sito\\C\\";
    char dst[100]="C:\\Users\\david\\Il mio Drive\\Scuola\\2021-2022\\Informatica\\Sito\\Es_corretti_text\\";
    // int Nfile = contaFile();
    int Nfile = 93;
    char nomefile_src[100]="";
    char nomefile_dst[100]="";
    FILE *fp_read,*fp_write;
    char path_src[200]="";
    char path_dst[200]="";
    int i;
    for(i=0;i<Nfile-1;i++){
        sprintf(nomefile_src,"%03d",i+1);
        sprintf(nomefile_dst,"%03d",i+1);
        strcat(nomefile_src,".c");
        strcat(nomefile_dst,".txt");
        strcpy(path_src,"");
        strcpy(path_dst,"");
        strcat(path_src,src);
        strcat(path_dst,dst);
        strcat(path_src,nomefile_src);
        strcat(path_dst,nomefile_dst);
        
        printf("%s\n",path_src);
        char buffer;
        fp_read=fopen(path_src,"r");
        fp_write=fopen(path_dst,"w");
        if(fp_write==NULL){
            printf("Negro");
        }
        while((buffer=fgetc(fp_read))!=EOF){
            if(buffer=='<'){
                fprintf(fp_write,"&lt");
            }
            else if(buffer=='>'){
                fprintf(fp_write,"&gt");
            } else {
                fputc(buffer,fp_write);
            }
        }
        fclose(fp_read);
        fclose(fp_write);
    }

    return 0;
}