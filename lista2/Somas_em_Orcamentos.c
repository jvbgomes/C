#include <stdio.h>

int main() {
    int quantidade, total_itens = 0;
    double valor_unitario, total_orcamento = 0.0;

    while (1) {
        scanf("%d", &quantidade);
        if (quantidade == -1) {
            break;
        }
        scanf("%lf", &valor_unitario);
        total_itens += quantidade;
        total_orcamento += quantidade * valor_unitario;
    }

    printf("%d %.2lf", total_itens, total_orcamento);

    return 0;
}