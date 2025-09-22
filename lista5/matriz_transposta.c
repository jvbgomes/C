#include <stdio.h>

int main() {
    int l, c;
    scanf("%d %d", &l, &c);

    int A[l][c], B[c][l];

    // Leitura da matriz A
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Calcula a transposta em B
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            B[j][i] = A[i][j];
        }
    }

    // Imprime a transposta
    printf("Transposta\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < l; j++) {
            printf("%d", B[i][j]);
            if (j < l - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}