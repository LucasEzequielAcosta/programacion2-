#include <stdio.h>
#include <stdlib.h>
#include "Listas.c"
#include <string.h>

void cargararchivo(char archivo[]);
void mostrarDatos(char archivo[]);
nodo * archivoToLista(char archivo[], nodo * lista);
nodo * buscarPorNombre(nodo * lista, char nombre[]);
int resultadoDeBusqueda(nodo * lista, char nombre[]);
nodo * intercalarListas(nodo * listaA, nodo * listaB, nodo * listaC);
nodo * invertirLista(nodo * lista);

int main()
{
    char archivoA[] = {"archivoA.dat"};
    char archivoB[] = {"archivoB.dat"};

    cargararchivo(archivoA);
    mostrarDatos(archivoA);
    nodo * listaA = inicLista();
    listaA = archivoToLista(archivoA, listaA);
    mostrarLista(listaA);

    int f = resultadoDeBusqueda(listaA, "ivan");
    printf("\n%i\n", f);

    cargararchivo(archivoB);
    nodo * listaB = inicLista();
    listaB = archivoToLista(archivoB, listaB);
    mostrarLista(listaB);

    nodo * listaC = inicLista();
    listaC = intercalarListas(listaA, listaB, listaC);
    mostrarLista(listaC);

    listaC = invertirLista(listaC);
    mostrarLista(listaC);

    return 0;
}

void cargararchivo(char archivo[])
{
    char control = 's';
    persona P;

    FILE * archi = fopen(archivo, "ab");

    do
    {
        printf("Ingrese un nombre: \n");
        scanf("%s", &P.nombre);
        fflush(stdin);
        printf("Ingrese la edad: \n");
        scanf("%i", &P.edad);
        fflush(stdin);
        printf("Desea continuar: s/n \n ");
        scanf("%c", &control);
        fwrite(&P,sizeof(persona),1,archi);
    }
    while(control=='s');

    fclose(archi);
}

void mostrarDatos(char archivo[])
{
    FILE * archi;
    persona P;
    archi = fopen(archivo, "rb");

    printf("\narchivo: \n");
    while (fread(&P, sizeof(persona), 1, archi)>0)
    {
        printf("\n[Nombre: %s]",P.nombre);
        printf("\n[Edad: %i]\n",P.edad);
    }
    fclose(archi);
}

nodo * archivoToLista(char archivo[], nodo * lista)
{
    FILE * archi = fopen(archivo, "rb");
    persona P;
    nodo * aux;

    while(fread(&P, sizeof(persona), 1, archi)>0)
    {
        aux = crearNodo(P);
        lista = agregarEnOrden(lista, aux);
    }
    fclose(archi);

    return lista;
}

nodo * buscarPorNombre(nodo * lista, char nombre[])
{
    nodo * aux = lista;
    if(aux != NULL)
    {
        while(aux != NULL && strcmp(aux->dato.nombre, nombre)!=0)
        {
            aux = aux->siguiente;
        }
    }
    return aux;
}

int resultadoDeBusqueda(nodo * lista, char nombre[])
{
    int rta = 0;
    nodo * nodoBuscado = buscarPorNombre(lista, nombre);

    if(nodoBuscado != NULL)
    {
        rta = 1;
    }
    return rta;
}

nodo * intercalarListas(nodo * listaA, nodo * listaB, nodo * listaC)
{
    nodo * aux;

    while(listaA != NULL && listaB != NULL)
    {
        if(listaA->dato.edad < listaB->dato.edad)
        {
            aux = listaA;
            listaA = listaA->siguiente;
            aux->siguiente = NULL;
            listaC = agregarAlFinal(listaC, aux);
        }
        else
        {
            aux = listaB;
            listaB = listaB->siguiente;
            aux->siguiente = NULL;

            listaC = agregarAlFinal(listaC, aux);
        }
    }
    if(listaA != NULL)
    {
        listaC = agregarAlFinal(listaC, listaA);
    }
    else if(listaB != NULL)
    {
        listaC = agregarAlFinal(listaC, listaB);
    }
    return listaC;
}

nodo * invertirLista(nodo * lista)
{
    nodo * listaInvertida = NULL;
    nodo * aux;

    while(lista != NULL)
    {
        aux = lista;
        lista = lista->siguiente;
        aux->siguiente = NULL;

        listaInvertida = agregarAlPrincipio(listaInvertida, aux);
    }
    return listaInvertida;
}



