#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Persona.h"

typedef struct nodoLista{
     persona dato;
     struct nodoLista * siguiente;
} nodoLista;

nodoLista * inicLista();
nodoLista * crearNodoLista(persona dato);
nodoLista * agregarAlPrincipio(nodoLista * lista, nodoLista * nuevo);
nodoLista * cargarLista(nodoLista * lista);

#endif // LISTA_H_INCLUDED
