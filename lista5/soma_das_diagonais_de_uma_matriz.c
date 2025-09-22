#include <stdio.h>

int somaDiagonais(int n, int mat[n][n]) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += mat[i][i];           // diagonal principal
        soma += mat[i][n - 1 - i];   // diagonal secundária
    }
    return soma;
}

int main() {
    int n;
    scanf("%d", &n);
    int mat[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
    printf("%d\n", somaDiagonais(n, mat));
    return 0;
}