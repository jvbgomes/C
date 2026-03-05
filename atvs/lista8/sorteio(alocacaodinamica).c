#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char buffer[512];
    char **participants = NULL;
    size_t n = 0, cap = 0;

    while (fgets(buffer, sizeof buffer, stdin)) {
        size_t len = strlen(buffer);
        if (len && buffer[len-1] == '\n') buffer[len-1] = '\0';
        if (strcmp(buffer, "acabou") == 0) break;

        char *name = malloc(strlen(buffer) + 1);
        if (!name) { perror("malloc"); return 1; }
        strcpy(name, buffer);

        if (n == cap) {
            size_t newcap = cap ? cap * 2 : 8;
            char **tmp = realloc(participants, newcap * sizeof *participants);
            if (!tmp) { perror("realloc"); return 1; }
            participants = tmp;
            cap = newcap;
        }
        participants[n++] = name;
    }

    int seed;
    if (scanf("%d", &seed) != 1) seed = 1;
    if (n == 0) return 0;

    srand((unsigned)seed);

    unsigned char *picked = calloc(n, 1);
    if (!picked) { perror("calloc"); return 1; }

    size_t drawn = 0;
    while (drawn < n) {
        size_t idx = (size_t) (rand() % (int)n);
        if (!picked[idx]) {
            printf("%s\n", participants[idx]);
            picked[idx] = 1;
            drawn++;
        }
    }

    for (size_t i = 0; i < n; ++i) free(participants[i]);
    free(participants);
    free(picked);
    return 0;
}