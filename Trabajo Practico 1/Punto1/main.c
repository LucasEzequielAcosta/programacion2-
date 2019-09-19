#include <stdio.h>
#include <stdlib.h>

const int DIM = 5;

int main()
{
    int numeros[DIM];
    int validos = inicializar(numeros);
    mostrar(numeros, validos);

    validos = cargarNumeros(numeros);
    mostrar(numeros, validos);
    printf("el promedio es: %i ", promedio(numeros, validos));

    return 0;
}

int inicializar(int arreglo[])
{
    int validos = 0;
    for(int i=0; i<DIM; i++)
    {
        arreglo[i] = -1;
        validos++;
    }
    return validos;
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

int sumarArreglo(int arrgelo[], int validos)
{
    int suma = 0;
    for(int i=0; i<validos; i++)
    {
        suma += arrgelo[i];
    }
    return suma;
}

int contar(int arreglo[], int validos)
{
    int cantidad = 0;
    for(int i=0; i<validos; i++)
    {
        cantidad++;
    }
    return cantidad;
}

int promedio(int arreglo[], int validos)
{
    int suma = sumarArreglo(arreglo, validos);
    int cantidad = contar(arreglo, validos);
    int promedio = suma/cantidad;

    return promedio;
}










