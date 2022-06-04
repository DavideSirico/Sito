#include <stdio.h>
#include <string.h>

int main(){
    int i,lung;
    char str1[20],str2[20];

    for(i=0; (str1[i]=getchar())!='\n'; i++);
    str1[i]='\0';
    for(i=0; (str2[i]=getchar())!='\n'; i++);
    str2[i]='\0';
    
    lung=strlen(str1);
    
    for(i=0;i<strlen(str2);i++){
        str1[lung+i]=str2[i];
    }
    putchar('\n');
    str1[lung+i]='\0';
    puts(str1);
    return 0;
}
