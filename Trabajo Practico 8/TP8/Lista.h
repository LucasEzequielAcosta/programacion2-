#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include "Alumno.h"

typedef struct nodo{
   notaAlumno dato;
   struct nodo * siguiente;
} nodo;

nodo * inicLista();
nodo * crearNodo(int nota, int legajo, char nombre[]);
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo);

#endif // LISTA_H_INCLUDED
