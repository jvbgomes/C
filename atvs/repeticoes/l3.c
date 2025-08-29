#include <stdio.h>

int main(){
    char lixo;
    int vidro, plastico, papel, organico, metal, eletronico;
    int i;

    vidro = plastico = papel = organico = metal = eletronico = 0;   

    for (i = 0; i < 10; i++) {   //tanto faz se for i++ ou ++i.
        scanf(" %c", &lixo);  //esse espaço antes do %c faz ele desconsiderar o espaço em branco.
        if (lixo == 'V' || lixo == 'v') {
            vidro++;
        } else if (lixo == 'L' || lixo == 'l') {
            plastico++;
        } else if (lixo == 'P' || lixo == 'p') {
            papel++;
        } else if (lixo == 'O' || lixo == 'o') {
            organico++;
        } else if (lixo == 'M' || lixo == 'm') {
            metal++;
        } else if (lixo == 'E' || lixo == 'e') {
            eletronico++;
        } 
    }

    printf("Vidro: %d\n", vidro);
    printf("Plastico: %d\n", plastico);
    printf("Papel: %d\n", papel);
    printf("Organico: %d\n", organico);
    printf("Metal: %d\n", metal);
    printf("Eletronico: %d\n", eletronico);

    return 0;
}