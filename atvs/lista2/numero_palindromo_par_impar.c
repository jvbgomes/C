#include <stdio.h>

int main() {
    int n, original, invertido = 0;
    scanf("%d", &n);
    original = n;

    while (n > 0) {
        invertido = invertido * 10 + (n % 10);
        n /= 10;
    }

    printf("%d", original);

    if (original == invertido) {
        printf(" é Palíndromo");
    } else {
        printf(" não é Palíndromo");
    }

    if (original % 2 == 0) {
        printf(" e par.\n");
    } else {
        printf(" e impar.\n");
    }

    return 0;
}