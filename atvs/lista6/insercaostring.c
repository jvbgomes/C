#include <stdio.h>
#include <string.h>

void insere_string(const char *s1, const char *s2, char *s3, int p) {
    strncpy(s3, s1, p);
    s3[p] = '\0';
    strcat(s3, s2);
    strcat(s3, s1 + p);
}

int main() {
    char s1[52];
    char s2[52];
    char s3[104];
    int p;

    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0;

    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0;

    scanf("%d", &p);

    insere_string(s1, s2, s3, p);

    printf("%s\n", s3);

    return 0;
}