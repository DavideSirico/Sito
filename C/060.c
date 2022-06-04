/*Data una stringa s="Oggi ProVIAMO a VeDere chi Vince" caricata contestualmente
estrarre solo le maiuscole e ordinarle in una seconda stringa s2 in modo discendente.
visualizzare s.
visualizzare s2.*/
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define DIM 20


void maiusc(char [],char []);
void sort(char []);
int main(){
    char s[]="Oggi ProVIAMO aVeDere chi Vince";
    char s2[80];
    maiusc(s,s2);
    sort(s2);
    puts(s);
    puts(s2);
    return 0;
}

void maiusc(char s[], char s2[80]){
    int i,j;
    j=0;
    for(i=0;s[i]!='\0';i++){
        if((s[i]>=65) && (s[i]<=90)){
            s2[j]=s[i];
            j++;
        }
    }
    s2[j]='\0';
}

void sort(char s2[80]){
    int i,j;
    char temp;
    for(i=0;s2[i+1]!='\0';i++){
        for(j=i+1;s2[j]!='\0';j++){
            if(s2[i]>s2[j]){
                temp=s2[i];
                s2[i]=s2[j];
                s2[j]=temp;
            }
        }
    }
}