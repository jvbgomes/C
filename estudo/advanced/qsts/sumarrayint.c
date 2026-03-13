#include <stdio.h>

int soma(int a[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

int main() {
    int nums[3];
    nums[0] = 10;
    nums[1] = 20;
    nums[2] = 30;

    int total = soma(nums, 3);

    printf("Soma: %d\n", total);

    return 0;
}