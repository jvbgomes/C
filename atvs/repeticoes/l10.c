#include <stdio.h>
#include <math.h>

int main(){
    int A, B, i;
    int j, primo;

    printf("Digite o valor de A: ");
    scanf("%d", &A);
    printf("Digite o valor de B: ");
    scanf("%d", &B);

    printf("Números primos entre %d e %d:\n", A, B);


    for (i = A; i <= B; i++) {
        if (i < 2){
            continue;
        }
        primo = 1;
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                primo = 0;
                break;
            }    
        }
        if (primo) {
            printf("%d\n", i);
        }

    }

    return 0;
}

//um numero é primo quando é div. por 1 e ele mesmo, portanto, ele não pode ser dividido por nenhum outro numero.Entretanto, para verificar se um numero é primo, devemos testar se ele é divisível por algum numero entre 2 e a raiz quadrada dele.