#include <stdio.h>

int main() {
    int A[15], B[15], C[15], D[15];
    int i, b = 0, c = 0, d = 0;

    for (i = 0; i < 15; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 0; i < 15; i++) {
        if (A[i] % 6 == 0) {
            B[b++] = A[i];
            C[c++] = A[i];
        } else if (A[i] % 2 == 0) {
            B[b++] = A[i];
        } else if (A[i] % 3 == 0) {
            C[c++] = A[i];
        } else {
            D[d++] = A[i];
        }
    }

    printf("B = [");
    for (i = 0; i < b; i++) {
        printf("%d", B[i]);
        if (i < b - 1) printf(", ");
    }
    printf("]\n");

    printf("C = [");
    for (i = 0; i < c; i++) {
        printf("%d", C[i]);
        if (i < c - 1) printf(", ");
    }
    printf("]\n");

    printf("D = [");
    for (i = 0; i < d; i++) {
        printf("%d", D[i]);
        if (i < d - 1) printf(", ");
    }
    printf("]\n");

    return 0;
}