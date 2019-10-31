#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "Persona.h"

typedef struct nodoArbol{
     persona dato;
     struct nodoArbol * izq;
     struct nodoArbol * der;
} nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodo(persona dato);
nodoArbol * insertar(nodoArbol * arbol, nodoArbol * nuevo);

#endif // ARBOL_H_INCLUDED
