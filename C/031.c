#include <string.h>
#include <stdio.h>
int main()
{
    int i, c;
    char s[] = "Hello World!";
    c = 0;
    for(i = 0 ; i < sizeof(s)/sizeof(s[0]); i++)
        c++;
    puts(s);
    printf("lunghezza stringa: %d" , c-1);
    return 0;
}
