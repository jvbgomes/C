#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n_cartelas, seed_sorteio;
    if (scanf("%d %d", &n_cartelas, &seed_sorteio) != 2) return 0;
    if (n_cartelas < 1) return 0;
    if (n_cartelas > 50) n_cartelas = 50;

    int cards[50][10];
    int i, j;
    for (i = 0; i < n_cartelas; ++i) {
        int used[26] = {0};
        int cnt = 0;
        srand(i + 1);
        while (cnt < 10) {
            int r = (rand() % 25) + 1;
            if (!used[r]) {
                used[r] = 1;
                cards[i][cnt++] = r;
            }
        }
    }

    int drawnSeq[25];
    int drawCount = 0;
    int drawnFlag[26] = {0};
    int markedCount[50] = {0};
    int marked[50][26] = {{0}};

    srand(seed_sorteio);
    int winner = -1;
    while (drawCount < 25 && winner == -1) {
        int r = (rand() % 25) + 1;
        if (drawnFlag[r]) continue;
        drawnFlag[r] = 1;
        drawnSeq[drawCount++] = r;

        for (i = 0; i < n_cartelas && winner == -1; ++i) {
            for (j = 0; j < 10; ++j) {
                if (cards[i][j] == r) {
                    if (!marked[i][r]) {
                        marked[i][r] = 1;
                        markedCount[i]++;
                        if (markedCount[i] == 10) {
                            winner = i + 1;
                            break;
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < drawCount; ++i) {
        if (i) printf(" ");
        printf("%d", drawnSeq[i]);
    }
    printf("\n");
    if (winner != -1) {
        printf("Bingo! Cartela %d: ", winner);
        int idx = winner - 1;
        for (j = 0; j < 10; ++j) {
            if (j) printf(" ");
            printf("%d", cards[idx][j]);
        }
        printf("\n");
    }

    return 0;
}