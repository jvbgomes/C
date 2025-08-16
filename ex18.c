#include <stdio.h>
 
int main() {

    int X;
    float Y, KmpL;
    scanf("%d %f", &X, &Y);
    KmpL = X / Y;
    printf("%.3f km/l\n", KmpL);

    return 0;
}