#include "ADA.h"
#include "Arbol.c"
#include "Animal.c"
#include <string.h>

int buscarPos(char especie[], int validos, celdaEspecie ada[])
{
    int pos = -1;
    int i = 0;

    while((i<validos) && (pos == -1))
    {
        if(strcmp(ada[i].especie, especie) == 0)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}

int agregarCelda(celdaEspecie ada[], int validos, char especie[], int idEspecie)
{
    strcpy(ada[validos].especie, especie);
    //printf("\nespecie arreglo: %s", ada[validos].especie);
    //printf("\nespecie: %s", especie);
    ada[validos].idEspecie = idEspecie;
    ada[validos].arbolDeAnimales = inicArbol();
    validos++;

    return validos;
}

int alta(celdaEspecie ada[], int validos, char nombre[], int cantidad, int habitat, int idEspecie, char especie[])
{
    nodoArbol * nuevo = crearNodo(cantidad, habitat, nombre);
    int pos = buscarPos(especie, validos, ada);

    if(pos == -1)
    {
        validos = agregarCelda(ada, validos, especie, idEspecie);
        pos = validos-1;
    }
    ada[pos].arbolDeAnimales = insertar(ada[pos].arbolDeAnimales, nuevo);

    return validos;
}

void mostrarADA(celdaEspecie ada[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("\nESPECIE %i: %s\n", ada[i].idEspecie, ada[i].especie);
        inorder(ada[i].arbolDeAnimales);
    }
}













