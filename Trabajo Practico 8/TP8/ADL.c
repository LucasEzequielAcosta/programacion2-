#include "ADL.h"
#include "Lista.h"
#include <string.h>

int buscaPosMateria(celda adl[], char materia[], int validos)
{
    int rta = -1;
    int i = 0;

    while(i < validos && rta == -1)
    {
        if(strcmp(adl[i].materia, materia) == 0)
        {
            rta = i;
        }
        i++;
    }
    return rta;
}

int agregarMateria(celda adl[], char materia[], int IdMateria, int validos)
{
    strcpy(adl[validos].materia, materia);
    adl[validos].idMateria = IdMateria;
    adl[validos].listaDeNotas = inicLista();
    validos++;

    return validos;
}

int alta(celda adl[], char materia[], char nombre[], int nota, int legajo, int idMateria, int validos)
{
    nodo * aux = crearNodo(nota, legajo, nombre);
    int pos = buscaPosMateria(adl, materia, validos);

    if(pos == -1)
    {
        validos = agregarMateria(adl, materia, idMateria, validos);
        pos = validos-1;
    }
    adl[pos].listaDeNotas = agregarAlPrincipio(adl[pos].listaDeNotas, aux);

    return validos;
}

void mostrarADL(celda adl[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("\n\nMateria %d: %s\n",adl[i].idMateria, adl[i].materia);
        mostrarLista(adl[i].listaDeNotas);
    }
}








