#include <stdio.h>

int somaDigitos(int n) {
    if (n < 0) n = -n;
    if (n == 0) return 0;
    if (n < 10) return n;
    return (n % 10) + somaDigitos(n / 10);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    printf("%d\n", somaDigitos(n));
    return 0;
}