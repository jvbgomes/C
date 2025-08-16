#include <stdio.h>
 
int main() {
   
    int v1, v2, v3;
    int MaiorAB, MaiorFinal;

    scanf("%d %d %d", &v1, &v2, &v3);

    MaiorAB = (v1 + v2 + abs(v1-v2))/2;
    MaiorFinal = (MaiorAB + v3 + abs(MaiorAB - v3))/2;

    printf("%d eh o maior\n", MaiorFinal);

    return 0;
}