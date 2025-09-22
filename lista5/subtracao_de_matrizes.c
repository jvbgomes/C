#include <stdio.h>

// Função para subtrair matrizes
void subtraiMatrizes(int m, int n, int A[m][n], int B[m][n], int R[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            R[i][j] = A[i][j] - B[i][j];
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int A[m][n], B[m][n], R[m][n];

    // Leitura da matriz A
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    // Leitura da matriz B
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // Subtrai as matrizes
    subtraiMatrizes(m, n, A, B, R);

    // Imprime resultado
    printf("Resultado:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", R[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }

    // Conta elementos não nulos na parte triangular inferior
    int cont = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j && R[i][j] != 0)
                cont++;
        }
    }
    printf("Elementos não-nulos na região: %d\n", cont);

    return 0;
}