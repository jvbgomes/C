#include <stdio.h>
#include <stdlib.h>

char** mapa[5][10+1];
int linhas;
int colunas;

int main() { 

    FILE* f;
    f = fopen("mapa.txt", "r");
    if (f == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    printf("Linhas: %d, Colunas: %d\n", linhas, colunas);

    mapa = malloc(sizeof(char*) * linhas);
    for(int i = 0; i < linhas; i++) {
        mapa[i] = malloc(sizeof(char) * (colunas + 1));
    }

    for(int i = 0; i < 5; i++) {
        fscanf(f, "%s", mapa[i]);
    }

    for(int i = 0; i < 5; i++) {
        printf("%s\n", mapa[i]);
    }

    fclose(f);

    for(int i = 0; i < linhas; i++) {
        free(mapa[i]);
    }
    free(mapa);

    return 0;
}


