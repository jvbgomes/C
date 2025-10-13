#include <stdio.h>
#include <string.h>

#define MAX_CHOCOLATES 100
#define MAX_NOME 51

typedef enum {
    BRANCO,
    AMARGO,
    AO_LEITE,
    COM_CASTANHAS,
    TIPO_INVALIDO
} TipoChocolates;

typedef struct {
    char nome[MAX_NOME];
    float peso;
    float preco;
    TipoChocolates tipo;
} Chocolate;

TipoChocolates getTipo(const char *str) {
    if (strcmp(str, "BRANCO") == 0) return BRANCO;
    if (strcmp(str, "AMARGO") == 0) return AMARGO;
    if (strcmp(str, "AO_LEITE") == 0) return AO_LEITE;
    if (strcmp(str, "COM_CASTANHAS") == 0) return COM_CASTANHAS;
    return TIPO_INVALIDO;
}

int main() {
    int n;
    scanf("%d", &n);

    Chocolate chocolates[MAX_CHOCOLATES];
    int total[4] = {0, 0, 0, 0};
    char tipoStr[MAX_NOME];

    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", chocolates[i].nome);
        scanf("%f", &chocolates[i].peso);
        scanf("%f", &chocolates[i].preco);
        scanf(" %[^\n]", tipoStr);

        chocolates[i].tipo = getTipo(tipoStr);

        if (chocolates[i].tipo != TIPO_INVALIDO) {
            total[chocolates[i].tipo]++;
        }
    }

    printf("Total de chocolates BRANCO: %d\n", total[BRANCO]);
    printf("Total de chocolates AMARGO: %d\n", total[AMARGO]);
    printf("Total de chocolates AO_LEITE: %d\n", total[AO_LEITE]);
    printf("Total de chocolates COM_CASTANHAS: %d\n", total[COM_CASTANHAS]);

    int idx_caro = 0, idx_barato = 0;
    for (int i = 1; i < n; i++) {
        if (chocolates[i].preco > chocolates[idx_caro].preco)
            idx_caro = i;
        if (chocolates[i].preco < chocolates[idx_barato].preco)
            idx_barato = i;
    }

    printf("Chocolate mais caro: %s - R$%.2f\n", chocolates[idx_caro].nome, chocolates[idx_caro].preco);
    printf("Chocolate mais barato: %s - R$%.2f\n", chocolates[idx_barato].nome, chocolates[idx_barato].preco);

    return 0;
}