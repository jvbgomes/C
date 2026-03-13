#include <stdio.h>

int sum(int* num, int a, int b) {
    *num = a + b;
    return *num;
}

int main() {
    int result;

    sum(&result, 5, 3);

    printf("Sum: %d\n", result);
    
    return 0;
}