#include <stdio.h>
#include <string.h>
void reverse(char [],char[]);
int main(){
    char str2[20],str1[]="Franco";
    reverse(str1,str2);
    puts(str1);
    puts(str2);
    return 0;
}
void reverse(char str1[20],char str2[20]){
	int i;
	for(i=0;i<strlen(str1);i++){
        str2[i]=str1[(strlen(str1)-i)-1];
    }
    str2[strlen(str2)]='\0';
	
	
	
}
