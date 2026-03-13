#include <stdio.h>
#include <string.h>

//Variáveis globais
char palavrasecret[20];
char chutes[26];
int tentativas = 0;

void abertura() {
    printf("***********************\n");
    printf("* Jogo de Forca       *\n");
    printf("***********************\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
    tentativas++;
}

int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < tentativas; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca() {

        

    for(int i = 0; i < strlen(palavrasecret); i++) {

        printf("Voce ja deu %d chutes\n", tentativas);

        if(jachutou(palavrasecret[i])) {
            printf("%c ", palavrasecret[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n"); 
}

void escolhepalavra() {
    sprintf(palavrasecret, "MELANCIA");

}

int main() {
    
    int acertou = 0;
    int enforcou = 0;

    abertura();
    escolhepalavra();

    do {
        
        desenhaforca();
        chuta(); 

    } while(!acertou && !enforcou);

    return 0;
}