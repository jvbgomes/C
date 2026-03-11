#include <stdio.h>

void verif_nul_neg(int tam, int* vetor) {
    int i;
    
    for(i = 0; i < tam; i++){
        if(vetor[i] <= 0) {
            vetor[i] = 1;
        }
    }
}
 
int main() {
    int vetor[10];
    int i;
    
    for(i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }
    
    verif_nul_neg(10, vetor);
    
    for(i = 0; i < 10; i++) {
        printf("X[%d] = %d\n", i, vetor[i]);
    }
 
    return 0;
}