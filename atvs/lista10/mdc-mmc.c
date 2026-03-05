#include <stdio.h>

static int gcd_rec(int a, int b) {
    if (b == 0) return a < 0 ? -a : a;
    return gcd_rec(b, a % b);
}

void calc_mdc_mmc(int x, int y, int *mdc, int *mmc) {
    int ax = x < 0 ? -x : x;
    int ay = y < 0 ? -y : y;
    int g = gcd_rec(ax, ay);
    *mdc = g;
    if (g == 0) {
        *mmc = 0;
    } else {
        long long l = (long long)(ax / g) * ay;
        if (l < 0) l = -l;
        *mmc = (int)l;
    }
}

int main(void) {
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) return 0;
    int mdc, mmc;
    calc_mdc_mmc(x, y, &mdc, &mmc);
    printf("MDC = %d, MMC = %d\n", mdc, mmc);
    return 0;
}