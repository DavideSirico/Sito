#include <stdio.h>
#define DIM 10
int main(){
    int i,j,c;
    char let[DIM];
    c=0;
    srand(time(NULL));
    for(i=0;i<DIM;i++)
    	let[i]=rand()%26+65;
	for(i=0;i<DIM;i++){
		if(let[i]=='A' || let[i]=='E' || let[i]=='I' || let[i]=='O' ||let[i]=='U')
			c++;
	}
	for(i=0;i<DIM;i++){
		printf("%c ", let[i]);
	}
	printf("\nNumero vocali=%d", c);
    return 0;
}
