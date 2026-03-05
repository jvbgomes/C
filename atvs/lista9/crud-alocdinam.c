#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    int idade;
    char sexo;
} Pessoa;

static Pessoa criar(const char *nome, int idade, char sexo) {
    Pessoa p;
    p.nome = strdup(nome ? nome : "");
    p.idade = idade;
    p.sexo = sexo;
    return p;
}

static void inserir(Pessoa **vet, int *n, int *cap, Pessoa p) {
    if (*n == *cap) {
        int nc = (*cap) ? (*cap * 2) : 8;
        Pessoa *tmp = realloc(*vet, nc * sizeof(Pessoa));
        if (!tmp) return;
        *vet = tmp;
        *cap = nc;
    }
    (*vet)[(*n)++] = p;
}

static int igual(const Pessoa *a, const Pessoa *b) {
    if (a->idade != b->idade) return 0;
    if (a->sexo != b->sexo) return 0;
    if (strcmp(a->nome ? a->nome : "", b->nome ? b->nome : "") != 0) return 0;
    return 1;
}

static void deletar(Pessoa *vet, int *n, const Pessoa *p) {
    for (int i = 0; i < *n; ++i) {
        if (igual(&vet[i], p)) {
            free(vet[i].nome);
            for (int j = i; j + 1 < *n; ++j) vet[j] = vet[j+1];
            (*n)--;
            return; /* apagar apenas a primeira ocorrência */
        }
    }
}

static void imprimir(const Pessoa *vet, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s,%d,%c\n", vet[i].nome ? vet[i].nome : "", vet[i].idade, vet[i].sexo);
    }
}

int main(void) {
    char line[1024];
    Pessoa *vet = NULL;
    int n = 0, cap = 0;

    while (fgets(line, sizeof line, stdin)) {
        /* trim newline */
        size_t L = strlen(line);
        if (L && (line[L-1] == '\n' || line[L-1] == '\r')) line[--L] = '\0';
        if (L == 0) continue;

        char cmd = line[0];
        if (cmd == 'i' || cmd == 'd') {
            char nome[1024];
            char sexo_line[32];
            char idade_line[64];
            if (!fgets(nome, sizeof nome, stdin)) break;
            if (!fgets(idade_line, sizeof idade_line, stdin)) break;
            if (!fgets(sexo_line, sizeof sexo_line, stdin)) break;
            /* trim */
            size_t ln = strlen(nome); if (ln && (nome[ln-1]=='\n' || nome[ln-1]=='\r')) nome[--ln]=0;
            size_t li = strlen(idade_line); if (li && (idade_line[li-1]=='\n' || idade_line[li-1]=='\r')) idade_line[--li]=0;
            size_t ls = strlen(sexo_line); if (ls && (sexo_line[ls-1]=='\n' || sexo_line[ls-1]=='\r')) sexo_line[--ls]=0;
            int idade = atoi(idade_line);
            char sexo = sexo_line[0] ? sexo_line[0] : 'N';
            Pessoa p = criar(nome, idade, sexo);
            if (cmd == 'i') {
                inserir(&vet, &n, &cap, p);
            } else {
                deletar(vet, &n, &p);
                free(p.nome);
            }
        } else if (cmd == 'p') {
            imprimir(vet, n);
            break;
        }
    }

    for (int i = 0; i < n; ++i) free(vet[i].nome);
    free(vet);
    return 0;
}