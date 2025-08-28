#include <stdio.h> 

int main(){
    int n;
    scanf("%d", &n);

    switch(n %2 ==0){
        case 1: 
            printf("Par\n");
        default: 
            printf("Impar\n");
    }
    
    return 0;
}