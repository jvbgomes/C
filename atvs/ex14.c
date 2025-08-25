#include <stdio.h>

int main(){
    
    int c1, n1;
    int c2, n2;
    float p1, p2, VP;
    scanf("%d %d %f", &c1, &n1, &p1);
    scanf("%d %d %f", &c2, &n2, &p2);
    VP = (n1 * p1)+(n2 * p2);
    printf("VALOR A PAGAR: R$ %.2f\n", VP);

    return 0;
}