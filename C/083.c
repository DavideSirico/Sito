#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DIM 10

struct anagrafica{
  char nome[20];
  char cognome[20];
  char indirizzo[30];
  char eta[3];
}persona;

int Ricerca(struct anagrafica);
void Inserimento();
void Modifica(struct anagrafica);
void Cancellazione(struct anagrafica);
void Visualizzazione();

int main(){
  struct anagrafica persona_temp;
  int scelta;
  while(1){
    printf("\n1. Inserimento");
    printf("\n2. Modifica");
    printf("\n3. Cancellazione");
    printf("\n4. Ricerca ");
    printf("\n5. Visualizzazione");
    printf("\n0. Fine\n");
    printf("\nScelta: ");
    scanf("%d",&scelta);
    fflush(stdin);
    switch(scelta){
      case 1:
        Inserimento();
        break;
      case 2:
        Modifica(persona_temp);
        break;
      case 3:
        printf("\nNome:");
        scanf("%s", persona_temp.nome);
        fflush(stdin);

        printf("\nCognome:");
        scanf("%s", persona_temp.cognome);
        fflush(stdin);

        printf("\nIndirizzo:");
        gets(persona_temp.indirizzo);
        fflush(stdin);

        printf("\nEta':");
        scanf("%s", persona_temp.eta);
        fflush(stdin);
        Cancellazione(persona_temp);
        break;
      case 4:
        printf("\nNome:");
        scanf("%s", persona_temp.nome);
        fflush(stdin);

        printf("\nCognome:");
        scanf("%s", persona_temp.cognome);
        fflush(stdin);

        printf("\nIndirizzo:");
        gets(persona_temp.indirizzo);
        fflush(stdin);

        printf("\nEta':");
        scanf("%s", persona_temp.eta);
        fflush(stdin);
        if(Ricerca(persona_temp)==-1){
          printf("\nPersona non trovata\n\n");
        } else {
          printf("\nPersona trovata\n\n");
        }
        break;
      case 5:
        Visualizzazione();
        break;
      case 0:
        return 0;
        break;
      default:
        printf("Scelta non valida");
        break;
    }
  }
  return 0;
}

void Inserimento(){
  FILE *fp;
  fp=fopen("anagrafica.txt", "a");
  if(fp==NULL){ perror("Errore"); exit(1); }

  printf("\nNome:");
  scanf("%s", persona.nome);
  fflush(stdin);

  printf("\nCognome:");
  scanf("%s", persona.cognome);
  fflush(stdin);

  printf("\nIndirizzo:");
  gets(persona.indirizzo);
  fflush(stdin);

  printf("\nEta':");
  scanf("%s", persona.eta);
  fflush(stdin);

  fwrite(&persona, sizeof(struct anagrafica), 1, fp);
  

  fclose(fp);
}

void Modifica(struct anagrafica persona_temp){
  FILE *fp;
  fp=fopen("anagrafica.txt", "r+");
  if(fp==NULL){ perror("Errore"); exit(1); }
  int n;
  if((n=Ricerca(persona_temp))!=-1){
    fseek(fp, n*sizeof(struct anagrafica), SEEK_SET);
    fwrite(&persona_temp, sizeof(struct anagrafica), 1, fp);
  }
  fclose(fp);
}

void Cancellazione(struct anagrafica persona_temp){
  FILE *fp;
  fp=fopen("anagrafica.txt", "r+");
  if(fp==NULL){ perror("Errore"); exit(1); }
  int n;
  if((n=Ricerca(persona_temp))!=-1){
    FILE *fp2;
    fp2=fopen("anagrafica2.txt", "w");
    if(fp2==NULL){ perror("Errore"); exit(1); }
    int i=0;
    while(fread(&persona_temp, sizeof(struct anagrafica), 1, fp)!=0){
      if(i!=n){
        fwrite(&persona_temp, sizeof(struct anagrafica), 1, fp2);
      }
      i++;
    }
    fclose(fp2);
    fclose(fp);
    if(remove("anagrafica.txt")!=0){ perror("Errore nella cancellazione del file"); exit(1); }
    if(rename("anagrafica2.txt", "anagrafica.txt")!=0){ perror("Errore nella cancellazione del file"); exit(1); }
    if(remove("anagrafica2.txt")!=0){ perror("Errore nella cancellazione del file"); exit(1); }
  } else {
    fclose(fp);
  }
}

int Ricerca(struct anagrafica persona_temp){
  FILE *fp;
  fp=fopen("anagrafica.txt", "r");
  if(fp==NULL){ perror("Errore"); exit(1); }
  int c=0;
  while((fread(&persona, sizeof(struct anagrafica), 1, fp))!=0){
    if(strcmp(persona.nome, persona_temp.nome)==0 && strcmp(persona.cognome, persona_temp.cognome)==0 && strcmp(persona.indirizzo, persona_temp.indirizzo)==0 && strcmp(persona.eta, persona_temp.eta)==0){
      return c;
    }
    c++;
  }
  return -1;
  fclose(fp);
}

void Visualizzazione(){
  FILE *fp;
  fp=fopen("anagrafica.txt", "r");
  if(fp==NULL){ perror("Errore"); exit(1); }

  while((fread(&persona, sizeof(struct anagrafica), 1, fp))!=0){
    printf("\nNome: %s", persona.nome);
    printf("\nCognome: %s", persona.cognome);
    printf("\nIndirizzo: %s", persona.indirizzo);
    printf("\nEta': %s", persona.eta);
    printf("\n\n\n\n");
  }

  fclose(fp);
}