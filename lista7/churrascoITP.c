#include <stdio.h>
#include <string.h>

#define MAX_ITENS 100
#define MAX_NOME 50

typedef struct {
    char nome[MAX_NOME];
    float preco;
    int quantidade;
} Item;

int main() {
    Item itens[MAX_ITENS];
    int total_itens = 0;
    int continuar = 1;
    float total = 0.0;
    int pessoas;

    while (continuar == 1 && total_itens < MAX_ITENS) {
        scanf(" %[^\n]", itens[total_itens].nome);
        scanf("%f", &itens[total_itens].preco);
        scanf("%d", &itens[total_itens].quantidade);

        total += itens[total_itens].preco * itens[total_itens].quantidade;

        scanf("%d", &continuar);

        total_itens++;
    }

    scanf("%d", &pessoas);

    printf("Valor: R$ %.2f\n", total);
    printf("Divisão R$ %.2f para cada participante.\n", total / pessoas);

    return 0;
}