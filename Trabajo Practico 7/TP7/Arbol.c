#include "Arbol.h"

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodo(int dato)
{
    nodoArbol * aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->der = NULL;
    aux->izq = NULL;
    aux->dato = dato;

    return aux;
}

nodoArbol * insertar(nodoArbol * arbol, int dato)
{
    if(arbol == NULL)
    {
        arbol = crearNodo(dato);
    }
    else
    {
        if(arbol->dato < dato)
        {
            arbol->der = insertar(arbol->der, dato);
        }
        else
        {
            arbol->izq = insertar(arbol->izq, dato);
        }
    }
    return arbol;
}

nodoArbol * buscar(nodoArbol * arbol, int dato)
{
    nodoArbol * rta = NULL;

    if(arbol != NULL)
    {
        if(arbol->dato == dato)
        {
            rta = arbol;
        }
        else
        {
            if(arbol->dato < dato)
            {
                rta = buscar(arbol->der, dato);
            }
            else
            {
                rta = buscar(arbol->izq, dato);
            }
        }
    }
    return rta;
}

void preorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        printf("\n%d", arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->izq);
        printf("\n%d", arbol->dato);
        inorder(arbol->der);
    }
}

void posorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        posorder(arbol->izq);
        posorder(arbol->der);
        printf("\n%d", arbol->dato);
    }
}



