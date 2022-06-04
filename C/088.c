#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona{
    char nome[20];
    char cognome[20];
    char numero[80];
    char indirizzo[80];
};

void visualizza();
void inserisci(struct persona);
int ricerca(struct persona);
void cancella();
void modifica();

int main(){
    struct persona temp;
    int scelta;
    int posizione;
    while(1){
        printf("0>Esci\n1>Inserisci\n2>Modifica\n3>Cancella\n4>Visualizza\n");
        printf("Scelta: ");
        scanf("%d",&scelta);
        fflush(stdin);

        switch(scelta){
            case 0:
                return 0;
                break;
            case 1:
                printf("\nNome: ");
                scanf("%s",temp.nome);

                printf("\nCognome: ");
                scanf("%s",temp.cognome);

                printf("\nNumero: ");
                scanf("%s",temp.numero);

                printf("\nIndirizzo: ");
                gets(temp.indirizzo);

                inserisci(temp);
                break;
            case 2:
                do{
                    printf("\nNome: ");
                    scanf("%s",temp.nome);

                    printf("\nCognome: ");
                    scanf("%s",temp.cognome);

                    printf("\nNumero: ");
                    scanf("%s",temp.numero);

                    printf("\nIndirizzo: ");
                    gets(temp.indirizzo);
                }while((posizione=ricerca(temp))==-1);
                modifica(temp,posizione);
                break;
            case 3:
                do{
                    printf("\nNome: ");
                    scanf("%s",temp.nome);

                    printf("\nCognome: ");
                    scanf("%s",temp.cognome);

                    printf("\nNumero: ");
                    scanf("%s",temp.numero);

                    printf("\nIndirizzo: ");
                    gets(temp.indirizzo);
                }while((posizione=ricerca(temp))==-1);
                cancella(temp);
                break;
            case 4:
                visualizza();
                break;
            default:
                printf("Errore: scelta non valida\n");
                break;
        }
    }
    return 0;
}

void cancella(struct persona temp){
    FILE *fp,*fp_temp;
    fp=fopen("rubrica.dat","r+");
    fp_temp=fopen("temp.dat","w");

    if(fp==NULL || fp_temp==NULL){
        perror("Errore: impossibile aprire il file\n");
        exit(1);
    }

    struct persona temp2;
    while(fread(&temp2,sizeof(struct persona),1,fp)!=0){
        if(strcmp(temp.nome,temp2.nome)!=0 && strcmp(temp.cognome,temp2.cognome)!=0 && strcmp(temp.numero,temp2.numero)!=0 && strcmp(temp.indirizzo,temp2.indirizzo)!=0){
            fwrite(&temp,sizeof(struct persona),1,fp_temp);
        }
    }

    fclose(fp);
    fclose(fp_temp);
    remove("rubrica.dat");
    rename("temp.dat","rubrica.dat");
    remove("temp.dat");
}

void modifica(struct persona temp,int pos){
    FILE *fp;
    fp=fopen("rubrica.dat","r+");
    if(fp==NULL){
        perror("Error");
        exit(1);
    }
    fseek(fp,pos*sizeof(struct persona),SEEK_SET);
    fwrite(&temp,sizeof(struct persona),1,fp);
    fclose(fp);
}

int ricerca(struct persona temp){
    FILE *fp;
    fp=fopen("rubrica.dat","r");
    if(fp==NULL){
        perror("Error");
        exit(1);
    }
    int i=0;
    struct persona temp2;
    while(fread(&temp2,sizeof(struct persona),1,fp)!=0){
        if(strcmp(temp.nome,temp2.nome)==0 && strcmp(temp.cognome,temp2.cognome)==0 && strcmp(temp.numero,temp2.numero)==0 && strcmp(temp.indirizzo,temp2.indirizzo)==0){
            fclose(fp);
            return i;
        }
        i++;
    }
    fclose(fp);
    return -1;
}

void inserisci(struct persona temp){
    FILE *fp;
    fp=fopen("rubrica.dat","a");
    if(fp==NULL){
        perror("Error");
        exit(1);
    }
    fwrite(&temp,sizeof(temp),1,fp);
    fclose(fp);
}

void visualizza(){
    FILE *fp;
    struct persona temp;
    fp=fopen("rubrica.dat","r");
    if(fp==NULL){
        perror("Error");
        exit(1);
    }
    while(fread(&temp,sizeof(temp),1,fp)==1){
        printf("\n\n\nNome: %s",temp.nome);
        printf("\nCognome: %s",temp.cognome);
        printf("\nNumero: %s",temp.numero);
        printf("\nIndirizzo: %s",temp.indirizzo);
    }
    fclose(fp);
}