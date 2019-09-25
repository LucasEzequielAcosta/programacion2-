#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[30];
    char genero;
    int edad;
} persona;

int cuentaPorGenero(persona p[], char genero, int validos);
int arregloDeVarones(persona p[], int validos, persona varones[], char genero);

int main()
{
    persona personas[30];

    int validos = cargarPersona(personas);
    muestraArregloPersonas(personas, validos);

    ordenarPorSeleccion(personas, validos);
    muestraArregloPersonas(personas, validos);

    int cantidadM = cuentaPorGenero(personas, 'm', validos);
    int cantidadF = cuentaPorGenero(personas, 'f', validos);

    printf("\n hay %i hombres", cantidadM);

    persona * listaVarones = malloc(cantidadM * sizeof(persona));

    int validosVarones = arregloDeVarones(personas, validos, listaVarones, 'm');
    muestraArregloPersonas(listaVarones, validosVarones);

    return 0;
}

int cargarPersona(persona p[])
{
    char control = 's';
    int i = 0;

    while(control=='s' && i<30)
    {
        printf("ingrese un nombre: \n");
        fflush(stdin);
        scanf("%s", &p[i].nombre);

        printf("ingrese genero: \n");
        fflush(stdin);
        scanf("%c", &p[i].genero);

        printf("ingrese edad: \n");
        fflush(stdin);
        scanf("%i", &p[i].edad);

        i++;

        printf("desea continuar s/n \n");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}

void muestraArregloPersonas(persona A[], int val)
{
    int i=0;

    printf("\nContenido del arreglo de personas: \n");
    for(i=0; i<val; i++)
    {
        printf("\nNombre: %s", A[i].nombre);
        printf("\ngenero: %c", A[i].genero);
        printf("\nEdad: %d", A[i].edad);
    }
}

int cuentaPorGenero(persona p[], char genero, int validos)
{
    int contador=0;
    for(int i=0; i<validos; i++)
    {
        if(p[i].genero == genero)
        {
            contador++;
        }
    }
    return contador;
}

int arregloDeVarones(persona p[], int validos, persona varones[], char genero)
{
    int x = 0;

    for(int i=0; i<validos; i++)
    {
        if(p[i].genero == genero)
        {
            varones[x] = p[i];
            x++;
        }
    }
    return x;
}

int posicionMenor(persona p[], int validos, int pos)
{
    persona menor = p[pos];
    int posMenor = pos;
    int i = pos+1;

    while(i < validos)
    {
        if(menor.edad > p[i].edad)
        {
            menor = p[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenarPorSeleccion(persona p[], int validos)
{
    int i = 0;
    int posMenor = 0;
    persona aux;

    while(i < validos-1)
    {
        posMenor = posicionMenor(p, validos, i);
        aux = p[posMenor];
        p[posMenor] = p[i];
        p[i] = aux;
        i++;
    }
}






