#include "Listas.h"

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(persona dato)
{
    nodo * aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;

    return aux;
}

nodo * agregarAlPrincipio(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}

nodo * agregarAlFinal(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
    }
    return lista;
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * seg = lista;

    if(seg)
    {
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}

nodo * borrarTodaLaLista(nodo * lista)
{
    nodo * seg = lista;
    nodo * proximo;

    while(seg != NULL)
    {
        proximo = seg->siguiente;
        free(seg);
        seg = proximo;
    }
    return seg;
}

nodo * eliminarUltimoNodo(nodo * lista)
{
    nodo * aux;
    nodo * ante;

    if(lista)
    {
        if(lista->siguiente == NULL)
        {
            aux = lista;
            lista = lista->siguiente;
            free(aux);
        }
        else
        {
            aux = lista;
            while(aux->siguiente != NULL)
            {
                ante = aux;
                aux = aux->siguiente;
            }
            free(aux);
            ante->siguiente = NULL;
        }
    }
    return lista;
}

nodo * eliminarPrimerNodo(nodo * lista)
{
    nodo * aux;
    if(lista)
    {
        aux = lista;
        lista = lista->siguiente;
        free(aux);
    }
    return lista;
}

void mostrarLista(nodo * lista)
{
    printf("\n LISTA: \n");
    while(lista != NULL)
    {
        printf("\n[Nombre: %s]",lista->dato.nombre);
        printf("\n[Edad: %i]\n",lista->dato.edad);
        lista = lista->siguiente;
    }
}

nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(lista->dato.edad > nuevoNodo->dato.edad)
        {
            lista = agregarAlPrincipio(lista, nuevoNodo);
        }
        else
        {
            nodo * anterior = lista;
            nodo * seguidora = lista->siguiente;
            while( seguidora != NULL && seguidora->dato.edad < nuevoNodo->dato.edad)
            {
                anterior = seguidora;
                seguidora = seguidora->siguiente;
            }
            nuevoNodo->siguiente = seguidora;
            anterior->siguiente = nuevoNodo;
        }
    }
    return lista;
}









