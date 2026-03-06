#include <stdio.h>
#include <string.h>
#include <ctype.h>

void string_para_minusculas(char *str_destino, const char *str_origem) {
    int i = 0;
    while (str_origem[i]) {
        str_destino[i] = tolower(str_origem[i]);
        i++;
    }
    str_destino[i] = '\0';
}

int main() {
    char strA[42], strB[42];
    char lowerA[42], lowerB[42];
    int posicoes[41];
    int contador = 0;

    fgets(strA, sizeof(strA), stdin);
    strA[strcspn(strA, "\n")] = 0;

    fgets(strB, sizeof(strB), stdin);
    strB[strcspn(strB, "\n")] = 0;

    string_para_minusculas(lowerA, strA);
    string_para_minusculas(lowerB, strB);

    int lenA = strlen(lowerA);
    int lenB = strlen(lowerB);

    if (lenA > 0 && lenB >= lenA) {
        for (int i = 0; i <= lenB - lenA; i++) {
            if (strncmp(&lowerB[i], lowerA, lenA) == 0) {
                posicoes[contador] = i;
                contador++;
            }
        }
    }

    printf("Repetições: %d\n", contador);

    // CORREÇÃO: Só imprime a linha "Posições:" se houver alguma ocorrência.
    if (contador > 0) {
        printf("Posições:");
        for (int i = 0; i < contador; i++) {
            printf(" %d", posicoes[i]);
        }
        printf("\n");
    }

    return 0;
}