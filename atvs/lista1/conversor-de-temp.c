#include <stdio.h>

int main(){
    float valor, celsius, farenheit, kelvin;
    char escala;

    scanf("%f %c", &valor, &escala);

    if (escala == 'C' || escala == 'c'){
        celsius = valor;
        farenheit = (celsius * 1.8) + 32;
        kelvin = celsius + 273.15;

    }
    else if (escala == 'F' || escala == 'f'){
        farenheit = valor;
        celsius = (farenheit - 32)/1.8;
        kelvin = celsius + 273.15;

    }
    else if (escala == 'K' || escala == 'k'){
        kelvin = valor;
        celsius = kelvin - 273.15;
        farenheit = (celsius * 1.8) + 32;

    }
    else{
        printf("Escala inválida!\n");
        return 1;
    }
    printf("Celsius: %.2f\n", celsius);
    printf("Fahrenheit: %.2f\n", farenheit);
    printf("Kelvin: %.2f\n", kelvin);

    return 0;
}