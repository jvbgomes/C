#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "pacman.h"
#include "ui.h"

int main() {
    MAPA m;
    POSICAO heroi;
    int tempilula = 0;
    
    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);

    do {

        system("cls");
        printf("Tem pilula: %s\n", tempilula ? "SIM" : "NAO");
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(&m, &heroi, comando, &tempilula);
        if(comando == BOMBA) {
            explodepilula(heroi.x, heroi.y, 3, &m, &tempilula);
        }

        fantasmas(&m);

    } while(!acabou(&m));

    liberamapa(&m);
    return 0;
}