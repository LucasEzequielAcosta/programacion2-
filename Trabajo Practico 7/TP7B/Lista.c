#include "Lista.h"

nodoLista * inicLista()
{
    return NULL;
}

nodoLista * crearNodoLista(persona dato)
{
    nodoLista * aux = (nodoLista*)malloc(sizeof(nodoLista));
    aux->dato = dato;
    aux->siguiente = NULL;

    return aux;
}

nodoLista * agregarAlPrincipio(nodoLista * lista, nodoLista * nuevo)
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

nodoLista * cargarLista(nodoLista * lista)
{
    char control = 's';
    nodoLista * aux = NULL;
    persona p;

    while(control == 's')
    {
        printf("\nIngrese un nombre:");
        scanf("%s", &p.nombre);
        fflush(stdin);

        printf("\nIngrese un legajo:");
        scanf("%i", &p.legajo);
        fflush(stdin);

        printf("\nIngrese una edad:");
        scanf("%i", &p.edad);
        fflush(stdin);

        aux = crearNodoLista(p);
        lista = agregarAlPrincipio(lista, aux);

        printf("\nDesea continuar? s/n");
        scanf("%c", &control);
        fflush(stdin);
    }
    return lista;
}


