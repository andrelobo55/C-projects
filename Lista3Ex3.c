#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Exerc�cio 3

int main()
{
    //Definindo valor das vari�veis num e num2;
    int num=70,num2=40;
            setlocale(LC_ALL,"Portuguese"); //Definindo caracateres latinos em portugu�s;
        do{ //Fa�a:
            printf("%d\n",num); //Mostre o numero;
            num--; //Fa�a: n�mero = n�mero - 1;
        }
        while(num >= num2); // Enquanto 70 for menor ou igual a 40;
    return 0;
}
