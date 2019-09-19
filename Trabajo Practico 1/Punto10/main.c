#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ArregloDeNumeros[10]={4, 2,7,3,99,22,5,23,97,12};
    int mayor=0;
    int menor=0;
    float prom=0;

    printf("\n Arreglo para el punto 10: ");
    mostrarArreglo(ArregloDeNumeros, 10);
    valores(ArregloDeNumeros, 10, &mayor, &menor, &prom);
    printf("\nInfo del arreglo: \n Mayor= %d\n Menor= %d\n Promedio=%.2f", mayor,menor, prom);

    return 0;
}

float promedioEnArreglo (int A[], int validos)
{
    int i=0;
    int suma=0;
    for(i=0; i<validos; i++)
    {
        suma+=A[i];
    }

    return (float)suma/(float)validos;
}
int maximoEnArreglo (int A[], int validos)
{
    int i=0;
    int mayor=A[i];
    for(i=1; i<validos; i++)
    {
        if(mayor<A[i])
        {
            mayor=A[i];
        }
    }
    return mayor;
}
int minimoEnArreglo (int A[], int validos)
{
    int i=0;
    int menor=A[i];
    for(i=1; i<validos; i++)
    {
        if(menor>A[i])
        {
            menor=A[i];
        }
    }
    return menor;
}

void valores(int A[], int validos, int * maximo, int * minimo, float * promedio)
{
    *maximo=maximoEnArreglo(A, validos);
    *minimo=minimoEnArreglo(A, validos);
    *promedio=promedioEnArreglo(A, validos);
}


void mostrarArreglo(int arreglo[], int validos)
{
    int i=0;
    for(i=0; i<validos; i++)
    {
        printf(" %i \t", arreglo[i]);
    }
}





