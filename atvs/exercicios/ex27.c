#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    if (n > 5 && n < 80 || n < -1 && n > -10) {
        printf("V");
    } else {
        printf("F");
    }
    
    return 0;
}