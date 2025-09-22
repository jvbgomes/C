#include <stdio.h>

int main(void) {
  int op, init;
  int lado1, lado2, lado3, aux;

  /*Essa variável vai ser utilizada para verificar se os 3 lados já
    foram lidos. Quando o valor for 0 indica que a leitura ainda não
    ocorreu, se for 1 indica que a leitura ocorreu.
  */
  init = 0;

  printf("Bem vindo ao triangulizer!\n\n");

  do{
    printf("\nEscolha a opção:\n");
    printf("1 - Informar triangulo\n");
    printf("2 - Testar se é um triângulo válido\n");
    printf("3 - Testar tipo em relação aos ângulos\n");
    printf("4 - Testa tipo em relação aos lados\n");
    printf("5 - Relizar todos os testes\n");
    printf("6 - Encerrar programa\n");
    printf("Selecione: ");

    scanf("%d", &op);

    switch(op){
      case 1:
        scanf("%d %d %d", &lado1, &lado2, &lado3);
        init = 1;
        printf("Triângulo lido com sucesso!\n");
        break;
      case 2:
        //Para rodar, precisa ter um triângulo informado
        if(init != 0){
          //Teste se é triângulo
          //Para facilitar os testes, vou deixar lado1 como o maior lado
          if(lado2 > lado1 && lado2 > lado3){
            aux = lado2;
            lado2 = lado1;
            lado1 = aux;
          }
          else if(lado3 > lado1 && lado3 > lado2){
            aux = lado3;
            lado3 = lado1;
            lado1 = aux;
          }
        
          if(lado1 >= lado2 + lado3)
            printf("Não é um triângulo\n");
          else
            printf("Triângulo válido\n");
        }
        break;
      case 3:
        //Para testar, tem que ter um triângulo informado válido
        if(init != 0){
          if(lado2 > lado1 && lado2 > lado3){
            aux = lado2;
            lado2 = lado1;
            lado1 = aux;
          }
          else if(lado3 > lado1 && lado3 > lado2){
            aux = lado3;
            lado3 = lado1;
            lado1 = aux;
          }
        
          if(lado1 >= lado2 + lado3)
            printf("Não é um triângulo\n");
          else{
            if(lado1*lado1 == lado2*lado2 + lado3*lado3)
              printf("Triângulo Retângulo\n");
            else if(lado1*lado1 > lado2*lado2 + lado3*lado3)
              printf("Triângulo Obtusângulo\n");
            else
              printf("Triângulo Acutângulo\n");
          }
        }
        break;
      case 4:
        //Para testar, tem que ter um triângulo informado válido
        if(init != 0){
          if(lado2 > lado1 && lado2 > lado3){
            aux = lado2;
            lado2 = lado1;
            lado1 = aux;
          }
          else if(lado3 > lado1 && lado3 > lado2){
            aux = lado3;
            lado3 = lado1;
            lado1 = aux;
          }
        
          if(lado1 >= lado2 + lado3)
            printf("Não é um triângulo\n");
          else{
            if(lado1 == lado2 && lado1 == lado3)
              printf("Triângulo Equilátero\n");
            else if(lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
              printf("Triângulo Isóceles\n");
            else
              printf("Triângulo Escaleno\n");
          }
        }
        break;
      case 5:
        //Para testar, tem que ter um triângulo informado válido
        if(init != 0){
          if(lado2 > lado1 && lado2 > lado3){
            aux = lado2;
            lado2 = lado1;
            lado1 = aux;
          }
          else if(lado3 > lado1 && lado3 > lado2){
            aux = lado3;
            lado3 = lado1;
            lado1 = aux;
          }
        
          if(lado1 >= lado2 + lado3)
            printf("Não é um triângulo\n");
          else{
            if(lado1*lado1 == lado2*lado2 + lado3*lado3)
              printf("Triângulo Retângulo\n");
            else if(lado1*lado1 > lado2*lado2 + lado3*lado3)
              printf("Triângulo Obtusângulo\n");
            else
              printf("Triângulo Acutângulo\n");

            if(lado1 == lado2 && lado1 == lado3)
              printf("Triângulo Equilátero\n");
            else if(lado1 == lado2 || lado1 == lado3 || lado2 == lado3)
              printf("Triângulo Isóceles\n");
            else
              printf("Triângulo Escaleno\n");
          }
        }
        break;
      case 6:break;
      default: printf("Opção inválida!\n");
    }
  }while(op != 6);

  return 0;
}