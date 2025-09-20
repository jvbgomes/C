#include <stdio.h>
#include <stdlib.h>

// Função para somar os divisores próprios de um número
int somaDivisores(int n) {
    int soma = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0)
            soma += i;
    }
    return soma;
}

// Função para verificar se dois números são colegas
int saoColegas(int a, int b) {
    int da = somaDivisores(a);
    int db = somaDivisores(b);
    return (abs(da - b) <= 2 && abs(db - a) <= 2);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    if (saoColegas(a, b))
        printf("S\n");
    else
        printf("N\n");

    return 0;
}