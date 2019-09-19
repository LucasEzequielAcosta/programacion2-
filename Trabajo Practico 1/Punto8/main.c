#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIM = 5;
const int DIMC = 10;

int main()
{
    int arregloA[DIM];
    int arregloB[DIM];
    int arregloC[DIMC];

    int validosA = cargar(arregloA);
    int validosB = cargar(arregloB);

    mostrarArregloInt(arregloA, validosA);
    printf("\n");
    mostrarArregloInt(arregloB, validosB);

    printf("\n");

    ordenar(arregloA);
    ordenar(arregloB);

    mostrarArregloInt(arregloA, validosA);
    printf("\n");
    mostrarArregloInt(arregloB, validosB);

    int validosC = intercalar(arregloA,arregloB,arregloC,validosA,validosB);
    printf("\n");
    mostrarArregloInt(arregloC, validosC);

    return 0;
}

int cargar(int arreglo[])
{
    int i=0;

    for(i=0; i<DIM; i++)
    {
        arreglo[i] = rand()%20;
    }
    return i;
}

void mostrarArregloInt(int arreglo[], int validos)
{
    int i=0;
    for(i=0; i<validos; i++)
    {
        printf(" %i \t", arreglo[i]);
    }
}

int posicionMenor(int arreglo[], int pos)
{
    int menor = arreglo[pos];
    int posMenor = pos;
    int i = pos+1;

    while(i<DIM)
    {
        if(menor > arreglo[i])
        {
            menor = arreglo[i];
            posMenor = i;
        }
        i++;
    }
    return posMenor;
}

void ordenar(int arreglo[])
{
    int posMenor, aux;

    for(int i=0; i<DIM-1; i++)
    {
        posMenor = posicionMenor(arreglo, i);
        aux = arreglo[posMenor];
        arreglo[posMenor] = arreglo[i];
        arreglo[i] = aux;
    }
}

int intercalar(int arregloA[], int arregloB[], int arregloC[], int validosA, int validosB)
{
    int indexB=0, indexA=0, validosC=0;

    for(int i=0; i<DIMC; i++)
    {
        if(arregloA[indexA] < arregloB[indexB])
        {
            arregloC[validosC] = arregloA[indexA];
            indexA++;
        }
        else
        {
            arregloC[validosC] = arregloB[indexB];
            indexB++;
        }
        validosC++;
    }
    return validosC;
}










