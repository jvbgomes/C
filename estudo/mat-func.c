#include <stdio.h>

void detecta_negativos(int lin, int col, int mat[lin][col]) {
    int i, j;

    for(i = 0; i < lin; i++) {
        for(j = 0; j < col; j++) {
            if(mat[i][j] < 0) {
                printf("Linha: %d, Coluna: %d\n", i, j);
            }
        }
    }

}

int main() {
    int mat[5][5];
    int i, j;

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            scanf("%d", &mat[i][j]);
        } 
    }
    detecta_negativos(5, 5, mat);

    return 0;
}