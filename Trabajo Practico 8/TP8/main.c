#include <stdio.h>
#include <stdlib.h>
#include "Lista.c"
#include "Alumno.c"
#include "ADL.c"

typedef struct {
   int nota;
   int legajo;
   char nombreApe[30];
   char materia[30];
   int idMateria;
} registroArchivo;

void cargarArchivo(char archivo[]);
void mostrarRegistro(registroArchivo reg);
void mostrarArchivo(char archivo[]);
int pasarDeArchivoToADL(char archivo[], celda adl[]);

int main()
{
    char archivo[] = {"Archivo.dat"};
    char archivoDeAprobados[] = {"ArchivoDeAprobados.dat"};

    cargarArchivo(archivo);
    mostrarArchivo(archivo);

    celda adl[20];
    int validos = pasarDeArchivoToADL(archivo, adl);
    printf("\nArreglo de Listas:");
    mostrarADL(adl, validos);

    pasarDeADLToArchivoDeAprobados(archivoDeAprobados, adl, validos);
    printf("\nAprobados:");
    mostrarArchivo(archivoDeAprobados);



    return 0;
}

void cargarArchivo(char archivo[])
{
    registroArchivo reg;
    char control = 's';
    FILE * archi = fopen(archivo, "ab");

    printf("Desea cargar el archivo? s/n \n");
    scanf("%c", &control);

    while(control == 's')
    {
        printf("\nIngrese Nombre:");
        fflush(stdin);
        scanf("%s", &reg.nombreApe);

        printf("\nIngrese Materia:");
        fflush(stdin);
        scanf("%s", &reg.materia);

        printf("\nIngrese Nota:");
        fflush(stdin);
        scanf("%i", &reg.nota);

        printf("\nIngrese Legajo:");
        fflush(stdin);
        scanf("%i", &reg.legajo);

        printf("\nIngrese IdMateria:");
        fflush(stdin);
        scanf("%i", &reg.idMateria);

        fwrite(&reg, sizeof(registroArchivo), 1, archi);

        printf("\nDesea Continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);
    }
    fclose(archi);
}

void mostrarRegistro(registroArchivo reg)
{
    printf("\n[Nombre: %s]",reg.nombreApe);
    printf("\n[Materia: %s]",reg.materia);
    printf("\n[Nota: %i]",reg.nota);
    printf("\n[Legajo: %i]",reg.legajo);
    printf("\n[IdMateria: %i]",reg.idMateria);
    puts("\n----------------------------------");
}

void mostrarArchivo(char archivo[])
{
    FILE * archi = fopen(archivo, "rb");
    registroArchivo reg;

    if(archi)
    {
        while(fread(&reg, sizeof(registroArchivo), 1, archi) > 0)
        {
            mostrarRegistro(reg);
        }
    }
    fclose(archi);
}

int pasarDeArchivoToADL(char archivo[], celda adl[])
{
    FILE * archi = fopen(archivo, "rb");
    registroArchivo reg;
    int validos = 0;

    if(archi)
    {
        while(fread(&reg, sizeof(registroArchivo), 1, archi) > 0)
        {
            validos = alta(adl, reg.materia, reg.nombreApe, reg.nota, reg.legajo, reg.idMateria, validos);
        }
    }
    fclose(archi);

    return validos;
}

void pasarDeADLToArchivoDeAprobados(char archivo[], celda adl[], int validos)
{
    FILE * archi = fopen(archivo, "wb");
    registroArchivo reg;

    for(int i=0; i<validos; i++)
    {
        strcpy(reg.materia, adl[i].materia);
        reg.idMateria = adl[i].idMateria;
        nodo * seg = adl[i].listaDeNotas;

        while(seg)
        {
            reg.legajo = seg->dato.legajo;
            reg.nota = seg->dato.nota;
            strcpy(reg.nombreApe, seg->dato.nombreApe);
            if(seg->dato.nota >= 6)
            {
                fwrite(&reg, sizeof(registroArchivo), 1, archi);
            }
            seg = seg->siguiente;
        }
    }
    fclose(archi);
}







