#include <stdio.h>
#include <string.h>
#include <ctype.h>

static int clamp(int v) {
    if (v < 0) return 0;
    if (v > 100) return 100;
    return v;
}

void imprime_relatorio(int fome, int sede, int banheiro, int sono, int tedio) {
    printf("Status final:\n");
    printf("Fome: %d\n", fome);
    printf("Sede: %d\n", sede);
    printf("Banheiro: %d\n", banheiro);
    printf("Sono: %d\n", sono);
    printf("Tédio: %d\n", tedio);
}

int simula_sims(int *pfome, int *psede, int *pbanheiro, int *psono, int *ptedio) {
    char buf[128];
    if (fgets(buf, sizeof(buf), stdin) == NULL) return 0;
    size_t L = strlen(buf);
    while (L > 0 && (buf[L-1] == '\n' || buf[L-1] == '\r')) { buf[--L] = '\0'; }
    char *s = buf;
    while (*s && isspace((unsigned char)*s)) s++;
    char cmd[128];
    size_t i;
    for (i = 0; i < sizeof(cmd)-1 && s[i]; i++) cmd[i] = (char)tolower((unsigned char)s[i]);
    cmd[i] = '\0';

    int fome = *pfome, sede = *psede, banheiro = *pbanheiro, sono = *psono, tedio = *ptedio;
    int diret[5] = {0,0,0,0,0};

    if (strcmp(cmd, "comer") == 0) {
        fome += 30; diret[0]=1;
        banheiro -= 15; diret[2]=1;
    } else if (strcmp(cmd, "beber") == 0) {
        sede += 30; diret[1]=1;
        banheiro -= 20; diret[2]=1;
    } else if (strcmp(cmd, "dormir") == 0) {
        sono += 80; diret[3]=1;
        tedio += 30; diret[4]=1;
        fome -= 30; diret[0]=1;
        sede -= 30; diret[1]=1;
        banheiro -= 30; diret[2]=1;
    } else if (strcmp(cmd, "se aliviar") == 0 || strcmp(cmd, "sealiviar") == 0) {
        banheiro += 100; diret[2]=1;
    } else if (strcmp(cmd, "jogar videogame") == 0 || strcmp(cmd, "jogarvideogame") == 0) {
        tedio += 80; diret[4]=1;
        fome -= 20; diret[0]=1;
        sede -= 20; diret[1]=1;
        banheiro -= 20; diret[2]=1;
        sono -= 20; diret[3]=1;
    }

    if (!diret[0]) fome -= 5;
    if (!diret[1]) sede -= 5;
    if (!diret[2]) banheiro -= 5;
    if (!diret[3]) sono -= 5;
    if (!diret[4]) tedio -= 5;

    fome = clamp(fome);
    sede = clamp(sede);
    banheiro = clamp(banheiro);
    sono = clamp(sono);
    tedio = clamp(tedio);

    *pfome = fome; *psede = sede; *pbanheiro = banheiro; *psono = sono; *ptedio = tedio;

if (fome == 0) { printf("Game Over! Morreu de fome\n"); return 0; }
if (sede == 0) { printf("Game Over! Morreu de sede\n"); return 0; }
if (banheiro == 0) { printf("Game Over! Morreu apertado...\n"); return 0; }
if (sono == 0) { printf("Game Over! Morreu dormindo...\n"); return 0; }
if (tedio == 0) { printf("Game Over! Morreu deprimido...\n"); return 0; }

if (fome > 0 && fome <= 15) printf("Alerta: fome está com valor baixo\n");
if (sede > 0 && sede <= 15) printf("Alerta: sede está com valor baixo\n");
if (banheiro > 0 && banheiro <= 15) printf("Alerta: banheiro está com valor baixo\n");
if (sono > 0 && sono <= 15) printf("Alerta: sono está com valor baixo\n");
if (tedio > 0 && tedio <= 15) printf("Alerta: tédio está com valor baixo\n");

    return 1;
}

int main() {
    int fome, sede, banheiro, sono, tedio;
    int acoes;
    if (scanf("%d %d %d %d %d", &fome, &sede, &banheiro, &sono, &tedio) != 5) return 0;
    if (scanf("%d", &acoes) != 1) return 0;
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) { }

    for (int i = 0; i < acoes; i++) {
        int ret = simula_sims(&fome, &sede, &banheiro, &sono, &tedio);
        if (ret == 0) break;
    }

    imprime_relatorio(fome, sede, banheiro, sono, tedio);
    return 0;
}