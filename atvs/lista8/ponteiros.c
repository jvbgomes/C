#include <stdio.h>

void ordena(int *a, int *b) {
    if (*a < *b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
}

int main(void) {
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) return 0;
    ordena(&x, &y);
    printf("%d\n%d\n", x, y);
    return 0;
}