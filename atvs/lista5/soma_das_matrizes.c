#include <stdio.h>

// Função para somar e imprimir as matrizes
void somaMatrizes(int m, int n, int A[m][n], int B[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", A[i][j] + B[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int A[m][n], B[m][n];

    // Leitura da matriz A
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    // Leitura da matriz B
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    somaMatrizes(m, n, A, B);

    return 0;
}