#include <stdio.h>
#include <stdlib.h>
#define L 80

void scrittura(char []);
int main(){
    FILE *fp_read;
    char nome_file[80];

    printf("Inserire il nome del file: ");
    scanf("%s",nome_file);
    fflush(stdin);

    fp_read=fopen(nome_file,"r");

    if(fp_read!=NULL){
        fclose(fp_read);
        while(1){
            char opz;
            printf("Il file esiste gia', vuoi sovrascriverlo? (y n): ");
            scanf("%c",&opz);
            fflush(stdin);
            switch(opz){
                case 'n':
                    exit(1);
                    break;
                case 'y':
                    scrittura(nome_file);
                    return 0;
                    break;
                default:
                    printf("Opzione non valida\n\n");
                    break;
            }
        }
    } else {
        scrittura(nome_file);
    }
    return 0;
}

void scrittura(char nome_file[L]){
    FILE *fp_write;
    fp_write=fopen(nome_file,"w");
    if(fp_write==NULL){
        printf("errore nell'apertura del file in scrittura");
        exit(1);
    }
    char buffer[L];
    printf("Inserire massimo 80 caratteri: ");
    gets(buffer);
    fprintf(fp_write,"%s",buffer);
    fclose(fp_write);
}