#include <stdio.h>

int main(){
    int num, i;
    int fatorial;
    fatorial = 1;

    printf("Digite um número: \n");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        fatorial *= i;
    }

    printf("Fatorial: %d\n", fatorial);

    return 0;
}