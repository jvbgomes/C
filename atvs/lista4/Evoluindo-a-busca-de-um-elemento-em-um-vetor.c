#include <stdio.h>
#include <string.h>

int main() {
    char frutas[8][50];
    char busca[50];

    // Lê os 8 nomes
    for (int i = 0; i < 8; i++) {
        scanf("%49s", frutas[i]);
    }

    // Lê o nome a ser buscado
    scanf("%49s", busca);

    // Para cada posição, informa se encontrou ou não
    for (int i = 0; i < 8; i++) {
        if (strcmp(frutas[i], busca) == 0)
            printf("encontrei\n");
        else
            printf("não\n");
    }

    return 0;
}