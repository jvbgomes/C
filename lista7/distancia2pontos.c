#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} tCoordenada;

float dist(tCoordenada p1, tCoordenada p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    tCoordenada p1, p2;
    scanf("%f %f", &p1.x, &p1.y);
    scanf("%f %f", &p2.x, &p2.y);

    printf("Distância: %.2f\n", dist(p1, p2));
    return 0;
}