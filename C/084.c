#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("C:\\autoexec.bat","r");

    if(fp==NULL){
        printf("Il file non esiste");
        exit(1);
    }

    char buffer;
    while((buffer=fgetc(fp))!=EOF){
        putchar(buffer);
    }
    fclose(fp);
    return 0;
}