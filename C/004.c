#include <stdio.h>
int main(){
    int n,contaPari,contaDispari,i,flag;
    flag=0;
    contaDispari = 0;
    contaPari = 0;
    printf("Inserire un numero: ");
    scanf("%d",&n);
    fflush(stdin);
    printf("Pari: ");
    for(i=1;i<=n;i++){
        if(n%i==0 && i%2==0){
            contaPari++;
            printf("%d ", i);
            flag=1;
        }
    }
    if(flag==0)
    	printf("0");// No divisori pari = 0
    printf("\nDispari: ");
    for (i=1;i<=n;i++){
        if (n%i==0 && i%2!=0){
            contaDispari++;
            printf("%d ", i);
        }
    }
    printf("\nTotale pari: %d",contaPari);
    printf("\nTotale dispari: %d",contaDispari);
    return 0;
}
