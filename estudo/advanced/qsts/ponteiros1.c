#include <stdio.h>

void calcula(int* c2) {
    printf("calcula %d %d\n", *c2, c2);
    (*c2)++;
    printf("calcula %d %d\n", *c2, c2);
}

int main() {

    int c = 10;

    printf("main %d %d\n", c, &c);
    calcula(&c);
    printf("main %d %d\n", c, &c);

    return 0;
}