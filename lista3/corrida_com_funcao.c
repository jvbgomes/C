#include <stdio.h>

int tempoAlcance(int X, int V1, int V2) {
    if (V1 <= V2) return -1;
    return (X + (V1 - V2) - 1) / (V1 - V2);
}

int main() {
    int X, V1, V2;
    scanf("%d %d %d", &X, &V1, &V2);

    int t = tempoAlcance(X, V1, V2);
    if (t == -1)
        printf("impossivel\n");
    else
        printf("%ds\n", t);

    return 0;
}