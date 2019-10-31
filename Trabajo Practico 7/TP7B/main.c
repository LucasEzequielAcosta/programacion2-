#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arbol.c"
#include "Lista.c"
#include "Persona.c"

nodoArbol * cargarPersonas(nodoArbol * arbol);
void mostrarPersona(persona p);
void preorder(nodoArbol * arbol);
void inorder(nodoArbol * arbol);
void posorder(nodoArbol * arbol);
void mostrarLista(nodoLista * lista);
nodoLista * arbolToLista(nodoArbol * arbol, nodoLista * lista);
nodoArbol * buscarPorLegajo(nodoArbol * arbol, int legajo);
nodoArbol * buscarPorNombre(nodoArbol * arbol, char nombre[]);
int mayorValor(int a, int b);
int calcularAltura(nodoArbol * arbol);
int cantDeNodos(nodoArbol * arbol);
int eshoja(nodoArbol * arbol);
int cantDeHojas(nodoArbol * arbol);
nodoArbol * borrarNodo(nodoArbol * arbol, int legajo);

int main()
{
    nodoArbol * arbol = inicArbol();
    arbol = cargarPersonas(arbol);
    printf("\nARBOL:");
    inorder(arbol);

    nodoLista * lista = inicLista();
    lista = arbolToLista(arbol, lista);
    printf("\nLISTA:");
    mostrarLista(lista);

    nodoArbol * buscadoXlegajo = NULL;
    buscadoXlegajo = buscarPorLegajo(arbol, 3);
    printf("\nBuscado:");
    mostrarPersona(buscadoXlegajo->dato);

    nodoArbol * buscadoXnombre = NULL;
    buscadoXnombre = buscarPorNombre(arbol, "lucas");
    printf("\nBuscado:");
    mostrarPersona(buscadoXnombre->dato);

    int altura = calcularAltura(arbol);
    printf("\nAltura: %i", altura);

    int nodos = cantDeNodos(arbol);
    printf("\nNodos: %i", nodos);

    int hojas = cantDeHojas(arbol);
    printf("\nHojas: %i", hojas);

    arbol = borrarNodo(arbol, 2);
    printf("\nARBOL DESPUES DE BORRAR:");
    inorder(arbol);

    return 0;
}

nodoArbol * cargarPersonas(nodoArbol * arbol)
{
    char control = 's';
    nodoArbol * aux = NULL;
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

        aux = crearNodo(p);
        arbol = insertar(arbol, aux);

        printf("\nDesea continuar? s/n");
        scanf("%c", &control);
        fflush(stdin);
    }
    return arbol;
}

void preorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        mostrarPersona(arbol->dato);
        preorder(arbol->izq);
        preorder(arbol->der);
    }
}

void inorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        inorder(arbol->izq);
        mostrarPersona(arbol->dato);
        inorder(arbol->der);
    }
}

void posorder(nodoArbol * arbol)
{
    if(arbol != NULL)
    {
        posorder(arbol->izq);
        posorder(arbol->der);
        mostrarPersona(arbol->dato);
    }
}

void mostrarLista(nodoLista * lista)
{
    nodoLista * seg = lista;
    while(seg != NULL)
    {
        mostrarPersona(seg->dato);
        seg = seg->siguiente;
    }
}

nodoLista * arbolToLista(nodoArbol * arbol, nodoLista * lista)
{
    nodoLista * aux = NULL;
    if(arbol != NULL)
    {
        aux = crearNodoLista(arbol->dato);
        lista = agregarAlPrincipio(lista, aux);
        lista = arbolToLista(arbol->izq, lista);
        lista = arbolToLista(arbol->der, lista);
    }
    return lista;
}

nodoArbol * buscarPorLegajo(nodoArbol * arbol, int legajo)
{
    nodoArbol * rta = NULL;

    if(arbol != NULL)
    {
        if(arbol->dato.legajo == legajo)
        {
            rta = arbol;
        }
        else
        {
            if(arbol->dato.legajo < legajo)
            {
                rta = buscarPorLegajo(arbol->der, legajo);
            }
            else
            {
                rta = buscarPorLegajo(arbol->izq, legajo);
            }
        }
    }
    return rta;
}

nodoArbol * buscarPorNombre(nodoArbol * arbol, char nombre[])
{
    nodoArbol  * rta = NULL;

    if(arbol != NULL)
    {
        if(strcmp(arbol->dato.nombre, nombre) == 0)
        {
            rta = arbol;
        }
        else
        {
            rta = buscarPorNombre(arbol->izq, nombre);
            if(rta == NULL)
            {
                rta = buscarPorNombre(arbol->der, nombre);
            }
        }
    }
    return rta;
}

int mayorValor(int a, int b)
{
    int rta;

    if(a > b)
    {
        rta = a;
    }
    else
    {
        rta = b;
    }
    return rta;
}

int calcularAltura(nodoArbol * arbol)
{
    int alturaI = 0;
    int alturaD = 0;

    if(arbol != NULL)
    {
        if(arbol->izq != NULL)
        {
            alturaI = calcularAltura(arbol->izq);
        }
        if(arbol->der != NULL)
        {
            alturaD = calcularAltura(arbol->der);
        }
    }
    return 1 + mayorValor(alturaD, alturaI);
}

int cantDeNodos(nodoArbol * arbol)
{
    int rta;

    if(arbol == NULL)
    {
        rta = 0;
    }
    else
    {
        rta = 1 + cantDeNodos(arbol->izq) + cantDeNodos(arbol->der);
    }
    return rta;
}

int eshoja(nodoArbol * arbol)
{
    int rta = 0;
    if(arbol)
    {
        if(arbol->izq == NULL && arbol->der == NULL)
        {
            rta = 1;
        }
    }
    return rta;
}

int cantDeHojas(nodoArbol * arbol)
{
    int hojas;
    if(arbol == NULL)
    {
        hojas = 0;
    }
    else
    {
        if(eshoja(arbol))
        {
            hojas = 1;
        }
        else
        {
            hojas = cantDeHojas(arbol->izq) + cantDeHojas(arbol->der);
        }
    }
    return hojas;
}

nodoArbol * NMD(nodoArbol* arbol)
{
    if(arbol)
    {
        if(arbol->der)
        {
            arbol->der = NMD(arbol->der);
        }
    }
    return arbol;
}

nodoArbol * NMI(nodoArbol* arbol)
{
    if(arbol)
    {
        if(arbol->izq)
        {
            arbol->izq = NMI(arbol->izq);
        }
    }
    return arbol;
}

nodoArbol * borrarNodo(nodoArbol * arbol, int legajo)
{
    if(arbol != NULL)
    {
        if(arbol->dato.legajo == legajo)
        {
            if(arbol->izq != NULL)
            {
                nodoArbol * masDer = NMD(arbol->izq);
                arbol = masDer;
                arbol->izq =  borrarNodo(arbol->izq , masDer->dato.legajo);
            }
            else
            {
                if(arbol->der != NULL)
                {
                    nodoArbol * masIzq = NMI(arbol->der);
                    arbol = masIzq;
                    arbol->der = borrarNodo(arbol->der, masIzq->dato.legajo);
                }
                else
                {
                    free(arbol);
                    arbol = NULL;
                }
            }
        }
        else
        {
            if(arbol->dato.legajo < legajo)
            {
                arbol->der = borrarNodo(arbol->der, legajo);
            }
            else
            {
                arbol->izq = borrarNodo(arbol->izq, legajo);
            }
        }
    }
    return arbol;
}































