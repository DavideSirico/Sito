#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("Errore nell'apertura del file");
        exit(1);
    }
    char buffer[80];
    fgets(buffer,80,fp);
    puts(buffer);
    fseek(fp,0L,0);
    fgets(buffer,80,fp);
    puts(buffer);

    fclose(fp);
    return 0;
}