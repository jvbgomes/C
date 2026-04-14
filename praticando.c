#include <stdio.h>
#include <stdlib.h>

//void main() {
//    int var1;
//    int *var2;
//    int var3;
//
//    var1 = 10;
//    var2 = &var1;
//    var3 = *var2 + 20;
//
//    printf("Valor de var1: %d\n", var1);
//    printf("Valor de var2: %d\n", *var2);
//    printf("Valor de var3: %d\n", var3);
//}
// Este código demonstra o uso de ponteiros em C. Ele declara três variáveis: `var1`, `var2` e `var3`. `var1` é um inteiro que recebe o valor 10. `var2` é um ponteiro para inteiro que armazena o endereço de `var1`. `var3` é um inteiro que recebe o valor de `*var2` (o valor apontado por `var2`, que é 10) somado a 20, resultando em 30. O programa então imprime os valores de `var1`, `*var2` e `var3`.

void main() {
    int var1;
    int *var2;
    int var3;

    var1 = 10;
    var2 = (int *)malloc(sizeof(int)); //aloca dinamicamente um inteiro na heap.
    var3 = *var2 + 20; // isso vai ser um valor lixo em que o var2 esta apontando, podendo ser qualquer valor e ai soma-se 20.
    free(var2); // libera a memória alocada para var2

    printf("Valor de var1: %d\n", var1);
    printf("Valor de var2: %d\n", *var2);
    printf("Valor de var3: %d\n", var3);
}