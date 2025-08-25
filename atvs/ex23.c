#include <stdio.h>

int main(){
    int T, S, H;
    scanf("%d %d %d", &T, &S, &H);
    if (T==S && S==H){
        printf("Empate!\n");
    }
    else if (T!=S && T!=H){
        printf("Thor!\n");
    }
    else if(S!=T && S!=H){
        printf("Star lord!\n");
    }
    else{
        printf("Homem-Aranha!\n");
    }

    return 0;
}