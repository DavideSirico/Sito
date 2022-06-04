#include <stdio.h>
#include <string.h>
void my_strcpy(char [], char[]);
int main(){
    int i;
    char str1[]="Franco",str2[]="Foresta";
    my_strcpy(str1,str2);
    printf("Stringa1:");
    puts(str1);
    printf("Stringa2:");
    puts(str2);
    return 0;
}
void my_strcpy(char str1[20],char str2[0]){
	int i;
	for(i=0;i<strlen(str2);i++){
        str2[i]=str1[i];
    }
}
