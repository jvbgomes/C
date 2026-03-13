#include <stdio.h>

void potencia(int* resultado ,int a, int b) {
    *resultado = 1;
    for(int i = 0; i < b; i++) {
        *resultado *= a;
    }


}

int main() {
    int resultado = 1;
    int x, y;
    printf("Digite a base e seu expoente: ");
    scanf("%d %d", &x, &y);

    potencia(&resultado, x, y);

    printf("A potencia de %d^%d e %d\n", x, y, resultado);

    return 0;
}