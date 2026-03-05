#include <stdio.h>

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

    for (int i = 0; i < n; i++) {
        printf("O telefone de %s é %d\n", pessoas[i].nome, pessoas[i].telefone);
    }

    return 0;
}