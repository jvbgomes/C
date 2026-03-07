#include <stdio.h>
#include <string.h>

int main() {
    char texto[100];
    char nome[50] = "André";
    int idade = 37;
    double altura = 1.75;

    sprintf(texto, "%s - %d - %.2lf", nome, idade, altura);
    printf("%s\n", texto);

    // fgets(texto, 100, stdin);

    // sscanf(texto, "%*s - %d - %*lf", nome, &idade, &altura);
    
    // printf("IDADE: %d\n", idade);
    
    return 0;
}