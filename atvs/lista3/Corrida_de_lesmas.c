#include <stdio.h>

// Função que retorna o level da lesma conforme sua velocidade
int getLevel(int velocidade) {
    if (velocidade < 10)
        return 1;
    else if (velocidade < 20)
        return 2;
    else
        return 3;
}

int main() {
    int N, i, velocidade, maiorLevel = 1;
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &velocidade);
        int level = getLevel(velocidade);
        if (level > maiorLevel)
            maiorLevel = level;
    }

    printf("Level %d\n", maiorLevel);
    
    return 0;

}