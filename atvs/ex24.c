#include <stdio.h>

int main(){
    float n1, n2, n3;
    float media;
    printf("Digite as três notas:\n");
    scanf("%f %f %f", &n1, &n2, &n3);

    media = (n1+n2+n3)/3;
    printf("Média do aluno: %.2f\n", media);

    if (media >= 7.0){
        printf("Aprovado!\n");
    }
    else if (media >= 5.0 && (n1 >= 3.0 && n2 >= 3.0 && n3 >= 3.0)){
        printf("Aprovado por nota!\n");
    }
    else if (media < 3.0){
        printf("Reprovado!\n");
    }

    else{
        printf("\nDigite a quarta nota:\n");
        float n4;
        scanf("%f", &n4);

        if (n4 > n1 && n1 <= n2 && n1 <= n3){
            media = (n4+n2+n3)/3;
        }
        else if (n4 > n2 && n2 <= n1 && n2 <= n3){
            media = (n4+n1+n3)/3;
        }
        else if(n4 > n3 && n3 <= n1 && n3 <= n2){
            media = (n4+n1+n2)/3;
        }
        printf("Média final do aluno: %.2f\n", media);

        if (media >= 7.0){
            printf("Aprovado!\n");
        }
        else if (media >= 5.0 && n4 >= 3.0){
            printf("Aprovado na Recuperação!\n");
        }
        else{
            printf("Reprovado!\n");
        }      
        }

    return 0;
}