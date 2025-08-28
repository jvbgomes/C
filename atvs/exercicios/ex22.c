#include <stdio.h>

int main(){
    int petalas;

    scanf("%d", &petalas);
   
    if (petalas % 2 == 0){
        printf("Mal me quer! Estalo!\n");   
    }
    else{
        printf("Bem me quer! #xatiado\n");     
    }

    return 0;
}