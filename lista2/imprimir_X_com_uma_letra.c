#include <stdio.h>

int main() {
    int n, i, j;
    char c;
    scanf("%d %c", &n, &c);

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (j == i || j == (n - 2 - i)) {
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}