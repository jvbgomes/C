#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char entrada[52];
    char limpa[52];
    
    fgets(entrada, sizeof(entrada), stdin);
    entrada[strcspn(entrada, "\n")] = 0;

    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != ' ') {
            limpa[j] = tolower(entrada[i]);
            j++;
        }
    }
    limpa[j] = '\0';

    int e_palindromo = 1;
    int len = strlen(limpa);
    
    if (len > 0) {
        int esquerda = 0;
        int direita = len - 1;

        while (esquerda < direita) {
            if (limpa[esquerda] != limpa[direita]) {
                e_palindromo = 0;
                break;
            }
            esquerda++;
            direita--;
        }
    }
    
    // Corrigido para usar "palíndromo" com acento
    if (e_palindromo) {
        printf("É palíndromo");
    } else {
        printf("Não é palíndromo");
    }

    return 0;
}