#include <stdio.h>
#include <math.h> 

int main() {
    double x1, x2, y1, y2; 
    double distancia;
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    double pt1 = (x2 - x1) * (x2 - x1);
    double pt2 = (y2 - y1) * (y2 - y1);
    distancia = sqrt(pt1 + pt2);
    printf("%.4lf\n", distancia);

    return 0;
}