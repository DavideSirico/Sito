#include <stdio.h>
int main(){
	int somma,n,i;
	somma=0;
	for (i=0;i<10;i++){
		printf("Inserire n: ");
		scanf("%d",&n);
		somma=somma+n;
	}
	if (somma>100){
		printf("La somma e' maggiore di 100");
	} else if (somma==100) {
		printf("La somma e' uguale a 100");
	} else {
		printf("La somma e' minore di 100");
	}
	return 0;
}
