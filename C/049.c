//211203_049_Sirico_Davied.c
/*
Dato un array s dimensionato DIM di stringhe dimensionate L, scrivere una funzione 
int confronta(char [][L])
che ritorna il numero di stringhe uguali.
*/
#include <stdio.h>
#include <string.h>
#define DIM 5
#define L 80


void sort(char [][L]);
void carica(char [][L]);
int confronta(char [][L]);
int main(){
    char s[DIM][L];
    carica(s);
    printf("Sono state trovate %d stringhe uguali",confronta(s));
    return 0;
}

void carica(char s[DIM][L]){
    int i;
    printf("Inserire %d stringhe: \n",DIM);
    for(i=0;i<DIM;i++){
        gets(s[i]);
        fflush(stdin);
    }
}

void sort(char s[DIM][L]){
    int i,j;
    char temp[L];
    for(i=0;i<DIM-1;i++){
        for(j=i+1;j<DIM;j++){
            if(strcmp(s[i],s[j])>0){
                strcpy(temp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],temp);
            }
        }
    }
}

int confronta(char s[DIM][L]){
    int i;
    int c=0;
    int somma=0;
    sort(s);
    for(i=1;i<DIM;i++){
        if(strcmp(s[i],s[i-1])==0){
            if(c==0){
                c=c+2;
            } else {
                c++;
            }
        } else {
            somma+=c;
            c=0;
        }
    }
    somma+=c;

    return somma;
}