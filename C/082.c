#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	FILE *fp;
	int ctr;
	char car;
	fp=fopen("numeri.num","r");
	if(fp==NULL){
		perror("Error: ");
		exit(1);	
	}
	ctr=0;
	while((car=fgetc(fp))!=EOF){
		if(car>='0' && car<='9'){
	    	ctr++;
	    }
	}
	fprintf(fp,"%d", ctr);
	fclose(fp);
	fp=fopen("numeri.num","a");
	if(fp==NULL){ 
		perror("Errore apertura file");
		exit(1);
	}
	fprintf(fp,"%d", ctr);
	fclose(fp);
	return 0;
}
