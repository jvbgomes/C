#include <stdio.h>

void gerar(int n) {
    if (n <= 0) return;
    printf("%d", n);
    if (n == 1) return;
    int primos[] = {2, 3, 5, 7};
    for (int i = 0; i < 4; ++i) {
        if (n % primos[i] == 0) {
            printf(" ");
            gerar(n / primos[i]);
            return;
        }
    }
    /* não divisível por nenhum primo: termina */
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    gerar(n);
    printf("\n");
    return 0;
}