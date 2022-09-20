#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Exercício 1

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int num=110,num2=100;
    while(num2 <= num){
    if(num2%2==0){
        printf("%d \n",num2);
    }
        num2++;
    }

    return 0;
}
