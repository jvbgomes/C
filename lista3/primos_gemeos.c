#include <stdio.h>

int ehPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    if (ehPrimo(n) && ehPrimo(n + 2))
        printf("Numero forma par de gemeos\n");
    else
        printf("Numero nao forma par de gemeos\n");

    return 0;
}