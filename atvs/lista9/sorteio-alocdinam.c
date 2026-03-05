#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *my_strdup(const char *s) {
    if (!s) return NULL;
    size_t L = strlen(s) + 1;
    char *p = malloc(L);
    if (p) memcpy(p, s, L);
    return p;
}

int main(void) {
    char line[1024];
    char **participants = NULL;
    size_t n = 0, cap = 0;

    /* ler nomes até "acabou" */
    while (fgets(line, sizeof line, stdin)) {
        size_t L = strlen(line);
        while (L > 0 && (line[L-1] == '\n' || line[L-1] == '\r')) line[--L] = '\0';
        if (L == 0) continue;
        if (strcmp(line, "acabou") == 0) break;

        if (n == cap) {
            size_t nc = cap ? cap * 2 : 8;
            char **tmp = realloc(participants, nc * sizeof *participants);
            if (!tmp) {
                for (size_t i = 0; i < n; ++i) free(participants[i]);
                free(participants);
                return 1;
            }
            participants = tmp;
            cap = nc;
        }
        participants[n] = my_strdup(line);
        if (!participants[n]) {
            for (size_t i = 0; i < n; ++i) free(participants[i]);
            free(participants);
            return 1;
        }
        n++;
    }

    int seed;
    if (scanf("%d", &seed) != 1) {
        for (size_t i = 0; i < n; ++i) free(participants[i]);
        free(participants);
        return 0;
    }

    if (n == 0) {
        /* nada a sortear */
        return 0;
    }

    srand((unsigned)seed);

    unsigned char *picked = calloc(n, 1);
    if (!picked) {
        for (size_t i = 0; i < n; ++i) free(participants[i]);
        free(participants);
        return 1;
    }

    size_t remaining = n;
    while (remaining > 0) {
        int idx = rand() % (int)n;
        if (picked[idx]) continue;
        printf("%s\n", participants[idx]);
        picked[idx] = 1;
        --remaining;
    }

    for (size_t i = 0; i < n; ++i) free(participants[i]);
    free(participants);
    free(picked);
    return 0;
}