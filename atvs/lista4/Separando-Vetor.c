#include <stdio.h>

int main() {
    int A[20], pares[20], impares[20];
    int i, p = 0, im = 0;

    for (i = 0; i < 20; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < 20; i++) {
        if (A[i] % 2 == 0)
            pares[p++] = A[i];
        else
            impares[im++] = A[i];
    }

    printf("Pares: ");
    for (i = 0; i < p; i++) {
        printf("%d", pares[i]);
        if (i < p - 1) printf(",");
    }
    printf("\n");

    printf("Impares: ");
    for (i = 0; i < im; i++) {
        printf("%d", impares[i]);
        if (i < im - 1) printf(",");
    }
    printf("\n");

    return 0;
}