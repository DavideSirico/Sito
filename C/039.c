#include <stdio.h>
#include <string.h>
#define DIM 80
int my_strcmp(char [], char[]);
int main(){
	char s1[DIM],s2[DIM];
	int flag;
	printf("s1: ");
	gets(s1);
	printf("s2: ");
	gets(s2);
	flag=my_strcmp(s1,s2);
	if(flag==0){
		printf("%s = %s",s1,s2);
	}else if(flag==1){
		printf("%s > %s",s1,s2);
	}else{
		printf("%s < %s",s1,s2);		
	}
	return 0;
}
int my_strcmp(char s1[DIM], char s2[DIM]){
	int i,flag;
	i=0;
	while(i<DIM){
		if(s1[i]>s2[i]){
			return 1;
		}else if(s1[i]<s2[i]){
			return -1;
			}
		i++;	
	}
	return 0;
}
