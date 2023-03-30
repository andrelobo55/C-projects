#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int escolha;
    float a,b;
        setlocale(LC_ALL,"Portuguese");
        printf("\n Calculadora Básica!");
    do {
        printf("\n[1]Soma"
               "\n[2]Subtração"
               "\n[3]Multiplicação"
               "\n[4]Divisão"
               "\n[0]Sair");
        printf("\n Selecione uma opção:");
        scanf("\n %d",&escolha);
        //printf("\n Digite dois números:");
        //scanf("\n %f %f",&a,&b);
    switch(escolha){
    case 1:
        printf("\n Digite dois números:");
        scanf("\n %f %f",&a,&b);
        a+b;
        printf("\n %0.2f + %0.2f = %0.2f",a,b,a+b);
        break;
    case 2:
        printf("\n Digite dois números:");
        scanf("\n %f %f",&a,&b);
        a-b;
        printf("\n %0.2f - %0.2f = %0.2f",a,b,a-b);
        break;
    case 3:
        printf("\n Digite dois números:");
        scanf("\n %f %f",&a,&b);
        a*b;
        printf("\n %0.2f x %0.2f = %0.2f",a,b,a*b);
        break;
    case 4:
        printf("\n Digite dois números:");
        scanf("\n %f %f",&a,&b);
        if(b == 0){
            printf("\n Impossível dividir por zero. \a ");
        }
        else {
        a/b;
        printf("\n %0.2f / %0.2f = %0.2f",a,b,a/b);
        }
        break;
    case 0:
        printf("\n Saindo!");
        break;
    default:
        printf("\n Opção inválida!");
    }
    }
    while(escolha != 0);
    return 0;
}
