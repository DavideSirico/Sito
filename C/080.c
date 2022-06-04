#include<stdio.h>
#include<string.h>
#include <stdlib.h>
int main()
{
	FILE *fp1,*fp2;
	fp1=fopen("input.txt","r"); //file di input
	fp2=fopen("output.txt","w"); //file di output
	if(fp1==NULL || fp2==NULL){ //controllo errore apertura file
		perror("Error: ");
		exit(1);
	}
	char car;
	while((car=fgetc(fp1))!=EOF){
		if(car=='f'){
			fputs("effe",fp2);
		}else{
			fputc(car,fp2);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
