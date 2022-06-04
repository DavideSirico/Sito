#include<stdio.h>
#include<string.h>
#define L 80
int count_char(char *,char );
int main()
{
	char *s,c,str[L];
	printf("inserisci stringa: ");
	scanf("%s",str);
	fflush(stdin);
	s=&str[0];
	printf("inserisci carattere: ");
	scanf("%c",&c);
	fflush(stdin);
	printf("occorrenze: %d",count_char(s,c));
	return 0;
}
int count_char(char *str,char c){
	if(*str=='\0'){
		return 0;
	}else
	{
		if(*str==c){
			return count_char(str+1,c)+1;
		}else
		{
			return count_char(str+1,c);
		}	
	}
}
