/*75> copiare un file "prova.txt" su un altro file "provacopy.txt"*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(){
  FILE *fpin;
  FILE *fpout;
  char str[80];
  fpin=fopen("prova.txt", "r");
  fpout=fopen("provacopy.txt", "w");
  if(fpin==NULL || fpout==NULL){
    perror("errore nell'apertura edei file\n");
    exit(1);
  }
  while(fscanf(fpin,"%s", &str)!=EOF){
    fprintf(fpout,"%s ",str);
  }
  
  fclose(fpin);
  fclose(fpout);
  return 0;
}
