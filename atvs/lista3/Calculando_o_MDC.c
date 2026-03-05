#include <stdio.h>

int MDC(int x, int y) {
    while (y != 0) {
        int aux = x;
        x = y;
        y = aux % y;
    }
    return x;
}

int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("MDC(%d , %d) = %d\n", x, y, MDC(x, y));
    return 0;
}