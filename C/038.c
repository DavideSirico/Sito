#include <stdio.h>
#include <string.h>
#define DIM 80
void my_strncpy(char [], char[],int n);
int main(){
	char s1[DIM],s2[DIM];
	int n;
	printf("s1: ");
	gets(s1);
	printf("s2: ");
	gets(s2);
	printf("n:");
	scanf("%d",&n);
	fflush(stdin);
	strncpy(s2,s1,n);
	printf("s1: ");
	puts(s2);
	return 0;
}
void my_strncpy(char s2[DIM], char s1[DIM],int n){
	int i;
	for(i=0;i<n;i++){
		s2[i]=s1[i];	
	}
	s2[i]='\0';
}
