#include <stdio.h>
#include <string.h>

int main() {
    char s1[52];
    char s2[52];

    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0;

    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0;

    if (strstr(s1, s2) != NULL) {
        printf("É substring\n");
    } else {
        printf("Não é substring\n");
    }

    return 0;
}