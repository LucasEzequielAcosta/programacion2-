#include <stdio.h>
#include <stdlib.h>
#include "RegistroArchivo.h"
#include "Animal.h"
#include "Arbol.h"
#include "ADA.c"

int pasarDearchivoToADA(char archivo[], celdaEspecie ada[], int validos, int dim);
nodoArbol * archivoToArbol(nodoArbol * arbol, char archivo[]);

int main()
{
    char archivo[] = {"animales.dat"};

    celdaEspecie ada[4];
    int validos = 0;
    int dim = 4;

    validos = pasarDearchivoToADA(archivo, ada, validos, dim);
    printf("\nARREGLO DE ARBOLES: ");
    mostrarADA(ada, validos);

    printf("\nARCHIVOS DE ESPECIES:\n");

    pasarDeADAToArchivosAnimales(ada, validos);
    printf("\nMAMIFEROS:\n");
    mostrarPorEspecies("mamiferos.dat");
    printf("\nAVES:\n");
    mostrarPorEspecies("aves.dat");
    printf("\nREPTILES:\n");
    mostrarPorEspecies("reptiles.dat");
    printf("\nPECES:\n");
    mostrarPorEspecies("peces.dat");

    return 0;
}

int pasarDearchivoToADA(char archivo[], celdaEspecie ada[], int validos, int dim)
{
    FILE * archi = fopen(archivo, "rb");

    if(archi)
    {
        registroArchivo reg;
        while((fread(&reg, sizeof(registroArchivo), 1, archi) > 0) && (validos <= dim))
        {
            validos = alta(ada, validos, reg.animal, reg.cant, reg.habitat, reg.idEspecie, reg.especie);
        }
    }
    fclose(archi);
    return validos;
}

void mostrarArchivo(char archivo[])
{
    registroArchivo reg;
    FILE * archi = fopen(archivo, "rb");

    while(fread(&reg, sizeof(registroArchivo), 1, archi) > 0)
    {
        printf("\nNombre: %s", reg.animal);
        printf("\nEspecie: %s", reg.especie);
        printf("\nHabitat: %i", reg.habitat);
        printf("\nCantidad: %i", reg.cant);
        printf("\nidEspecie: %i", reg.idEspecie);
        puts("\n---------------------------");
    }
    fclose(archi);
}

void mostrarPorEspecies(char archivo[])
{
    animal A;
    FILE * archi = fopen(archivo, "rb");

    while(fread(&A, sizeof(animal), 1, archi) > 0)
    {
        printf("\nNombre: %s", A.nombreAnimal);
        printf("\nHabitat: %i", A.habitat);
        printf("\nCantidad: %i", A.cantidad);
        puts("\n---------------------------");
    }
    fclose(archi);
}


nodoArbol * archivoToArbol(nodoArbol * arbol, char archivo[])
{
    FILE * archi = fopen(archivo, "rb");

    if(archi)
    {
        registroArchivo reg;
        nodoArbol * nuevo;
        while(fread(&reg, sizeof(registroArchivo), 1, archi) > 0)
        {
            nuevo = crearNodo(reg.cant, reg.habitat, reg.animal);
            arbol = insertar(arbol, nuevo);
        }
    }
    fclose(archi);
    return arbol;
}

void pasarDeADAToArchivosAnimales(celdaEspecie ada[], int validos)
{
    char especie[20];
    for(int i=0; i<validos; i++)
    {
        especie[0] = '\0';
        strcat(especie, ada[i].especie);
        strcat(especie, ".dat");

        FILE * archi = fopen(especie, "wb");
        if(archi)
        {
            guardarArbol(archi, ada[i].arbolDeAnimales);
            fclose(archi);
        }
    }
}

void guardarArbol(FILE * archi, nodoArbol * arbol)
{
    if(arbol)
    {
        guardarArbol(archi, arbol->izq);
        fwrite(&arbol->dato, sizeof(animal), 1, archi);
        guardarArbol(archi, arbol->der);
    }
}


