//220107_057_Sirico_Davide.c
/*
data una stringa s caricata contestualmente (contenente solo lettere e spazi per ipotesi)
eliminare gli spazi e caricare in una seconda stringa s2
convertire s2 tutto in minuscole
ordinare s2 in modo crescente
visualizzare s2

es: s="vADo al maRe"
s2="vADoalmaRe"
s2="vadoalmare"
s2="aaadelmorv"
*/
#include <stdio.h>
#include <string.h>

int main(){
    char s[]="vADo al maRe";
    char s2[80];
    int i,j,leng;
    j=0;
    for(leng=0;s[leng]!='\0';leng++);
    for(i=0;i<leng;i++){
        if(s[i]!=32){
            s2[j]=s[i];
            j++;
        }
    }
    s2[j]='\0';
    puts(s2);
    i=0;
    while(s2[i]!='\0'){
        if(s2[i]>64 && s2[i]<91){
            s2[i]=s2[i]+32;
        }
        i++;
    }
    puts(s2); 
    char temp;
    for(i=0;i<leng;i++){
        for(j=0;j<leng-i;j++){
            if(s2[j]<s2[j+1]){
                temp=s2[j];
                s2[j]=s2[j+1];
                s2[j+1]=temp;
            }
        }
    }
    puts(s2);
    return 0;
}