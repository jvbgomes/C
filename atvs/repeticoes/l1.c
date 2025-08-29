#include <stdio.h>

int main() {
    int somatorio, numero;

    somatorio = 0;

    scanf("%d", &numero);
    
    while (numero > 0) {
        somatorio += numero;   //somatorio = somatorio + numero;
        scanf("%d", &numero); 
    }

    printf("A soma é: %d\n", somatorio);

    return 0;
}