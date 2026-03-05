#include <stdio.h>

int main() {
    int N, i, validos = 0;
    double valor, soma = 0.0;

    scanf("%d", &N);


    for ( i = 0; i < N; i++) {
        scanf("%lf", &valor);
        if (valor != -1) {
            soma += valor;
            validos++;
        }
    }

    if (validos == 0) {
        printf("A competicao nao possui dados historicos!\n");
    } else {
        printf("%.2lf\n", soma / validos);
    }

    return 0;
}