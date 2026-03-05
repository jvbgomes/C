#include <stdio.h>
#include <stdlib.h>

int main(){
    int carro, carro1, carro2;
    scanf("%d %d %d", &carro, &carro1, &carro2);

    int frente, tras;

    if (carro1 > carro && carro2 < carro){
        frente = carro1;
        tras = carro2;
    } else if (carro2 > carro && carro1 < carro){
        frente = carro2;
        tras = carro1;
    } else {
        printf("C\n");
        return 0;
    }

     int dist_frente = abs(frente - carro);
     int dist_tras = abs(tras - carro);

     if (dist_tras < dist_frente){
        printf("A\n");
     } else if (dist_frente < dist_tras){
        printf("F\n");
     } else {
        printf("C\n");
     }

    return 0;
}