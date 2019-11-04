#include "Lista.h"
#include "Alumno.h"
#include <string.h>

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(int nota, int legajo, char nombre[])
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
    aux->dato.nota = nota;
    aux->dato.legajo = legajo;
    strcpy(aux->dato.nombreApe, nombre);
    aux->siguiente = NULL;

    return aux;
}

nodo * agregarAlPrincipio(nodo * lista, nodo * nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }
    return lista;
}

void mostrarLista(nodo * lista)
{
    nodo * seg = lista;
    while(seg)
    {
        mostrarAlumno(seg->dato);
        seg = seg->siguiente;
    }
}




