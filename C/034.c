#include <stdio.h>
#include <string.h>
int vocali (char []);
int main(){
	char s[80];
	int v;
	printf("Inserire stringa: ");
	gets(s);
	v=vocali(s);
	printf("numero vocali: %d",v);
	return 0;
}
int vocali(char s[80]){
	int vocali=0;
	int i;
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
			vocali++;
		}
	}	
	return vocali;
}
