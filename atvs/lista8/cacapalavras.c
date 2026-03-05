#include <stdio.h>
#include <string.h>
#include <ctype.h>

void imprimePalavra(char *c, int salto, int tam) {
    if (c == NULL) {
        printf("Palavra nao encontrada\n");
        return;
    }
    for (int i = 0; i < tam; i++) {
        printf("%c", *c);
        c += salto;
    }
    printf(", salto:%d\n", salto);
}

/* Retorna ponteiro para o primeiro caractere encontrado na matriz linearizada (10x10),
   seta *salto com o passo entre caracteres; retorna NULL se não encontrado. */
char *localiza(char *mat, const char *pal, int *salto) {
    int len = (int)strlen(pal);
    if (len == 0) {
        *salto = 0;
        return NULL;
    }

    /* direções: dr,dc */
    int dirs[8][2] = {
        {-1,-1}, {-1,0}, {-1,1},
        { 0,-1},         { 0,1},
        { 1,-1}, { 1,0}, { 1,1}
    };

    for (int idx = 0; idx < 100; idx++) {
        if (tolower((unsigned char)mat[idx]) != tolower((unsigned char)pal[0])) continue;
        int r = idx / 10;
        int c = idx % 10;

        for (int d = 0; d < 8; d++) {
            int dr = dirs[d][0];
            int dc = dirs[d][1];
            int r_end = r + dr * (len - 1);
            int c_end = c + dc * (len - 1);
            if (r_end < 0 || r_end >= 10 || c_end < 0 || c_end >= 10) continue;

            int k;
            for (k = 0; k < len; k++) {
                int rr = r + dr * k;
                int cc = c + dc * k;
                int id = rr * 10 + cc;
                if (tolower((unsigned char)mat[id]) != tolower((unsigned char)pal[k])) break;
            }
            if (k == len) {
                *salto = dr * 10 + dc;
                return &mat[idx];
            }
        }
    }

    *salto = 0;
    return NULL;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n < 0) n = 0;
    if (n > 5) n = 5;

    char palavras[5][101];
    for (int i = 0; i < n; i++) {
        scanf("%100s", palavras[i]);
    }

    char linha[128];
    char mat[100];
    for (int i = 0; i < 10; i++) {
        scanf("%127s", linha);
        for (int j = 0; j < 10; j++) {
            mat[i * 10 + j] = linha[j];
        }
    }

    for (int i = 0; i < n; i++) {
        int salto;
        char *pos = localiza(mat, palavras[i], &salto);
        imprimePalavra(pos, salto, (int)strlen(palavras[i]));
    }

    return 0;
}