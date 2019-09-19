#include <stdio.h>
#include <stdlib.h>

const int DIM = 5;

int main()
{
    char arreglo[DIM];
    int validos = 0;
    validos = cargar(arreglo, validos);
    mostrar(arreglo, validos);

    int f = capicua(arreglo, validos);

    if(f==0)
    {
        printf("es capicua\n");
    }
    else
    {
        printf("no es capicua");
    }

    return 0;
}

int cargar(char arreglo[], int validos)
{
    char control = 's';

    while(control=='s' && validos<DIM)
    {
        printf("ingrese una letra \n");
        scanf("%c", &arreglo[validos]);
        fflush(stdin);
        validos++;
        printf("desea continuar? s/n \n");
        scanf("%c", &control);
        fflush(stdin);
    }
    return validos;
}

void mostrar(char arreglo[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("%c \n", arreglo[i]);
    }
}

int capicua(char arreglo[], int validos)
{
    int flag=0, j=validos-1;

    for(int i=0; i<j; i++)
    {
        if(arreglo[i]==arreglo[j])
        {
            j--;
        }
        else
        {
            flag = 1;
        }
    }
    return flag;
}









