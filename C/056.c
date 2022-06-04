//220108_056_Sirico_Davide.c
/*
ordina-stringhe  - Scrivere un programma che ordini in modo crescente e
con un algoritmo in-place un array di DIM stringhe inserite esternamente,
visualizzando il risultato dell'ordinamento sullo schermo.
Si assuma che ogni stringa abbia una lunghezza L non superiore a 80 caratteri.
*/
#include <stdio.h>
#include <string.h>
#define DIM 5
#define L 80

void visualizza(char [][L]);
void sort(char [][L]);
int main(){
    char vs[DIM][L];
    int i;
    //caricamento esterno
    printf("Inserisci 5 stringhe: ");
    for(i=0;i<DIM;i++){
        gets(vs[i]);
    }
    putchar('\n');
    //sorting
    sort(vs);
    //visualizza
    visualizza(vs);
    return 0;
}


void visualizza(char vs[DIM][L]){
    int i;
    for(i=0;i<DIM;i++){
        printf("%s\n",vs[i]);
    }
    putchar('\n');
}

void sort(char vs[DIM][L]){
    int i,j;
    char temp[L];
    for(i=0;i<DIM;i++){
        for(j=i+1;j<DIM;j++){
            if(strcmp(vs[i],vs[j])>0){
                strcpy(temp,vs[i]);
                strcpy(vs[i],vs[j]);
                strcpy(vs[j],temp);
            }
        }
    }
}