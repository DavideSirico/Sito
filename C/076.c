#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
int main(){
  FILE *fpin1, *fpin2, *fpout;
  char str1[80], str2[80];
  fpin1=fopen("file1.txt", "r");
  fpin2=fopen("file2.txt", "r");
  fpout=fopen("fileall.txt", "a");
  if(fpin1==NULL||fpin2==NULL||fpout==NULL){
    perror("Errore nell'apertura dei file\n");
    exit(1);
  }
  while(fscanf(fpin1,"%s", &str1)!=EOF)
    fprintf(fpout,"%s ", str1);
  fflush(stdin);
  while(fscanf(fpin2,"%s", &str2)!=EOF)
    fprintf(fpout,"%s ", str2);
  
  fclose(fpin1);
  fclose(fpin2);
  fclose(fpout);
  return 0;
}
