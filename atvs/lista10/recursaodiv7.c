#include <stdio.h>

int divisivel7(long long n) {
    if (n < 0) n = -n;
    if (n == 0) return 1;
    /* caso base: quando o número ficar pequeno, testa diretamente */
    if (n < 100) return (n % 7) == 0;
    int last = n % 10;
    long long rest = n / 10;
    long long novo = rest + 5LL * last;
    return divisivel7(novo);
}

int main(void) {
    long long n;
    if (scanf("%lld", &n) != 1) return 0;
    printf("%c\n", divisivel7(n) ? 's' : 'n');
    return 0;
}