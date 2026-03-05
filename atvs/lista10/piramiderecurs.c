#include <stdio.h>

void piramide(int n) {
    if (n <= 0) return;
    if (n == 1) {
        printf("1\n");
        return;
    }
    piramide(n - 1);
    for (int i = n; i >= 1; --i) {
        if (i != n) printf(" ");
        printf("%d", i);
    }
    printf("\n");
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    piramide(n);
    return 0;
}