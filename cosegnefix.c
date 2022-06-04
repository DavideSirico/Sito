//crea i file txt che non rompono gli html dai file c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contaFile();

int main(){
    FILE *fp_read,*fp_write;
    char path_src[200]="C:\\Users\\david\\Il mio Drive\\Scuola\\2021-2022\\Informatica\\Sito\\C.txt";
    char path_dst[200]="C:\\Users\\david\\Il mio Drive\\Scuola\\2021-2022\\Informatica\\Sito\\Es_corretti_text\\C0.txt";
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
        } else if(buffer=='\n'){
            fprintf(fp_write,"%s","<br>");
            fputc('\n',fp_write);
        } else {
            fputc(buffer,fp_write);
        }
    }
    fclose(fp_read);
    fclose(fp_write);
    return 0;
}
