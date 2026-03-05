#include <stdio.h>

int main() {
    int t1, t2;
    scanf("%d", &t1);
    int v1[t1];
    for (int i = 0; i < t1; i++) {
        scanf("%d", &v1[i]);
    }
    scanf("%d", &t2);
    int v2[t2];
    for (int i = 0; i < t2; i++) {
        scanf("%d", &v2[i]);
    }

    int v3[t1 + t2];
    for (int i = 0; i < t1; i++) {
        v3[i] = v1[i];
    }
    for (int i = 0; i < t2; i++) {
        v3[t1 + i] = v2[i];
    }

    for (int i = 0; i < t1 + t2; i++) {
        printf("%d ", v3[i]);
    }
    printf("\n");

    return 0;
}