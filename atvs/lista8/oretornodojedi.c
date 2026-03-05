#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *my_strdup(const char *s) {
    if (!s) return NULL;
    size_t l = strlen(s) + 1;
    char *p = malloc(l);
    if (p) memcpy(p, s, l);
    return p;
}

char **separa(const char *str, int *quantidade) {
    *quantidade = 0;
    if (!str) return NULL;
    char *dup = my_strdup(str);
    if (!dup) return NULL;
    char **vet = NULL;
    int cap = 0, n = 0;
    char *tok = strtok(dup, " ");
    while (tok) {
        if (n == cap) {
            int newcap = cap ? cap * 2 : 8;
            char **tmp = realloc(vet, newcap * sizeof *vet);
            if (!tmp) { perror("realloc"); free(dup); for (int i=0;i<n;i++) free(vet[i]); free(vet); return NULL; }
            vet = tmp;
            cap = newcap;
        }
        vet[n++] = my_strdup(tok);
        tok = strtok(NULL, " ");
    }
    free(dup);
    *quantidade = n;
    return vet;
}

char *embaralha(const char *texto) {
    int N = 0;
    char **M = separa(texto, &N);
    if (!M) return my_strdup("");
    if (N == 0) { free(M); return my_strdup(""); }
    unsigned char *seen = calloc((size_t)N, 1);
    if (!seen) { perror("calloc"); for (int i=0;i<N;i++) free(M[i]); free(M); return NULL; }
    char **E = NULL;
    int capE = 0, k = 0;
    int remaining = N;
    srand(5940);
    while (1) {
        int r = rand();
        int idx = r % N;
        if (k == capE) {
            int nc = capE ? capE * 2 : 8;
            char **tmp = realloc(E, nc * sizeof *E);
            if (!tmp) { perror("realloc"); break; }
            E = tmp;
            capE = nc;
        }
        E[k++] = M[idx];
        if (!seen[idx]) {
            seen[idx] = 1;
            remaining--;
            if (remaining == 0) break;
        }
    }
    size_t total = 1;
    for (int i = 0; i < k; ++i) total += strlen(E[i]);
    if (k > 1) total += (size_t)(k - 1);
    char *res = malloc(total);
    if (!res) { perror("malloc"); res = my_strdup(""); }
    else {
        res[0] = '\0';
        for (int i = 0; i < k; ++i) {
            if (i) strcat(res, " ");
            strcat(res, E[i]);
        }
    }
    free(E);
    free(seen);
    for (int i = 0; i < N; ++i) free(M[i]);
    free(M);
    return res;
}

int main(void) {
    char buf[600];
    if (!fgets(buf, sizeof buf, stdin)) return 0;
    size_t l = strlen(buf);
    if (l && buf[l-1] == '\n') buf[l-1] = '\0';
    char *saida = embaralha(buf);
    if (saida) {
        printf("%s\n", saida);
        free(saida);
    }
    return 0;
}