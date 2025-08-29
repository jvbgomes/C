#include <stdio.h>
#include <math.h>

int main() {
    int inicial, final;
    int i, j, aux, eh_primo;

    printf("Digite dois numeros inteiros (intervalo): ");
    if (scanf("%d %d", &inicial, &final) != 2) {
        printf("Entrada invalida!\n");
        return 1;
    }

    if (inicial > final) {
        aux = inicial;
        inicial = final;
        final = aux;
    }

    for (i = inicial; i <= final; i++) {
        if (i < 2) continue; // Números menores que 2 não são primos
        eh_primo = 1;
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                eh_primo = 0;
                break;
            }
        }
        if (eh_primo) {
            printf("%d\n", i);
        }
    }

    return 0;
}