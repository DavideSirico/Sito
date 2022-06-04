#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char car;
	int i,ctr;
	FILE *fp;
	fp=fopen("numeri.txt","r");
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
	printf("Nel file sono presenti %d cifre",ctr);
	fclose(fp);
	return 0;
}
