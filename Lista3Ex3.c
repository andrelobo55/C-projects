#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Exercício 3

int main()
{
    //Definindo valor das variáveis num e num2;
    int num=70,num2=40;
            setlocale(LC_ALL,"Portuguese"); //Definindo caracateres latinos em português;
        do{ //Faça:
            printf("%d\n",num); //Mostre o numero;
            num--; //Faça: número = número - 1;
        }
        while(num >= num2); // Enquanto 70 for menor ou igual a 40;
    return 0;
}
