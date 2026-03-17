#ifndef UI_H
#define UI_H

#include "mapa.h"

void imprimemapa(MAPA* m);
void imprimeparte(char desenho[4][7], int parte);

extern char desenhoparede[4][7];
extern char desenhofantasma[4][7];
extern char desenhoheroi[4][7];
extern char desenhopilula[4][7];
extern char desenhovazio[4][7];


#endif