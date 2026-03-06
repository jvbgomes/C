#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char resultado[300] = "";
    char temp[100];
    int modo;
    while (1) {
        scanf("%d", &modo);
        if (modo == -1) break;
        getchar();
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = '\0';

        if (strlen(resultado) == 0) {
            strcpy(resultado, temp);
        } else if (modo == 0) {
            char aux[300];
            strcpy(aux, resultado);
            strcpy(resultado, temp);

            // Adiciona espaço apenas se necessário
            int temp_len = strlen(temp);
            if (temp_len > 0 && aux[0] != ' ' && temp[temp_len - 1] != ' ') {
                strcat(resultado, " ");
            }
            strcat(resultado, aux);
        } else if (modo == 1) {
            int res_len = strlen(resultado);
            if (res_len > 0 && resultado[res_len - 1] != ' ' && temp[0] != ' ') {
                strcat(resultado, " ");
            }
            strcat(resultado, temp);
        }
    }
    printf("%s\n", resultado);
    return 0;
}