#include <stdio.h>

int main(){
    int N, i, num;
    int soma = 0;
    float media;

    printf("Quantos números: \n");
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        printf("Digite um número %d: ", i);
        scanf("%d", &num);
        soma += num;
    }

    media = (float)soma / N;
    printf("Média: %.2f\n", media);

    return 0;
}