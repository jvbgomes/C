#include <stdio.h>

void imprimeSemRepeticao(int v[], int n) {
    for (int i = 0; i < n; i++) {
        int repetido = 0;
        for (int j = 0; j < i; j++) {
            if (v[i] == v[j]) {
                repetido = 1;
                break;
            }
        }
        if (!repetido) {
            printf("%d ", v[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    imprimeSemRepeticao(v, n);
    return 0;
}