#include <stdio.h>
#define L 5
int main(){
	char v[L]={'P','R','O','V','A'};
	char v2[L]={'E','S','A','M','E'};
	char w[L*2];
	int i,j;
	j=0;
	for(i=0;i<L;i++)	
		w[i]=v[i];
	for(i=L;i<L*2;i++)	
		w[i]=v2[i-L];
	for(i=0;i<L;i++)
		printf("%c",v[i]);
	putchar('\n');
	for(i=0;i<L;i++)
		printf("%c",v2[i]);
	putchar('\n');
	for(i=0;i<(L*2);i++)
		printf("%c",w[i]);
	return 0;
}
