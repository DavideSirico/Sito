#include <stdio.h>
#define DIM 80
void my_strcpy(char [], char []);
int main(){
    char s1[DIM],s2[DIM];
    printf("Inserire la 1 stringa: ");
    gets(s1);
    fflush(stdin);
    putchar('\n');
    printf("Inserire la 2 stringa: ");
    gets(s2);
    fflush(stdin);
    putchar('\n');
    my_strcpy(s1,s2);
    printf("Stringa 1: ");
    puts(s1);
    return 0;
}
void my_strcpy(char s1[DIM], char s2[DIM]){
    int i;
    for(i=0;i<DIM;i++){
        s1[i]=s2[i];
    }
    s1[i]='\0';
}
