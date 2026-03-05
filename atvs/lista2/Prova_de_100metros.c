#include <stdio.h>
#include <math.h>

int main() {
    double tempo_max, tempo;
    int aptos = 0;

    scanf("%lf", &tempo_max);

    while(1) {
        scanf("%lf", &tempo);
        if (tempo == -1.0) {
            break;
        }
        if (tempo <= tempo_max) {
            aptos++;
        }
    }

    int series = (aptos + 7) / 8;

    printf("%d %d\n", aptos, series);

    return 0;
}
