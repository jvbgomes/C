int potencia(int x, int y){
    int i;
    int pot = 1;

    for(i=0; i<y; i++){
        pot *= x;
    }
    return pot;
}
int main(){
    int num1, num2;
    int resultado;

    scanf("%d %d", &num1, &num2);
    resultado = potencia(num1, num2);
    resultado = 100 + potencia(num1, num2);
    
    if(potencia(num1, num2) > 100){
        printf("Que potência!\n");
    }
    printf("O valor da potência foi: %d\n", potencia(num1, num2));
}