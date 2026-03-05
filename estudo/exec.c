#include <stdio.h>

int main() {
    int fotos, entrada;
    int tubaroes[15] = {0};
    int i, diferentes = {0};

    scanf("%d", &fotos);

    for(i=0; i<fotos; i++) {
        scanf("%d", &entrada);
        
        if(tubaroes[entrada] == 0) {
            tubaroes[entrada] = 1;
            diferentes++;
        }
    }
    printf("%d especies diferentes!\n", diferentes);

    for(i=1; i <=15; i++) {
        if(tubaroes[i] != 0) {
            switch(i) {
                case 1:
                    printf("Tubarao Branco\n");
                    break;
                case 2:
                    printf("Tubarao Martelo\n");
                    break;
                case 3:
                    printf("Tubarao Tigre\n");
                    break;
                case 4:
                    printf("Tubarao Mako\n");
                    break;
                case 5:
                    printf("Tubarao Azul\n");
                    break;
                case 6:
                    printf("Tubarao Femea\n");
                    break;
                case 7:
                    printf("Tubarao Galha Preta\n");
                    break;
                case 8:
                    printf("Tubarao Galha Branca\n");
                    break;
                case 9:
                    printf("Tubarao Lixa\n");
                    break;
                case 10:
                    printf("Tubarao Anjo\n");
                    break;
                case 11:
                    printf("Tubarao Frade\n");
                    break;
                case 12:
                    printf("Tubarao Baleia\n");
                    break;
                case 13:
                    printf("Tubarao Cornuda\n");
                    break;
                case 14:
                    printf("Tubarao Martelo Gigante\n");
                    break;
            }

        }
    }

    return 0;
}