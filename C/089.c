#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ContaChar(FILE *);
int ContaConsonanti(FILE *);
int main(){
    FILE *fp;
    fp=fopen("input.txt","r");
    if(fp==NULL){
        printf("Errore nell'apertura");
        exit(1);
    }

    printf("Numero di caratteri: %d\n",ContaChar(fp));
    fseek(fp,0L,0);
    printf("Numero di Consonanti: %d\n",ContaConsonanti(fp));
    fclose(fp);
    return 0;
}

int ContaChar(FILE *fp){
    int i=0;
    char buffer;
    while(buffer=fgetc(fp)!=EOF)
        i++;
    return i;
}


int ContaConsonanti(FILE *fp){
    int i,j;
    int c=0;
    char buffer;
    char consonanti[]={'q','w','r','t','y','p','s','d','f','g','h','j','k','l','z','x','c','v','b','n','m','Q','W','R','T','Y','P','S','D','F','G','H','J','K','L','Z','X','C','V','B','N','M','\0'};
    int dim=strlen(consonanti);
    int flag;
    while((buffer=fgetc(fp))!=EOF){
        j=0;
        flag=0;
        while(j<dim && flag==0){
            if(consonanti[j]==buffer){
                c++;
                flag=1;
            }
            j++;
        }
    }
    return c;
}