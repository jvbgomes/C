#include <stdio.h>

int main() {
    int n, m, x, achou = 0;
    scanf("%d %d", &n, &m);
    int A[30][30];

    // Leitura da matriz
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    // Leitura do valor a ser procurado
    scanf("%d", &x);

    // Procura o elemento x na matriz
    for (int i = 0; i < n && !achou; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == x) {
                achou = 1;
                break;
            }
        }
    }

    if (achou)
        printf("Matriz tem elemento %d\n", x);
    else
        printf("Matriz não tem elemento %d\n", x);

    return 0;
}