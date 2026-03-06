#include <stdio.h>
#define TAM1 3
#define TAM2 2

int main() {

    int matriz1[TAM1][TAM1], matriz2[TAM1][TAM1], matriz3[TAM1][TAM2];
    int resultadoSoma[TAM1][TAM1], resultadoMulti[TAM1][TAM2];
    int i, j, k;

    //LEITURA DAS MATRIZES

    for(i = 0; i < TAM1; i++) {
        for(j = 0; j < TAM1; j++) {
            scanf("%d", &matriz1[i][j]);
        }
    }
    for(i = 0; i < TAM1; i++) {
        for(j = 0; j < TAM1; j++) {
            scanf("%d", &matriz2[i][j]);
        }
    }
    for(i = 0; i < TAM1; i++) {
        for(j = 0; j < TAM2; j++) {
            scanf("%d", &matriz3[i][j]);
        }
    }
    //SOMA DAS MATRIZES

    for(i = 0; i < TAM1; i++) {
        for(j = 0; j < TAM1; j++) {
            resultadoSoma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    printf("Soma das matrizes 1 e 2:\n");
    for(i = 0; i < TAM1; i++) {
        for(j = 0; j < TAM1; j++) {
            printf("%d ", resultadoSoma[i][j]);
        }
        printf("\n");
    }

    //MULTIPLICAÇÃO DA MATRIZ 2 COM A 3
    for(i = 0; i < TAM1; i++) {
        for(j = 0; j < TAM2; j++) {
            resultadoMulti[i][j] = 0;
            for(k = 0; k < TAM1; k++) {
                resultadoMulti[i][j] += matriz1[i][k] * matriz3[k][j];
            }
        }
    }

    printf("Multiplicação das matrizes 2 e 3:\n");
    for(i = 0; i < TAM1; i++) {
        for(j = 0; j < TAM2; j++) {
            printf("%d ", resultadoMulti[i][j]);
        }
        printf("\n");
    }

    return 0;
}