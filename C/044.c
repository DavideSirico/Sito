#include <stdio.h>
#include <string.h>
#define DIM 80
int cerca(char [], char []);
int main(){
	char s1[80],s2[80];
	int r;
    printf("Inserire la prima stringa: ");
    gets(s1);
    printf("\nInserire la seconda stringa: ");
    gets(s2);
	r=cerca(s1,s2);
	if(r==-1){
		printf("la stringa %s non e' contenuta in %s",s2,s1);
	} else {
		printf("indice di inizio = %d",r);
	}
	return 0;
}
int cerca(char s1[],char s2[]){
	int i,j,ind,flag;
    flag=0;
    i=0;
	do{
		if(s2[0]==s1[i]){
			ind=i;
			flag=0;
			for(j=1;s2[j]!='\0' && flag==0;j++){
				if(s2[j]!=s1[i+j]){
					flag=1;
					ind=-1;
				}
			}
			if(ind!=-1){
				return ind;
			}
		}
		i++;
	}while(s1[i]!='\0');
	return -1;
}
