#include <stdio.h>
#include <stdlib.h>
#include "ListaDoble.c"
#include <string.h>

nodoDoble * borrarNodoPorNombre(nodoDoble * lista, char nombre[]);
int capicua(nodoDoble * cabeza, nodoDoble * cola);

int main()
{
    nodoDoble * lista = inicLista();
    lista = cargarLista(lista);
    recorrerYmostrarLista(lista);

    //lista = borrarNodoPorNombre(lista, "lucas");
    //recorrerYmostrarLista(lista);

    int rta = capicua(lista, buscarUltimo(lista));

    printf("\n %i", rta);

    return 0;
}

nodoDoble * borrarNodoPorNombre(nodoDoble * lista, char nombre[])
{
    nodoDoble * aBorrar;

    if(lista != NULL)
    {
        if((strcmp(lista->dato.nombre, nombre)==0))
        {
            aBorrar = lista;
            if(lista != NULL)
            {
                lista = lista->siguiente;
            }
            free(aBorrar);
        }
        else
        {
            nodoDoble * aux = lista->siguiente;
            while(aux != NULL && strcmp(aux->dato.nombre, nombre)!=0)
            {
                aux = aux->siguiente;
            }
            if(aux != NULL)
            {
                nodoDoble * ante = aux->anterior;
                ante->siguiente = aux->siguiente;
                if(aux->siguiente)
                {
                    nodoDoble * sgte = aux->siguiente;
                    sgte->anterior = ante;
                }
                free(aux);
            }
        }
    }
    return lista;
}

int capicua(nodoDoble * cabeza, nodoDoble * cola)
{
    int rta = 0;

    if(cabeza != NULL && cola != NULL)
    {
        if(cabeza->dato.edad != cola->dato.edad)
        {
            rta = 0;
        }
        else
        {
            if(cabeza != cola && cabeza->anterior != cola)
            {
                rta = capicua(cabeza->siguiente, cola->anterior);
            }
            else
            {
                rta = 1;
            }
        }
    }
    return rta;
}









