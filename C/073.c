#include<stdio.h>
#include<string.h>
#define DIM 2
#define L 20
struct studenti{
	char cognome[L];
	char nome[L];
	int info;
	int condotta;
}alunni[DIM];
void carica_dati(struct studenti []);
void visualizza_dati(struct studenti []);
void modifica_condotta(struct studenti []);
void modifica_info(struct studenti []);
int main()
{
	int scelta;
	scelta=5; //numero casuale che non sia tra quelli da inserire
	while(1){
		printf("0>esc\n1>carica_dati\n2>visualizza_dati\n3>modifica_condotta\n4>modifica_info\nscelta: ");
		scanf("%d",&scelta);
		fflush(stdin);
		switch(scelta){
			case 0:
				return 0;
				break;
			case 1:
				putchar('\n');
				carica_dati(alunni);
				break;
			case 2:
				putchar('\n');
				visualizza_dati(alunni);
				break;
			case 3:
				putchar('\n');
				modifica_condotta(alunni);
				break;
			case 4:
				putchar('\n');
				modifica_info(alunni);
				break;	
			default:
				printf("Errore!!\n");
				break;
		}
		putchar('\n');
		scelta=5;
	}
	return 0;
}
void carica_dati(struct studenti alunni[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		printf("Cognome alunno %d: ",i+1);
		gets(alunni[i].cognome);
		fflush(stdin);
		printf("Nome alunno %d: ",i+1);
		gets(alunni[i].nome);
		fflush(stdin);
		do{
			printf("Voto info alunno %d: ",i+1);
			scanf("%d",&alunni[i].info);
			fflush(stdin);
		}while(alunni[i].info<=0 || alunni[i].info>10);
		do{
			printf("Voto condotta alunno %d: ",i+1);
			scanf("%d",&alunni[i].condotta);
			fflush(stdin);
		}while(alunni[i].condotta<=0 || alunni[i].condotta>10);
		putchar('\n');
	}
}
void visualizza_dati(struct studenti alunni[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		printf("Alunno %d: %s %s\n",i+1,alunni[i].cognome,alunni[i].nome);
		printf("Voto info: %d ",alunni[i].info);
		printf("Voto condotta: %d",alunni[i].condotta);
		putchar('\n');
	}
}
void modifica_condotta(struct studenti alunni[DIM]){
	int i,flag;
	char n[L],c[L];
	flag=0;
	printf("inserisci nome: ");
	gets(n);
	fflush(stdin);
	printf("inserisci cognome: ");
	gets(c);
	fflush(stdin);
	for(i=0;i<DIM;i++){
		//sistemare sta parte qua
		if(strcmp(n,alunni[i].nome)==0 && strcmp(c,alunni[i].cognome)==0){
			flag=1;
			printf("modifica voto condotta: ");
			scanf("%d",&alunni[i].condotta);
			fflush(stdin);
		}
	}
	if(flag==0){
		printf("studente non trovato!!");
		putchar('\n');
	}
}
void modifica_info(struct studenti alunni[DIM]){
	int i;
	for(i=0;i<DIM;i++){
		alunni[i].info++;
	}
}
