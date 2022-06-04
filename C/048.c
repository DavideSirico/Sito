#include <string.h>
#include <stdio.h>
#define DIM 5
void ricerca(char [][80], char[]);
int main()
{
    char v[DIM][80],s[80];
    int i,r,j;
    for(i=0;i<DIM;i++){
        printf("inserire stringa %d (premere invio per terminare): ", i+1);
        gets(v[i]);
        if(v[i][0] == '\0'){
            break;
        }
    }
    if(i<DIM-1){
        return 0;
    }
    putchar('\n');
    printf("inserire stringa da cercare: ");
    gets(s);
    putchar('\n');
    ricerca(v,s);
    return 0;
}
void ricerca(char v[][80], char s[]){
    int i,r;
    for(i=0;i<DIM;i++){
        r=0;
        r=strcmp(v[i],s);
        if(r==0)
        {
            printf("parola presente in posizione %d\n\n", i+1);
        }else{
            printf("parola non trovata\n\n");
        }
    }
}
