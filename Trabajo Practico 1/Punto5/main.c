#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIMi = 12;
const int DIMj = 31;

void cargar(int matriz[][DIMj]);
void mostrar(int matriz[][DIMj]);
int mayorPrecipitacion(int matriz[][DIMj], int mes);
void cargarArregloPrecipitaciones(int arreglo[], int matriz[][DIMj]);
void mostrarArregloInt(int arreglo[], int validos);

int main()
{
    int matriz[DIMi][DIMj];
    cargar(matriz);
    mostrar(matriz);
/*
    int mes=0, diaMaxPrecip=0;
    printf("\n ingrese un mes \n\n");
    scanf("%i",&mes);

    diaMaxPrecip = mayorPrecipitacion(matriz,mes);
    printf("\n el dia de maxima precipitacion es %i \n\n",diaMaxPrecip);
*/
    int arreglo[12];

    cargarArregloPrecipitaciones(arreglo, matriz);

    mostrarArregloInt(arreglo, 12);

    return 0;
}

void cargar(int matriz[DIMi][DIMj])
{
    srand (time(NULL));
    for(int i=0; i<DIMi; i++)
    {
       for(int j=0; j<DIMj; j++)
       {
           matriz[i][j] = rand()%100+1;
       }
    }
}

void mostrar(int M[DIMi][DIMj])
{
    for(int x=0; x<DIMi; x++)
    {
        printf("\n\nPrecipitaciones para el mes %d", x+1);
        for(int y=0; y<DIMj; y++)
        {
            printf("\nDia %d: %d", y+1, M[x][y]);
        }
    }
}

int mayorPrecipitacion(int matriz[DIMi][DIMj], int mes)
{
    int i = 0;
    int maximoDia = 0;
    int maximaPrecip = 0;

    if(mes >= 0 && mes <= 12)
    {
        maximoDia=i+1;
        maximaPrecip = matriz[mes][i];
        i++;
        while(i < 31)
        {
            if(maximaPrecip < matriz[mes][i])
            {
                maximaPrecip = matriz[mes][i];
                maximoDia = i+1;
            }
            i++;
        }
    }
    return maximoDia;
}

void cargarArregloPrecipitaciones(int arreglo[], int matriz[DIMi][DIMj])
{
    int maxPrecip=0;
    for(int i=0; i<12; i++)
    {
        maxPrecip  = mayorPrecipitacion(matriz, i);
        arreglo[i] = maxPrecip;
    }
}

void mostrarArregloInt(int arreglo[], int validos)
{
    int i=0;
    for(i=0; i<validos; i++)
    {
        printf(" %i \t", arreglo[i]);
    }
}




