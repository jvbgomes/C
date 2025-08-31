#include <stdio.h>

int main() {
    int n, aux = 1, x = 1;
    scanf("%d", &n);

    if (n < 1) {
        printf("Você entrou com %d, tente de novo na próxima\n", n);
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < aux; j++) {
                if (x <= 9) {
                    printf(" ");
                    printf("%d", x);
                    printf(" ");
                } else {
                    printf("%d", x);
                    printf(" ");
                }
                x++;
            }
            printf("\n");
            aux++;
        }
    }

    return 0;
}