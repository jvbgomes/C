#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct {
    No* cabeca;
    int tamanho;
} Lista;

void inicializar(Lista* l) {
    l->cabeca = NULL;
    l->tamanho = 0;
}

void inserirInicio(Lista* l, int valor) {
    No* novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao.\n");
        return;
    }
    novo->dado = valor;
    novo->proximo = l->cabeca;
    l->cabeca = novo;
    l->tamanho++;
}

void inserirFim(Lista* l, int valor) {
    No* novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro de alocacao.\n");
        return;
    }
    novo->dado = valor;
    novo->proximo = NULL;

    if (l->cabeca == NULL) {
        l->cabeca = novo;
    } else {
        No* atual = l->cabeca;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    l->tamanho++;
}

int remover(Lista* l, int valor) {
    if (l->cabeca == NULL) return 0;

    if (l->cabeca->dado == valor) {
        No* temp = l->cabeca;
        l->cabeca = l->cabeca->proximo;
        free(temp);
        l->tamanho--;
        return 1;
    }

    No* atual = l->cabeca;
    while (atual->proximo != NULL && atual->proximo->dado != valor) {
        atual = atual->proximo;
    }

    if (atual->proximo == NULL) return 0;

    No* temp = atual->proximo;
    atual->proximo = temp->proximo;
    free(temp);
    l->tamanho--;
    return 1;
}

int buscar(Lista* l, int valor) {
    No* atual = l->cabeca;
    int pos = 0;
    while (atual != NULL) {
        if (atual->dado == valor) return pos;
        atual = atual->proximo;
        pos++;
    }
    return -1;
}

void exibir(Lista* l) {
    if (l->cabeca == NULL) {
        printf("Lista vazia.\n");
        return;
    }
    No* atual = l->cabeca;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d", atual->dado);
        if (atual->proximo != NULL) printf(" -> ");
        atual = atual->proximo;
    }
    printf(" (tamanho: %d)\n", l->tamanho);
}

void liberar(Lista* l) {
    No* atual = l->cabeca;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    l->cabeca = NULL;
    l->tamanho = 0;
}

int main() {
    Lista l;
    inicializar(&l);

    inserirFim(&l, 10);
    inserirFim(&l, 20);
    inserirFim(&l, 30);
    inserirInicio(&l, 5);

    exibir(&l);

    printf("Buscar 20: posicao %d\n", buscar(&l, 20));
    printf("Buscar 99: posicao %d\n", buscar(&l, 99));

    remover(&l, 20);
    exibir(&l);

    remover(&l, 5);
    exibir(&l);

    liberar(&l);
    printf("Memoria liberada.\n");

    return 0;
}
