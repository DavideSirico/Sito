//220218_064_Sirico_Davide.c
/*64> dato un array dimensionato DIM=10 di stringhe con lunghezza L=80 inserite esternamente
preparare il seguente menu

0 - escape
n – ordina le stringhe per nome in modo crescente
d – ordina le stringhe per lunghezza in modo crescente 
v – ordina le stringhe contenenti più vocali in modo crescente 
*/
#include <stdio.h>
#include <string.h>
#define DIM 10
#define L 80

int vocali(char []);
void visualizza(char [][L]);
void sortn(char [][L]);
void sortd(char [][L]);
void sortv(char [][L]);
int main(){
    int i;
    char opz;
    char s[DIM][L];
    for(i=0;i<DIM;i++){
        printf("\nInserire la stringa %d: ",i+1);
        gets(s[i]);
        fflush(stdin);
    }
    while(1){
        printf("0 - escape\nn – ordina le stringhe per nome in modo crescente\nd – ordina le stringhe per lunghezza in modo crescente\nv – ordina le stringhe contenenti più vocali in modo crescente\n");
        printf("Inserire una opzione: ");
        scanf("%c",&opz);
        fflush(stdin);
        switch(opz){
            case '0':
                return 0;
                break;
            case 'n':
                sortn(s);
                visualizza(s);
                break;
            case 'd':
                sortd(s);
                visualizza(s);
                break;
            case 'v':
                sortv(s);
                visualizza(s);
                break;
            default:
                printf("Opzione errata\n\n");
                break;
        }
    }
}

void visualizza(char s[DIM][L]){
    int i;
    for(i=0;i<DIM;i++){
        printf("stringa %d: %s\n",i+1,s[i]);
    }
    putchar('\n');
}

void sortn(char s[DIM][L]){
    int i,j;
    char temp[L];
    for(i=0;i<(DIM-1);i++){
        for(j=i+1;j<DIM;j++){
            if(strcmp(s[i],s[j])>0){
                strcpy(temp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],temp);
            }
        }
    }
}

void sortd(char s[DIM][L]){
    int i,j;
    char temp[L];
    for(i=0;i<(DIM-1);i++){
        for(j=i+1;j<DIM;j++){
            if(strlen(s[i])>strlen(s[j])){
                strcpy(temp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],temp);
            }
        }
    }
}

void sortv(char s[DIM][L]){
    int i,j;
    int v1,v2;
    char temp[L];
    for(i=0;i<(DIM-1);i++){
        for(j=i+1;j<DIM;j++){
            v1=vocali(s[i]);
            v2=vocali(s[j]);   
            if(v1>v2){
                strcpy(temp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],temp);
            }
        }
    }
}

int vocali(char s[L]){
    int i,c;
    c=0;
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
            c++;
        }
    }
    return c;
}