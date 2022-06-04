#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *fp1,*fp2;
	fp1=fopen("input.txt","r");
	fp2=fopen("output.txt","w");
	if(fp1==NULL || fp2==NULL){
		perror("Error: ");
		exit(1);
	}
	char buffer[4];
    char stringa[10]="effe";
    int n;

    while((n=fread(buffer,1,4,fp1))>3){
        buffer[4]='\0';

        if(strcmp(buffer,stringa)==0){
            fputc('f',fp2);
        } else {
            fseek(fp1,-3,1);
            fputc(buffer[0],fp2);
        }
    }
    fputc(buffer[0],fp2);
    fputc(buffer[1],fp2);
    fputc(buffer[2],fp2);

	fclose(fp1);
	fclose(fp2);
	return 0;
}
