#ifndef ADA_H_INCLUDED
#define ADA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"

typedef struct
{
   int idEspecie;
   char especie [20];
 	 // "Mamiferos", "Aves"
       // "Reptiles", "Peces"
   nodoArbol * arbolDeAnimales;
} celdaEspecie;

int buscarPos(char especie[], int validos, celdaEspecie ada[]);
int agregarCelda(celdaEspecie ada[], int validos, char especie[], int idEspecie);
int alta(celdaEspecie ada[], int validos, char nombre[], int cantidad, int habitat, int idEspecie, char especie[]);

#endif // ADA_H_INCLUDED
