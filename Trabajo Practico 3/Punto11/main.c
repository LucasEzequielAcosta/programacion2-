#include <stdio.h>
#include <stdlib.h>

int main()
{
    ingresaPorTecladoYMuestra();

    return 0;
}

void ingresaPorTecladoYMuestra()
{
    char valor;
    printf("\nIngrese un caracter: ");
    fflush(stdin);
    scanf("%c", &valor);

    /* if(valor=='*')
     {
         printf("%c ",valor);
     }
     else
     {
         ingresaPorTecladoYMuestra();
         printf("%c ",valor);
     }*/

    // esta tambien es valida... no se ve de forma explicita la cond. de corte

    if(valor!='*')
    {
        ingresaPorTecladoYMuestra();
        printf("%c ",valor);
    }
}
