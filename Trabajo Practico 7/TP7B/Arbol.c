#include "Arbol.h"

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodo(persona dato)
{
    nodoArbol * aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->dato = dato;
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

nodoArbol * insertar(nodoArbol * arbol, nodoArbol * nuevo)
{
    if(arbol == NULL)
    {
        arbol = crearNodo(nuevo->dato);
    }
    else
    {
        if(arbol != NULL)
        {
            if(arbol->dato.legajo < nuevo->dato.legajo)
            {
                arbol->der = insertar(arbol->der, nuevo);
            }
            else
            {
                arbol->izq = insertar(arbol->izq, nuevo);
            }
        }
    }
    return arbol;
}











