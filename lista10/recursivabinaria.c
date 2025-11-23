#include <stdio.h>

int eBinario(int n) {
    if (n < 0) n = -n;
    if (n == 0) return 1; // 0 é considerado binário
    int d = n % 10;
    if (d != 0 && d != 1) return 0;
    if (n < 10) return 1;
    return eBinario(n / 10);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (eBinario(n)) printf("Binário\n");
    else printf("Não binário\n");
    return 0;
}