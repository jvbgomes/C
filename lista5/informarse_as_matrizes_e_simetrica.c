#include <stdio.h>

int ehSimetrica(int n, int mat[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != mat[j][i])
                return 0;
        }
    }
    return 1;
}

int main() {
    int n, mat[10][10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    if (ehSimetrica(n, mat))
        printf("A matriz e simetrica\n");
    else
        printf("A matriz nao e simetrica\n");

    return 0;
}