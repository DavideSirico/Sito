#include<stdio.h>
#include<string.h>
int my_strlen(char []);
int main()
{
	char s[80];
	int l;
	printf("Inserisci stringa: ");
	gets(s);
	l=my_strlen(s);
	printf("lunghezza = %d",l);
	return 0;
}
int my_strlen(char s[]){
	int l=0;
	int i;
	for(i=0;s[i]!='\0';i++){
		l++;
	}
	return l;
}
