#include <stdio.h>
#include <math.h>

int main() {
    double numeros[10];
    double soma = 0, soma_inversos = 0, produto = 1;
    double media_aritmetica, media_harmonica, media_geometrica;
    double erro_harmonico, erro_geometrico, erro_medio;

    for (int i = 0; i < 10; i++) {
        scanf("%lf", &numeros[i]);
        soma += numeros[i];
        soma_inversos += 1.0 / numeros[i];
        produto *= numeros[i];
    }

    media_aritmetica = soma / 10.0;
    media_harmonica = 10.0 / soma_inversos;
    media_geometrica = pow(produto, 1.0 / 10.0);

    erro_harmonico = (media_harmonica - media_aritmetica) / media_aritmetica;
    erro_geometrico = (media_geometrica - media_aritmetica) / media_aritmetica;
    erro_medio = ((erro_harmonico + erro_geometrico) / 2.0) * 100.0;

    printf("Média aritmética é %.2f\n", media_aritmetica);
    printf("Média harmônica é %.2f\n", media_harmonica);
    printf("Média geométrica é %.2f\n", media_geometrica);
    printf("Erro médio é %.2f %%\n", erro_medio);


    return 0;
}