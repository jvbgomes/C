#include <stdio.h>

int main(){
    int N, i, multi;
    multi = 1;
    printf("Digite um número: \n");
    scanf("%d", &N);

    for (i = 1; i <= 10; i++) {
        if (N == 0){
            printf("0 x %d = 0\n", i);
            break;
        } else {
        multi = N * i;
        printf("%d x %d = %d\n", N, i, multi);
        }
    }

    return 0;
}