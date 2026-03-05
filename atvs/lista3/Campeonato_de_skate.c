#include <stdio.h>

// Função para calcular o score do dia (nem o maior, nem o menor)
int scoreDia(int a, int b, int c) {
    if ((a == b) || (a == c)) return a;
    if (b == c) return b;
    // Se todos diferentes, retorna o do meio
    if ((a > b && a < c) || (a < b && a > c)) return a;
    if ((b > a && b < c) || (b < a && b > c)) return b;
    return c;
}

// Função para calcular o score final do skatista
int scoreFinal(int scores[9]) {
    int dia1 = scoreDia(scores[0], scores[1], scores[2]);
    int dia2 = scoreDia(scores[3], scores[4], scores[5]);
    int dia3 = scoreDia(scores[6], scores[7], scores[8]);
    return scoreDia(dia1, dia2, dia3);
}

int main() {
    int scoresA[9], scoresB[9];
    for (int i = 0; i < 9; i++) scanf("%d", &scoresA[i]);
    for (int i = 0; i < 9; i++) scanf("%d", &scoresB[i]);

    int finalA = scoreFinal(scoresA);
    int finalB = scoreFinal(scoresB);

    if (finalA > finalB)
        printf("A\n");
    else if (finalB > finalA)
        printf("B\n");
    else
        printf("empate\n");

    return 0;
}