#include <stdio.h>

int estaOrdenado(int vet[], int n) {
    for (int i = 1; i < n; i++) {
        if (vet[i] < vet[i - 1])
            return 0;
    }
    return 1;
}

int main() {
    int n, vet[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    if (estaOrdenado(vet, n))
        printf("Vetor esta ordenado\n");
    else
        printf("Vetor nao esta ordenado\n");

    return 0;
}