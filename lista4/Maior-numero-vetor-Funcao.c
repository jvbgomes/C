#include <stdio.h>

int maior(int vet[], int tam) {
    int m = vet[0];
    for (int i = 1; i < tam; i++) {
        if (vet[i] > m)
            m = vet[i];
    }
    return m;
}

int main() {
    int N;
    scanf("%d", &N);
    int vet[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &vet[i]);
    }
    int m = maior(vet, N);
    printf("O maior é: %d\n", m);
    return 0;
}