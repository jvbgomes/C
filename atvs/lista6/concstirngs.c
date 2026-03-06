#include <stdio.h>
#include <string.h>

int main() {
    char s1[50], s2[50];
    int len1, len2, i;

    scanf("%s", s1);
    scanf("%s", s2);

    len1 = strlen(s1);
    len2 = strlen(s2);

    for (i = 0; i <= len2; i++) {
        s1[len1 + i] = s2[i];
    }

    printf("%s\n", s1);

    return 0;
}