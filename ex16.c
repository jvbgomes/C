#include <stdio.h>

int main(){
    
    float A, B, C, triangulo, circulo, trapezio, quadrado, retangulo;
    scanf("%f %f %f", &A, &B, &C);

    triangulo = (A * C) / 2;
    circulo = 3.14159 * C * C;
    trapezio = ((A + B) * C) / 2;
    quadrado = B * B;
    retangulo = A * B;
   
    printf("TRIANGULO: %.3f\n", triangulo);
    printf("CIRCULO: %.3f\n", circulo);
    printf("TRAPEZIO: %.3f\n", trapezio);
    printf("QUADRADO: %.3f\n", quadrado);
    printf("RETANGULO: %.3f\n", retangulo);

    return 0;
}