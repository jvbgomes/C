#include <stdio.h>

// 1. Piso e teto de um número de ponto flutuante
int piso(float x) {
    int inteiro = (int)x;
    if (x >= 0 || x == (float)inteiro)
        return inteiro;
    else
        return inteiro - 1;
}

int teto(float x) {
    int inteiro = (int)x;
    if (x == (float)inteiro)
        return inteiro;
    else if (x > 0)
        return inteiro + 1;
    else
        return inteiro;
}

// 2. div e mod sem usar / ou %
int div_inteira(int a, int b) {
    int q = 0, sinal = ((a < 0) ^ (b < 0)) ? -1 : 1;
    int aa = a < 0 ? -a : a;
    int bb = b < 0 ? -b : b;
    while (aa >= bb) {
        aa -= bb;
        q++;
    }
    return sinal * q;
}

int mod_inteira(int a, int b) {
    int sinal = a < 0 ? -1 : 1;
    int aa = a < 0 ? -a : a;
    int bb = b < 0 ? -b : b;
    while (aa >= bb) {
        aa -= bb;
    }
    return sinal * aa;
}

// 3. Primos no intervalo [a, b] usando Crivo de Eratóstenes
void primos_intervalo(int a, int b) {
    char primo[1001];
    for (int i = 0; i <= b; i++) primo[i] = 1;
    primo[0] = primo[1] = 0;
    for (int i = 2; i * i <= b; i++) {
        if (primo[i]) {
            for (int j = i * i; j <= b; j += i)
                primo[j] = 0;
        }
    }
    printf("Primos no intervalo [%d, %d]: ", a, b);
    for (int i = a; i <= b; i++) {
        if (i >= 2 && primo[i])
            printf("%d ", i);
    }
    printf("\n");
}

// 4. MDC(a, b) e Bézout, mostrando passo a passo
int mdc_bezout(int a, int b, int *s, int *t) {
    int r0 = a, r1 = b;
    int s0 = 1, s1 = 0;
    int t0 = 0, t1 = 1;
    printf("Passos do algoritmo de Euclides e Bézout:\n");
    while (r1 != 0) {
        int q = r0 / r1;
        int r2 = r0 - q * r1;
        int s2 = s0 - q * s1;
        int t2 = t0 - q * t1;
        printf("r0=%d, r1=%d, q=%d, r2=%d, s0=%d, s1=%d, s2=%d, t0=%d, t1=%d, t2=%d\n",
               r0, r1, q, r2, s0, s1, s2, t0, t1, t2);
        r0 = r1; r1 = r2;
        s0 = s1; s1 = s2;
        t0 = t1; t1 = t2;
    }
    *s = s0;
    *t = t0;
    return r0;
}

int main() {
    // Teste piso e teto
    float x;
    printf("Digite um número real para piso e teto: ");
    scanf("%f", &x);
    printf("Piso: %d\n", piso(x));
    printf("Teto: %d\n", teto(x));

    // Teste div e mod
    int a, b;
    printf("Digite dois inteiros para div e mod: ");
    scanf("%d %d", &a, &b);
    printf("div_inteira(%d, %d) = %d\n", a, b, div_inteira(a, b));
    printf("mod_inteira(%d, %d) = %d\n", a, b, mod_inteira(a, b));

    // Teste primos intervalo
    int ini, fim;
    printf("Digite o início e fim do intervalo para primos: ");
    scanf("%d %d", &ini, &fim);
    primos_intervalo(ini, fim);

    // Teste MDC e Bézout
    int s, t;
    printf("Digite dois inteiros para MDC e Bézout: ");
    scanf("%d %d", &a, &b);
    int mdc = mdc_bezout(a, b, &s, &t);
    printf("MDC(%d, %d) = %d\n", a, b, mdc);
    printf("Coeficientes de Bézout: s=%d, t=%d -> %d*%d + %d*%d = %d\n", a, s, a, b, t, b, mdc);

    return 0;
}