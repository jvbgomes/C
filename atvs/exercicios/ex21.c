#include <stdio.h>

int main() {
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    if (num1 >= num2){
        printf("%d é maior que %d\n", num1, num2);
    }
    else{
        printf("%d é menor que %d\n", num1, num2);
    }

    return 0;
}