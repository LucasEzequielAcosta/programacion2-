#ifndef ADL_H_INCLUDED
#define ADL_H_INCLUDED
#include "Lista.h"

typedef struct {
    int idMateria;
    char materia[30];
    nodo * listaDeNotas;
} celda;

int buscaPosMateria(celda adl[], char materia[], int validos);
int agregarMateria(celda adl[], char materia[], int idMateria, int validos);
int alta(celda adl[], char materia[], char nombre[], int nota, int legajo, int idMateria, int validos);
void mostrarADL(celda adl[], int validos);

#endif // ADL_H_INCLUDED
