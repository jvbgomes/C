#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int *parse_line_to_array(char *line, size_t *out_len) {
    int *arr = NULL;
    size_t cap = 0, n = 0;
    char *token = strtok(line, " \t\r\n");
    while (token) {
        long v = strtol(token, NULL, 10);
        if (n == cap) {
            size_t nc = cap ? cap * 2 : 8;
            int *tmp = realloc(arr, nc * sizeof *arr);
            if (!tmp) { free(arr); return NULL; }
            arr = tmp;
            cap = nc;
        }
        arr[n++] = (int)v;
        token = strtok(NULL, " \t\r\n");
    }
    *out_len = n;
    return arr;
}

int main(void) {
    char buf1[4096];
    char buf2[4096];
    if (!fgets(buf1, sizeof buf1, stdin)) return 0;
    if (!fgets(buf2, sizeof buf2, stdin)) return 0;

    size_t n1 = 0, n2 = 0;
    char *dup1 = strdup(buf1);
    char *dup2 = strdup(buf2);
    if (!dup1 || !dup2) { free(dup1); free(dup2); return 1; }

    int *a = parse_line_to_array(dup1, &n1);
    int *b = parse_line_to_array(dup2, &n2);

    free(dup1);
    free(dup2);

    if (!a || !b) { free(a); free(b); return 1; }

    if (n1 != n2) {
        printf("Vetores de tamanhos diferentes!\n");
        free(a); free(b);
        return 0;
    }

    for (size_t i = 0; i < n1; ++i) {
        if (i) printf(" ");
        printf("%d", a[i] + b[i]);
    }
    printf("\n");

    free(a);
    free(b);
    return 0;
}