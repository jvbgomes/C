#define CIMA 'w'
#define BAIXO 's'   
#define DIREITA 'd'
#define ESQUERDA 'a'



void move(char direcao); 
int acabou();

int ehdirecao(char direcao);

void fantasmas();

int praondeofantasmavai(int x, int y, int* xdestino, int* ydestino);