#include <stdio.h>
#include <string.h>

int main() {
    char texto[100];

    fgets(texto, 99, stdin);
    texto[strcspn(texto, "\n")] = '\0'; // Remove o caractere de nova linha, se presente

    printf("%s\n", texto);
    
    return 0;
}