#include <stdio.h>
#include <stdlib.h>

const int DIM = 5;

int main()
{
    int numeros[DIM];
    int validos = 0;

    validos = cargarNumeros(numeros);
    mostrar(numeros, validos);

    int decimal = valorDecimal(numeros, validos);
    printf("el valor decimal es: %i", decimal);

    int pos = posMayor(numeros, validos);
    printf("la posicion del mayor es: %i", pos);

    return 0;
}

void mostrar(int arreglo[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("%i \n", arreglo[i]);
    }
}

int cargarNumeros(int arreglo[])
{
    char control = 's';
    int validos = 0;

    while(validos<DIM && control=='s')
    {
        printf("ingrese un numero \n");
        scanf("%i", &arreglo[validos]);
        fflush(stdin);
        validos++;
        printf("desea continuar? s/n \n");
        scanf("%c", &control);
    }
    return validos;
}

int valorDecimal(int arreglo[], int validos)
{
    int decimal=0, cont=1, aux=0;

    for(int i=validos-1; i>=0; i--)
    {
        aux = arreglo[i];
        decimal += aux * cont;
        cont = cont*10;
    }
    return decimal;
}

int posMayor(int arreglo[], int validos)
{
    int mayor=0, aux=arreglo[0], pos=0;

    for(int i=0; i<validos; i++)
    {
        if(arreglo[i] > aux)
        {
            aux = arreglo[i];
            pos = i;
        }
    }
    return pos;
}








