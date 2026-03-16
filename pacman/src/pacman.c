#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/pacman.h"
#include "../include/mapa.h"


int praondeofantasmavai(MAPA* m, int xatual, int yatual, int* xdestino, int* ydestino) {

    int opcoes[4][2] = {
        {xatual, yatual+1},
        {xatual, yatual-1},
        {xatual+1, yatual},
        {xatual-1, yatual}
    };

    srand(time(0));
    for(int i = 0; i < 10; i++) {
        int posicao = rand() % 4;
        
        if(podeandar(m, opcoes[posicao][0], opcoes[posicao][1])) {
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;
        }
    }
    return 0;
}

void fantasmas(MAPA* m) {
    MAPA copia;

    copiamapa(&copia, m);

    for(int i = 0; i < m->linhas; i++) {
        for(int j = 0; j < m->colunas; j++) {
            if(copia.matriz[i][j] == FANTASMA) {

                int xdestino, ydestino;
                
                int encontrou = praondeofantasmavai(m, i, j, &xdestino, &ydestino);

                if(encontrou) {
                    andanomapa(m, i, j, xdestino, ydestino);
                }
            }
        }
    }
    liberamapa(&copia);
}

int acabou(MAPA* m) {
    POSICAO pos;
    int fogefogenomapa = encontramapa(m, &pos, HEROI);
    return !fogefogenomapa;
}

int ehdirecao(char direcao) {
    return direcao == BAIXO || direcao == CIMA || direcao == ESQUERDA || direcao == DIREITA;
}

void move(MAPA* m, POSICAO* heroi, char direcao) {

    if(!ehdirecao(direcao)) {
        printf("Comando invalido\n");
        return;
    }
   
    int proximox = heroi->x;
    int proximoy = heroi->y;

    switch(direcao) {
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case ESQUERDA:
            proximoy--;
            break;
        case DIREITA:
            proximoy++;
            break;
    }

    if(!podeandar(m, proximox, proximoy)) {
        return;
    }

    andanomapa(m, heroi->x, heroi->y, proximox, proximoy);
    heroi->x = proximox;
    heroi->y = proximoy;
    
}