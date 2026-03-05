#include <stdio.h>
#include <string.h>

#define MAX_PESSOAS 1000
#define MAX_NOME 51

typedef struct {
    char nome[MAX_NOME];
    int idade;
    char sexo;
} Pessoa;

Pessoa criar(char nome[], int idade, char sexo) {
    Pessoa p;
    strncpy(p.nome, nome, MAX_NOME);
    p.nome[MAX_NOME-1] = '\0';
    p.idade = idade;
    p.sexo = sexo;
    return p;
}

void inserir(Pessoa vetor[], int *n, Pessoa p) {
    vetor[*n] = p;
    (*n)++;
}

void deletar(Pessoa vetor[], int *n, Pessoa p) {
    int i, j;
    for (i = 0; i < *n; i++) {
        if (strcmp(vetor[i].nome, p.nome) == 0 && vetor[i].idade == p.idade && vetor[i].sexo == p.sexo) {
            for (j = i; j < *n - 1; j++) {
                vetor[j] = vetor[j + 1];
            }
            (*n)--;
            break;
        }
    }
}

void imprimir(Pessoa vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s,%d,%c\n", vetor[i].nome, vetor[i].idade, vetor[i].sexo);
    }
}

int main() {
    Pessoa vetor[MAX_PESSOAS];
    int n = 0;
    char comando;
    char nome[MAX_NOME];
    int idade;
    char sexo;

    while (1) {
        scanf(" %c", &comando);
        if (comando == 'i') {
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            Pessoa p = criar(nome, idade, sexo);
            inserir(vetor, &n, p);
        } else if (comando == 'd') {
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            Pessoa p = criar(nome, idade, sexo);
            deletar(vetor, &n, p);
        } else if (comando == 'p') {
            imprimir(vetor, n);
            break;
        }
    }
    return 0;
}