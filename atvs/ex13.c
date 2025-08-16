#include <stdio.h>

int main(){
   
    char name[50];
    double salary,mouth,total;

    scanf("%s",&name);
    scanf("%lf %lf",&salary,&mouth);   

    total = (mouth * 0.15) + salary;

    printf("TOTAL = R$ %.2lf\n",total);

    return 0;
}