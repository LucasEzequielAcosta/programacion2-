#include "ListaDoble.h"

nodoDoble * inicLista()
{
    return NULL;
}

nodoDoble * crearNodo(persona dato)
{
    nodoDoble * aux = (nodoDoble*)malloc(sizeof(nodoDoble));
    aux->dato = dato;
    aux->anterior = NULL;
    aux->siguiente = NULL;

    return aux;
}

nodoDoble * agregarAlPrincipio(nodoDoble * lista, nodoDoble * nuevoNodo)
{
    nuevoNodo->siguiente = lista;

    if(lista != NULL)
    {
        lista->anterior = nuevoNodo;
    }
    return nuevoNodo;
}

nodoDoble * buscarUltimoRec(nodoDoble * lista)
{
    nodoDoble * rta;
    if(lista == NULL)
    {
        rta = NULL;
    }
    else
    {
        if(lista->siguiente == NULL)
        {
            rta = lista;
        }
        else
        {
            rta = buscarUltimoRec(lista->siguiente);
        }
    }
    return rta;
}

nodoDoble * buscarUltimo(nodoDoble * lista)
{
    nodoDoble * aux;
    if(lista != NULL)
    {
        if(lista->siguiente == NULL)
        {
            aux = lista;
        }
        else
        {
            aux = lista;
            while(aux->siguiente != NULL)
            {
                aux = aux->siguiente;
            }
        }
    }
    else
    {
        aux = NULL;
    }
    return aux;
}

nodoDoble * agregarAlFinal(nodoDoble * lista, nodoDoble * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nodoDoble * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
    }
    return lista;
}

nodoDoble * agregarEnOrden(nodoDoble * lista, nodoDoble * nuevoNodo)
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
           nodoDoble * seguidora;
           nodoDoble * aux = lista->siguiente;
           while(aux != NULL && aux->dato.edad < nuevoNodo->dato.edad)
           {
                seguidora = aux;
                aux = aux->siguiente;
           }
           seguidora->siguiente = nuevoNodo;
           nuevoNodo->anterior = seguidora;
           nuevoNodo->siguiente = aux;
           if(aux != NULL)
           {
                aux->anterior = nuevoNodo;
           }
       }
    }
    return lista;
}

persona cargarPersona()
{
    persona aux;

    fflush(stdin);
    printf("\nIngrese nombre: ");
    gets(aux.nombre);
    fflush(stdin);
    printf("\nIngrese edad:");
    scanf("%d", &aux.edad);
    fflush(stdin);

    return aux;
}

nodoDoble * cargarLista(nodoDoble * lista)
{
    char control = 's';
    persona aux;

    while(control == 's')
    {
        fflush(stdin);
        aux = cargarPersona();
        nodoDoble * nuevoNodo = crearNodo(aux);
        lista = agregarAlPrincipio(lista, nuevoNodo);
        printf("\ndesea continuar? s/n ");
        scanf("%c", &control);
    }
    return lista;
}

void mostrarPersona(persona dato)
{
    printf("-----------------------\n");
    printf("Nombre: %s \n", dato.nombre);
    printf("  Edad: %d \n", dato.edad);
    printf("-----------------------\n");
}

void mostrarNodo(nodoDoble * aux)
{
    mostrarPersona(aux->dato);
}

void recorrerYmostrarLista(nodoDoble * lista)
{
    nodoDoble * seg = lista;

    while(seg != NULL)
    {
        mostrarNodo(seg);
        seg = seg->siguiente;
    }
}





