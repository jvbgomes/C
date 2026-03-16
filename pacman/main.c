#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"
#include "pacman.h"


int main() {
    MAPA m;
    POSICAO heroi;
    
    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);

    do {

        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(&m, &heroi, comando);
        fantasmas(&m);

    } while(!acabou());

    liberamapa(&m);
    return 0;
}