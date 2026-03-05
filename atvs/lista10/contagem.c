#include <stdio.h>

int contagem(int n) {
    if (n < 0) n = -n;
    if (n < 10) return 1;
    return 1 + contagem(n / 10);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    printf("%d\n", contagem(n));
    return 0;
}