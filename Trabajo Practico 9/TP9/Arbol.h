#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Animal.h"

typedef struct nodoArbol
{
   animal dato;
   struct nodoArbol * izq;
   struct nodoArbol * der;
} nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodo(int cantidad, int habitat, char nombre[]);
nodoArbol * insertar (nodoArbol* arbol, nodoArbol* nuevo);

#endif // ARBOL_H_INCLUDED
