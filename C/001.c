//001 - area rettangolo (con fflush(stdin) - sizeof())
#include<stdio.h>
int main(){
	int base,altezza,area;
	
	printf("i byte di un int sono: %d\n",sizeof(base));
	printf("altezza rettangolo: ");
	scanf("%d",&altezza);
	fflush(stdin);	
	printf("base rettangolo: ");
	scanf("%d",&base);
	fflush(stdin);
	area=base*altezza;
	printf("area rettangolo = %d",area);
	return 0;
}
