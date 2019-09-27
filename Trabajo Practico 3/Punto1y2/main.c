#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("El factorial es %i \n", factorial(5));
    printf("La potencia es %i \n", potencia(4, 2));

    return 0;
}

int factorial(int num)
{
    int rta;

    if(num == 0)
    {
        rta = 1;
    }
    else
    {
        rta = num * factorial(num-1);
    }
    return rta;
}

int potencia(int base, int exponente)
{
    int rta;

    if(exponente == 0)
    {
        rta = 1;
    }
    else
    {
        rta = base * potencia(base, exponente-1);
    }
    return rta;
}
