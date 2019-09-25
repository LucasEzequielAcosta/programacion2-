#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arreglo[10];

    return 0;
}

int cargar(int arreglo[])
{
    int i=0;

    for(i=0; i<DIM; i++)
    {
        arreglo[i] = rand()%20;
    }
    return i;
}

int insertarEnOrden(int arreglo[], int validos, int valor)
{
    int i = validos-1;

    while(i>0 && dato<arreglo[i])
    {
        arreglo[i+1] = arreglo[i];
        i--;
    }
    arreglo[i+1] = dato;

    return validos+1;
}

void insertar(int A[], int u, int dato)
{
    int i = u;
    while(i>=0 && dato <A[i])
    {
        A[i+1]=A[i];
        i--;
    }
    A[i+1]=dato;
}

void ordenacionInsercion (int A[], int c)
{
    int u = 0;
    while (u<c-1)
    {
        insertar(A,u,A[u+1]);
        u++;
    }
}

int eliminaElementoDeArreglo(int A[], int validos, int posAeliminar)
{
    int i=posAeliminar;
    // validamos que la pos ingresada sea valida...
    if(i<validos)
    {
        while(i<validos-1)
        {
            A[i]=A[i+1];
            i++;
        }

        validos--;
    }

    return validos;
}






