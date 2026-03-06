#include <stdio.h>

int main() {
    int mat[5][5];
    int i, j;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++) {
            mat[i][j] = 3;
        }
    }
    return 0;
}