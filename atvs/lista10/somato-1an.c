#include <stdio.h>

int somatorio(int n) {
    if (n <= 1) return n > 0 ? n : 0;
    return n + somatorio(n - 1);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    printf("%d\n", somatorio(n));
    return 0;
}