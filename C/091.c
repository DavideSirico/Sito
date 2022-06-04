#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp1,*fp2,*fp_write;
    fp1=fopen("input0.txt","r");
    fp2=fopen("input1.txt","r");
    fp_write=fopen("output.txt","w");

    if(fp1==NULL || fp2==NULL || fp_write==NULL){
        printf("Errore nell'apertura");
        exit(1);
    }
    char buffer1,buffer2;
    int flag=0;
    int c=0;
    while(flag==0 && (((buffer1=fgetc(fp1))!=EOF) && ((buffer2=fgetc(fp2))!=EOF))){
        if(buffer1==buffer2){
            fputc(buffer1,fp_write);
        } else {
            flag=1;
        }
        
        c++;
    }
    if(c==1){
        printf("File diversi\n");
    } else {
        printf("Scrittura avvenuta con successo\n");
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp_write);
    return 0;
}
