#include <stdio.h>

int main(){
    int codigos[5] = {1, 2, 3, 4, 5};
    int valores[5] = {12, 23, 31, 28, 15};

    int codigo, dinheiro, preco, troco, falta;
    scanf("%d %d", &codigo, &dinheiro);

    if (codigo >= 1 && codigo <= 5){
        preco = valores[codigo - 1];

        if(dinheiro == preco){
            printf("Deu certim!\n");
        } else if (dinheiro > preco){
            troco = dinheiro - preco;
            printf("Troco = %d reais\n", troco);
        } else{
            falta = preco - dinheiro;
            printf("Saldo insuficiente! Falta %d reais\n", falta);
        }
    } else {
        printf("Codigo invalido!\n");
    }

    return 0;
}