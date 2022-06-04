#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;  
    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("Il file non esiste");
        exit(1);
    }
    int i=0;
    char buffer[80];
    while((i<10) && (fscanf(fp,"%s",buffer)!=EOF)){
        printf("%s ",buffer);
        i++;
    }
    fclose(fp);
    return 0;
}