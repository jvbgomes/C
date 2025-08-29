#include <stdio.h>

int main() {
    int N, i;
    int soma = 0;
    printf("Digite um número: \n");
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        if (i % 2 == 0){
            soma += i;
        }
    }

    printf("Soma dos pares: %d\n", soma);

    return 0;
}