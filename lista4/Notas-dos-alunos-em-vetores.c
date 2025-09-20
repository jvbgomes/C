#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int aprovados[n], rec[n], reprovados[n];
    float notas[n];
    int i, ap = 0, rp = 0, rr = 0;
    int num;
    float nota;

    for (i = 0; i < n; i++) {
        scanf("%d - %f", &num, &nota);
        notas[num - 1] = nota;
    }

    for (i = 0; i < n; i++) {
        nota = notas[i];
        if (nota >= 7.0)
            aprovados[ap++] = i + 1;
        else if (nota >= 5.0)
            rec[rp++] = i + 1;
        else
            reprovados[rr++] = i + 1;
    }

    printf("Aprovados:");
    for (i = 0; i < ap; i++) {
        printf(" %d (%.1f)", aprovados[i], notas[aprovados[i] - 1]);
        if (i < ap - 1) printf(",");
    }
    printf("\n");

    printf("Recuperação:");
    for (i = 0; i < rp; i++) {
        printf(" %d (%.1f)", rec[i], notas[rec[i] - 1]);
        if (i < rp - 1) printf(",");
    }
    printf("\n");

    printf("Reprovados:");
    for (i = 0; i < rr; i++) {
        printf(" %d (%.1f)", reprovados[i], notas[reprovados[i] - 1]);
        if (i < rr - 1) printf(",");
    }
    printf("\n");

    return 0;
}