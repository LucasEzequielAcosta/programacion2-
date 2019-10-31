#include <stdio.h>
#include <stdlib.h>
#include "Arbol.c"

int sumar(nodoArbol * arbol);

int main()
{
    nodoArbol * arbol = inicArbol();
    int arreglo[5] = {6,2,3,4,5};

    for(int i=0; i<5; i++)
    {
        arbol = insertar(arbol, arreglo[i]);
    }

    posorder(arbol);

    int suma = sumar(arbol);

    printf("\nSuma: %i", suma);

    return 0;
}

int sumar(nodoArbol * arbol)
{
    int rta = 0;

    if(arbol != NULL)
    {
        rta = arbol->dato + sumar(arbol->izq) + sumar(arbol->der);
    }
    return rta;
}










