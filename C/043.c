#include<stdio.h>
#include<string.h>
int main()
{
	char s[80];
	int ctr,i;
	ctr=0;
	printf("Inserisci stringa: ");
	gets(s);
	for(i=0;i<strlen(s);i++){
		if(s[i]>=48 && s[i]<=57){
			ctr++;
		}
	}
	printf("le cifre nella stringa sono: %d",ctr);
	return 0;
}
