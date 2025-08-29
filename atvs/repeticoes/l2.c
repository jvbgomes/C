#include <stdio.h>

int main(){
    int numero1, numero2;
    char op;

    do {
       printf("Digite a conta desejada (Valor OP valor):\n");
       scanf("%d %c %d", &numero1, &op, &numero2);
       
       switch(op){
        case '+':
            printf("Resultado: %d\n", numero1 + numero2);
            break;
        case '-':
            printf("Resultado: %d\n", numero1 - numero2);
            break;
        case '*':
            printf("Resultado: %d\n", numero1 * numero2);
            break;
        case '/':
            if (numero2 == 0){
                printf("Divisão por zero não é permitida!\n");
            }else{
                printf("Resultado: %d\n", numero1 / numero2);
            }

            break;
       }

    }while(op != 'F');

    return 0;
}