#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct nodo * siguiente;
} nodo;

nodo * inicLista();
nodo * crearNodo(int dato);
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * agregarAlFinal(nodo * lista, nodo* nuevoNodo);
nodo * cargarLista(nodo * lista);
void mostrarLista(nodo * lista);
void recorrerYmostrar(nodo * lista);
nodo * invertirLista(nodo * lista);
nodo * borrarNodo(nodo * lista, int dato);
nodo * insertarEnOrden(nodo * lista, nodo * nuevoNodo);

int main()
{
    nodo * lista = inicLista();
    lista = cargarLista(lista);
    recorrerYmostrar(lista);

    int suma = sumar(lista);
    printf("\nsuma: %i", suma);

    lista = invertirLista(lista);
    printf("\nContenido de la lista despues de invertirla:");
    recorrerYmostrar(lista);

    lista = borrarNodo(lista, 3);
    printf("\nContenido de la lista despues de borrar un dato:");
    recorrerYmostrar(lista);

    lista = insertarEnOrden(lista , crearNodo(3));
    printf("\nContenido de la lista despues de insertar un dato:");
    recorrerYmostrar(lista);

    return 0;
}

nodo * inicLista()
{
    return NULL;
}

nodo * crearNodo(int dato)
{
    nodo * aux = (nodo*)malloc(sizeof(nodo));
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

nodo * buscarUltimo(nodo * lista)
{
    nodo * seguidora = lista;
    if(seguidora)
    {
        while(seguidora->siguiente != NULL)
        {
            seguidora = seguidora->siguiente;
        }
    }
    return seguidora;
}

nodo * agregarAlFinal(nodo * lista, nodo* nuevoNodo)
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

nodo * cargarLista(nodo * lista)
{
    char control = 's';
    int dato;
    nodo * aux;

    while(control == 's')
    {
        printf("ingrese un dato\n");
        scanf("%i", &dato);
        fflush(stdin);

        aux = crearNodo(dato);
        lista = agregarAlPrincipio(lista, aux);

        printf("desea continuar?\n");
        scanf("%c", &control);
        fflush(stdin);
    }
    return lista;
}

void mostrarLista(nodo * lista)
{
    printf("\ndato :%i", lista->dato);
}

void recorrerYmostrar(nodo * lista)
{
    nodo * seguidora = lista;
    if(seguidora != NULL)
    {
        mostrarLista(seguidora);
        recorrerYmostrar(seguidora->siguiente);
    }
}

int sumar(nodo * lista)
{
    int rta;
    nodo * seguidora = lista;

    if(seguidora == NULL)
    {
        rta = 0;
    }
    else
    {
        rta = seguidora->dato + sumar(seguidora->siguiente);
    }
    return rta;
}

void mostrarPares(nodo * lista, int pos)
{
    nodo * seguidora = lista;

    if(seguidora != NULL)
    {
        if(pos %2 == 0)
        {
            mostrarLista(seguidora);
            mostrarPares(seguidora->siguiente, pos+1);
        }
        else
        {
            mostrarPares(seguidora->siguiente, pos+1);
        }
    }
}

nodo * invertirLista(nodo * lista)
{
    nodo * primero = NULL;

    if(lista != NULL)
    {
        primero = lista;
        lista = lista->siguiente;
        primero->siguiente = NULL;
        lista = agregarAlFinal(invertirLista(lista), primero);
    }
    return lista;
}

nodo * borrarNodo(nodo * lista, int dato)
{
    nodo * aBorrar = NULL;
    if(lista != NULL)
    {
        if(lista->dato == dato)
        {
            aBorrar = lista;
            lista = lista->siguiente;
            free(aBorrar);
        }
        else
        {
            lista->siguiente = borrarNodo(lista->siguiente, dato);
        }
    }
    return lista;
}

nodo * insertarEnOrden(nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if(lista->dato > nuevoNodo->dato)
        {
            nuevoNodo->siguiente = lista;
            lista = nuevoNodo;
        }
        else
        {
            lista->siguiente = insertarEnOrden(lista->siguiente, nuevoNodo);
        }
    }
    return lista;
}










