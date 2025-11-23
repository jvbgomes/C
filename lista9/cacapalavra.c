#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int in_bounds(int r, int c, int L, int C) {
    return r >= 0 && r < L && c >= 0 && c < C;
}

int main(void) {
    int N, L, C;
    if (scanf("%d %d %d", &N, &L, &C) != 3) return 0;
    getchar();

    char **words = malloc((size_t)N * sizeof(char*));
    if (!words) return 1;
    char buf[1024];
    for (int i = 0; i < N; ++i) {
        if (!fgets(buf, sizeof buf, stdin)) { words[i] = strdup(""); continue; }
        size_t ln = strlen(buf);
        if (ln && buf[ln-1] == '\n') buf[--ln] = '\0';
        words[i] = strdup(buf);
        if (!words[i]) words[i] = strdup("");
    }

    char **grid = malloc((size_t)L * sizeof(char*));
    if (!grid) { for (int i=0;i<N;i++) free(words[i]); free(words); return 1; }
    for (int r = 0; r < L; ++r) {
        grid[r] = malloc((size_t)C + 1);
        if (!grid[r]) {
            for (int k=0;k<r;k++) free(grid[k]);
            free(grid);
            for (int i=0;i<N;i++) free(words[i]);
            free(words);
            return 1;
        }
        int got = 0;
        while (got < C) {
            int ch = getchar();
            if (ch == EOF) break;
            if (ch == '\n' || ch == '\r') continue;
            grid[r][got++] = (char)ch;
        }
        grid[r][C] = '\0';
    }

    const int dr[8] = { -1,  1,  0,  0, -1,  1, -1,  1 };
    const int dc[8] = {  0,  0, -1,  1, -1, -1,  1,  1 };
    const char dcode[8] = { 'c', 'b', 'e', 'd', '1', '2', '3', '4' };

    for (int w = 0; w < N; ++w) {
        const char *pat = words[w];
        int plen = (int)strlen(pat);
        int found = 0;
        int out_r = 0, out_c = 0;
        char out_dir = '0';
        char *out_word_from_grid = NULL;

        for (int r = 0; r < L && !found; ++r) {
            for (int c = 0; c < C && !found; ++c) {
                for (int d = 0; d < 8 && !found; ++d) {
                    int rr = r, cc = c;
                    int k;
                    for (k = 0; k < plen; ++k) {
                        if (!in_bounds(rr, cc, L, C)) break;
                        char a = tolower((unsigned char)grid[rr][cc]);
                        char b = tolower((unsigned char)pat[k]);
                        if (a != b) break;
                        rr += dr[d];
                        cc += dc[d];
                    }
                    if (k == plen) {
                        found = 1;
                        out_r = r;
                        out_c = c;
                        out_dir = dcode[d];
                        out_word_from_grid = malloc((size_t)plen + 1);
                        if (!out_word_from_grid) out_word_from_grid = strdup("");
                        else {
                            rr = r; cc = c;
                            for (int t = 0; t < plen; ++t) {
                                out_word_from_grid[t] = grid[rr][cc];
                                rr += dr[d];
                                cc += dc[d];
                            }
                            out_word_from_grid[plen] = '\0';
                        }
                    }
                }
            }
        }

        if (found) {
            printf("%s,%d,%d,%c\n", out_word_from_grid ? out_word_from_grid : words[w], out_r, out_c, out_dir);
            free(out_word_from_grid);
        } else {
            printf("%s,0,0,0\n", words[w]);
        }
    }

    for (int r = 0; r < L; ++r) free(grid[r]);
    free(grid);
    for (int i = 0; i < N; ++i) free(words[i]);
    free(words);
    return 0;
}