#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombre[20];
    int edad;
} persona;

typedef struct nodo
{
    persona dato;
    struct nodo * siguiente;
}nodo;


nodo * inicLista();
nodo * crearNodo(persona dato);
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevoNodo);
nodo * agregarAlFinal(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * borrarTodaLaLista(nodo * lista);
nodo * eliminarUltimoNodo(nodo * lista);
nodo * eliminarPrimerNodo(nodo * lista);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);
void mostrarLista(nodo * lista);

#endif // LISTAS_H_INCLUDED
