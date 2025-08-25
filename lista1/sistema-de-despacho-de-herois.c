#include <stdio.h>

int main(){
    int quantidade, classe, monstro;
    scanf("%d %d %d", &quantidade, &classe, &monstro);
    
    if (quantidade == 0) {
        printf("Melhor chamar Saitama!\n");
        return 0;
    }

    int venceu = 0;

    if (monstro == 1) {
        if (classe >=2 || (classe == 1 && quantidade >= 3)) {
            venceu = 1;
        }
    } else if (monstro == 2) {
        if (classe >=3 || (classe == 2 && quantidade >= 3)) {
            venceu = 1;
        }
    } else if (monstro == 3) {
        if (classe >= 4 || (classe == 3 && quantidade >= 3)) {
            venceu = 1;
        }
    } else if (monstro == 4) {
        if (classe == 5 || (classe == 4 && quantidade >= 3)) {
            venceu = 1;
        }
    } else if (monstro == 5) {
        if (classe == 5) {
            venceu = 1;
        }
    }
    if (venceu) {
        printf("Heróis vencerão!\n");  
    } else {
        printf("Melhor chamar Saitama!\n");
    }

    return 0;
}