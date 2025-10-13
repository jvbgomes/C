#include <stdio.h>
#include <string.h>

#define MAX_NOME 100

typedef struct {
    char nome[MAX_NOME];
    int telefone;
} tPessoa;

int main() {
    int n;
    scanf("%d", &n);

    tPessoa pessoas[n];

    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", pessoas[i].nome);
        scanf("%d", &pessoas[i].telefone);
    }

    char busca[MAX_NOME];
    scanf(" %[^\n]", busca);

    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(pessoas[i].nome, busca) == 0) {
            printf("O telefone de %s é %d\n", pessoas[i].nome, pessoas[i].telefone);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nome %s não encontrado.\n", busca);
    }

    return 0;
}