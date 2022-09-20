#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Exercício 2

int main()
{
    int num=70,num2=40,soma = 0;
        setlocale(LC_ALL,"Portuguese");
        while(num >= num2){
            printf("%d\n",num);
            num--;
            soma += num + num2;
        }
        printf("Soma = %d \n",soma);
    return 0;
}
