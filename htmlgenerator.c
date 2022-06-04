#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define numeroPagine    1
#define OFFSET          87
void shift_r(FILE *fp,int spostamento);     //right shift di tutti i char dalla posizione corrente
int len(FILE *fp);                          //Restituisce il numero di char presenti in un file

int main(){
    FILE *fp_template;
    char nomeFileHtml[100];
    char nomeFileTxt[100];
    char pathHtml[200];
    char pathTxt[200];
    
    /* Windows Path
    char dirHtml[]="C:\\Users\\david\\Il mio Drive\\Scuola\\2021-2022\\Informatica\\Sito - Copia\\HTML Generated\\";
    char dirTxt[]="C:\\Users\\david\\Il mio Drive\\Scuola\\2021-2022\\Informatica\\Sito - Copia\\Es_corretti_text\\";
    char pathTemplate[]="C:\\Users\\david\\Il mio Drive\\Scuola\\2021-2022\\Informatica\\Sito - Copia\\HTML\\template.html";
    */

    //Linux Path
    char dirHtml[]="/mnt/c/Users/david/Il mio Drive/Scuola/2021-2022/Informatica/Sito/HTML/";
    char dirTxt[]="/mnt/c/Users/david/Il mio Drive/Scuola/2021-2022/Informatica/Sito/Es_corretti_text/";
    char pathTemplate[]="/mnt/c/Users/david/Il mio Drive/Scuola/2021-2022/Informatica/Sito/Template/template_File.html";

    char currentNum[4];
    char currentActive[50];
    char active[]="class=\"active-left\" ";

    int i;
    int j;
    fp_template=fopen(pathTemplate,"r");
    if(fp_template==NULL){
        perror("Template non trovato");
        exit(1);
    }
    
    for(j=0;j<numeroPagine;j++){
        FILE *fp_txt;
        FILE *fp_html;
        i=j+OFFSET;
        sprintf(currentNum,"%03d",i+1);
        sprintf(currentActive,"href=\"%03d.html\">%03d</a></li>",i+1,i+1);

        sprintf(nomeFileHtml,"%03d.html",i+1);
        sprintf(nomeFileTxt,"%03d.txt",i+1);
        strcpy(pathHtml,dirHtml);
        strcat(pathHtml,nomeFileHtml);
        strcpy(pathTxt,dirTxt);
        strcat(pathTxt,nomeFileTxt);

        printf(pathHtml);
        putchar('\n');
        
        fp_txt=fopen(pathTxt,"r");
        fp_html=fopen(pathHtml,"w");
        if(fp_txt==NULL){
            printf("%s\n",pathTxt);
            perror("Errore apertura file txt");
            exit(1);
        }
        if(fp_html==NULL){
            printf("%s\n",pathHtml);
            perror("Errore apertura file html");
            exit(1);
        }
        
        //sostituisco le XX del template con il numero del file corrente
        int car;
        while((car=fgetc(fp_template))!=EOF){
            if(car=='X'){
                car=fgetc(fp_template);
                if(car=='X'){
                    fprintf(fp_html,"%s",currentNum);
                } else {
                    fputc(car,fp_html);
                }
            } else {
                fputc(car,fp_html);
            }
        }

        fseek(fp_template,0,0);
        fclose(fp_html);

        fp_html=fopen(pathHtml,"r+");
        if(fp_html==NULL){
            printf("%s\n",pathHtml);
            perror("Errore apertura file html");
            exit(1);
        }

        //aggiungo la classe active-left all'elemento della lista giusto
        char buffer[100];
        int pos;

        pos=ftell(fp_template);
        while(fscanf(fp_template,"%s",buffer)!=EOF){
            if(strcmp(buffer,currentActive)==0){
                fseek(fp_html,pos+2,0);
                int lung=strlen(active);
                shift_r(fp_html,lung);
                fprintf(fp_html,"%s",active);;
                fseek(fp_html,0,1);
            }
            pos=ftell(fp_template);
        }
        
        fseek(fp_template,0,0);
        fseek(fp_html,0,0);

        //aggiungo il file C nel tag PRE
        while(fscanf(fp_html,"%s",buffer)!=EOF){
            if(strcmp(buffer,"<PRE>")==0){
                int lung=len(fp_txt);

                shift_r(fp_html,lung);
                
                while((car=fgetc(fp_txt))!=EOF){
                    fputc(car,fp_html);
                }
                
                fseek(fp_html,0,2);
            }
        }

        fseek(fp_template,0,0);
        fclose(fp_html);
        fclose(fp_txt);

    }
    fclose(fp_template);
    return 0;
}

int len(FILE *fp){
    int i=0;
    int car;
    while((car=fgetc(fp))!=EOF){
        i++;
    }
    fseek(fp,0,0);
    return i;
}

void shift_r(FILE *fp,int spostamento){
    int pos_inizio=ftell(fp);

    int i;
    fseek(fp,0,2);
    for(i=0;i<spostamento;i++){
        fputc(' ',fp);
        fseek(fp,0,1);
    }
    char buffer;
    fseek(fp,0,2);
    int pos=ftell(fp);
    while(pos>pos_inizio && pos!=spostamento+1){
        fseek(fp,(spostamento+1)*(-1),1);
        buffer=fgetc(fp);
        fseek(fp,spostamento-1,1);
        fputc(buffer,fp);
        fseek(fp,-1,1);
        pos=ftell(fp);
    }
    fseek(fp,pos_inizio,0);
}