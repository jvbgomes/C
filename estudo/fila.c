#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct {
    int dados[TAMANHO_MAX];
    int inicio;
    int fim;
    int qtd;
} Fila;

void inicializar(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->qtd = 0;
}

int estaVazia(Fila* f) {
    return f->qtd == 0;
}

int estaCheia(Fila* f) {
    return f->qtd == TAMANHO_MAX;
}

void enfileirar(Fila* f, int valor) {
    if (estaCheia(f)) {
        printf("Fila cheia! Nao foi possivel enfileirar %d\n", valor);
        return;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % TAMANHO_MAX;
    f->qtd++;
    printf("Enfileirou: %d\n", valor);
}

int desenfileirar(Fila* f) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % TAMANHO_MAX;
    f->qtd--;
    printf("Desenfileirou: %d\n", valor);
    return valor;
}

int frente(Fila* f) {
    if (estaVazia(f)) {
        printf("Fila vazia.\n");
        return -1;
    }
    return f->dados[f->inicio];
}

void exibirFila(Fila* f) {
    if (estaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }
    printf("Fila (frente -> tras): ");
    for (int i = 0; i < f->qtd; i++) {
        printf("%d ", f->dados[(f->inicio + i) % TAMANHO_MAX]);
    }
    printf("\n");
}

int main() {
    Fila f;
    inicializar(&f);

    enfileirar(&f, 100);
    enfileirar(&f, 200);
    enfileirar(&f, 300);
    enfileirar(&f, 400);

    exibirFila(&f);
    printf("Frente: %d\n", frente(&f));

    desenfileirar(&f);
    desenfileirar(&f);

    exibirFila(&f);

    enfileirar(&f, 500);
    enfileirar(&f, 600);

    exibirFila(&f);

    return 0;
}
