#include <stdio.h>
#include <stdlib.h>

int main() {

    int linhas = 5;
    int colunas = 10;
    int** matriz;

    matriz = malloc(sizeof(int*) * linhas);
    for(int i = 0; i < linhas; i++) {
        matriz[i] = malloc(sizeof(int) * (colunas + 1));
    }

    for(int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    printf("Matriz alocada e liberada com sucesso!\n"); 
    
    return 0;
}