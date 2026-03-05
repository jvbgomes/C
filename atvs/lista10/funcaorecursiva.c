#include <stdio.h>

double potencia(double x, int n) {
    if (n <= 0) return 1.0;
    return x * potencia(x, n - 1);
}

int main(void) {
    double x;
    int n;
    if (scanf("%lf %d", &x, &n) != 2) return 0;
    printf("%g\n", potencia(x, n));
    return 0;
}