#include "Arbol.h"
#include <string.h>

nodoArbol * inicArbol()
{
    return NULL;
}

nodoArbol * crearNodo(int cantidad, int habitat, char nombre[])
{
    nodoArbol * aux = (nodoArbol*)malloc(sizeof(nodoArbol));
    aux->dato.cantidad = cantidad;
    aux->dato.habitat = habitat;
    strcpy(aux->dato.nombreAnimal, nombre);
    aux->der = NULL;
    aux->izq = NULL;

    return aux;
}

nodoArbol * insertar (nodoArbol* arbol, nodoArbol* nuevo){
    if(arbol==NULL){
        arbol = nuevo;
    }else{
        if(nuevo->dato.cantidad > arbol->dato.cantidad){
            arbol->der=insertar(arbol->der, nuevo);
        }else{
            arbol->izq=insertar(arbol->izq, nuevo);
        }
    }
    return arbol;
}

void inorder(nodoArbol * arbol)
{
    if(arbol)
    {
        inorder(arbol->izq);
        mostrarAnimal(arbol->dato);
        inorder(arbol->der);
    }
}






