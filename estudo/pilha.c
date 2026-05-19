#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct {
    int dados[TAMANHO_MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int estaVazia(Pilha* p) {
    return p->topo == -1;
}

int estaCheia(Pilha* p) {
    return p->topo == TAMANHO_MAX - 1;
}

void empilhar(Pilha* p, int valor) {
    if (estaCheia(p)) {
        printf("Pilha cheia! Nao foi possivel empilhar %d\n", valor);
        return;
    }
    p->topo++;
    p->dados[p->topo] = valor;
    printf("Empilhou: %d\n", valor);
}

int desempilhar(Pilha* p) {
    if (estaVazia(p)) {
        printf("Pilha vazia! Nao ha elementos para desempilhar.\n");
        return -1;
    }
    int valor = p->dados[p->topo];
    p->topo--;
    printf("Desempilhou: %d\n", valor);
    return valor;
}

int topo(Pilha* p) {
    if (estaVazia(p)) {
        printf("Pilha vazia.\n");
        return -1;
    }
    return p->dados[p->topo];
}

void exibirPilha(Pilha* p) {
    if (estaVazia(p)) {
        printf("Pilha vazia.\n");
        return;
    }
    printf("Pilha (topo -> base): ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializar(&p);

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);
    empilhar(&p, 40);

    exibirPilha(&p);

    printf("Topo atual: %d\n", topo(&p));

    desempilhar(&p);
    desempilhar(&p);

    exibirPilha(&p);

    empilhar(&p, 99);

    exibirPilha(&p);

    return 0;
}
