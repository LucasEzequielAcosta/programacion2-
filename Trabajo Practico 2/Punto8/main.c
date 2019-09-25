#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int matricula;
  char nombre[30];
}Alumno;

typedef struct {
  int codigo;
  char nombreMat[20];
}Materia ;

typedef struct {
  int matricula;
  int codigo;
  int nota;
}Nota;


int main()
{
    Alumno alus[20]; // para almacenar los datos de los 20 alumnos.
    Materia mats[5]; // para almacenar los códigos y nombres de las 5 materias.
    Nota notas[100]; // para almacenar todas las notas de los alumnos.

    int validosM = cargarMaterias(mats);
    mostrarMaterias(mats, validosM);

    int validosA = cargarAlumnos(alus);
    mostrarAlumnos(alus, validosA);

    int validosN = cargarNotas(notas, mats, alus, validosA, validosM);

    mostrarNotas(notas, validosN);

    return 0;
}

int cargarMaterias(Materia mats[])
{
    char control = 's';
    int validos = 0;

    while(control=='s' && validos<5)
    {
        fflush(stdin);
        printf("ingrese una materia \n");
        scanf("%s", &mats[validos].nombreMat);
        fflush(stdin);

        printf("ingrese un codigo \n");
        scanf("%i", &mats[validos].codigo);
        fflush(stdin);

        validos++;

        printf("desea continuar? \n");
        scanf("%c", &control);
    }
    return validos;
}

void mostrarMaterias(Materia mats[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("\n Materia: %s\n", mats[i].nombreMat);
        printf("\n Codigo: %i\n", mats[i].codigo);
        printf("---------------------\n");
    }
}

int cargarAlumnos(Alumno alum[])
{
    char control = 's';
    int validos = 0;

    while(control=='s' && validos<20)
    {
        fflush(stdin);
        printf("ingrese un nombre \n");
        scanf("%s", &alum[validos].nombre);
        fflush(stdin);

        printf("ingrese una matricula \n");
        scanf("%i", &alum[validos].matricula);
        fflush(stdin);

        validos++;

        printf("desea continuar? \n");
        scanf("%c", &control);
    }
    return validos;
}

void mostrarAlumnos(Alumno alum[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("\n Nombre: %s\n", alum[i].nombre);
        printf("\n Matricula: %i\n", alum[i].matricula);
        printf("---------------------\n");
    }
}

int validarMatricula(Alumno alum[], int validos, int matricula)
{
    int f, i = 0;

    while(alum[i].matricula != matricula && i<validos)
    {
        f = 0;
        i++;
    }
    if(alum[i].matricula == matricula)
    {
        f = 1;
    }

    return f;
}

int validarCodigo(Materia mats[], int validos, int codigo)
{
    int f, i = 0;

    while(mats[i].codigo != codigo && i<validos)
    {
        f = 0;
        i++;
    }
    if(mats[i].codigo == codigo)
    {
        f = 1;
    }

    return f;
}

int cargarNotas(Nota notas[], Materia mats[], Alumno alum[], int validosA, int validosM)
{
    char control = 's';
    int validos = 0;
    int f;
    int matricula, codigo;

    while(control=='s' && validos<100)
    {
        fflush(stdin);
        do
        {
            printf("ingrese una matricula \n");
            scanf("%i", &matricula);
            f = validarMatricula(alum, validosA, matricula);
            if(f == 1)
            {
                notas[validos].matricula = matricula;
            }
            else
            {
                printf("\nla matricula no existe\n");
            }
            fflush(stdin);
        }
        while(f == 0);

        f=0;

        do
        {
            printf("ingrese un codigo \n");
            scanf("%i", &codigo);
            f = validarCodigo(mats, validosM, codigo);
            if(f == 1)
            {
                notas[validos].codigo = codigo;
            }
            else
            {
                printf("\nel codigo no existe\n");
            }
            fflush(stdin);
        }
        while(f == 0);

        printf("ingrese una nota \n");
        scanf("%i", &notas[validos].nota);
        fflush(stdin);

        validos++;

        printf("desea continuar? \n");
        scanf("%c", &control);
    }
    return validos;
}

void mostrarNotas(Nota notas[], int validos)
{
    for(int i=0; i<validos; i++)
    {
        printf("\n Matricula: %i\n", notas[i].matricula);
        printf("\n Codigo: %i\n", notas[i].codigo);
        printf("\n Nota: %i\n", notas[i].nota);
        printf("---------------------\n");
    }
}


void mostrar(char nombre)
{
    for(int i=0; )
}




