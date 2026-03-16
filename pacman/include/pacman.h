#ifndef PACMAN_H
#define PACMAN_H

#include "mapa.h"

#define CIMA 'w'
#define BAIXO 's'   
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou(MAPA* m);
int ehdirecao(char direcao);
void move(MAPA* m, POSICAO* heroi, char direcao); 
void fantasmas(MAPA* m);
int praondeofantasmavai(MAPA* m, int x, int y, int* xdestino, int* ydestino);

#endif