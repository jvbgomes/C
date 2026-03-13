#include <stdio.h>
#include <string.h>

void abertura() {
    printf("***********************\n");
    printf("* Jogo de Forca       *\n");
    printf("***********************\n\n");
}

void chuta(char chutes[26], int* tentativas) {
    char chute;
    scanf(" %c", &chute);

    chutes[(*tentativas)] = chute;
    (*tentativas)++;
}

int jachutou(char letra, char chutes[26], int tentativas) {
    int achou = 0;
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

int main() {
    char palavrasecret[20];
    
    sprintf(palavrasecret, "BANANA");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];
    int tentativas = 0;

    abertura();

    do {
        //imprime a palavra secreta
        for(int i = 0; i < strlen(palavrasecret); i++) {

            jachutou(palavrasecret[i], chutes, tentativas);

            if(achou) {
                printf("%c ", palavrasecret[i]);
            }
            else {
                printf("_ ");
            }
        }
        printf("\n"); 

        chuta(chutes, &tentativas); 
        

    } while(!acertou && !enforcou);

    return 0;
}