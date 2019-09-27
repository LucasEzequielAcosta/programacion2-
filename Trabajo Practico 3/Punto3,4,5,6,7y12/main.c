#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arreglo[10];
    //int validos = cargar(arreglo

    int validos = cargarArreglo(arreglo);

    mostrar(arreglo, validos, 0);

    int rta = capicua(arreglo, 0, validos-1);
    printf("%i \n", rta);

    if(rta == 1)
    {
        printf("es capicua");
    }
    else
    {
        printf("no es capicua");
    }

    int suma = sumar(arreglo, validos, 0);

    printf("\n suma: %i", suma);

    int menor = buscarMenor(arreglo, validos, 0);

    printf("\n menor: %i", menor);

    int elem = buscarElemento(arreglo, validos, 5, 0);

    if(elem == 1)
    {
        printf("\n se encontro el elemento");
    }
    else
    {
        printf("\n no se encontro");
    }

    return 0;
}

int cargar(int arreglo[])
{
    int i = 0;
    srand(time(NULL));

    for(i=0; i<10; i++)
    {
        arreglo[i] = rand()%100+1;
    }
    return i;
}

int cargarArreglo(int arreglo[])
{
    int validos = 0;
    char control = 's';

    while(control=='s' && validos<10)
    {
        printf("ingrese un numero\n");
        scanf("%i", &arreglo[validos]);
        validos++;
        fflush(stdin);
        printf("desea continuar? s/n \n");
        scanf("%c", &control);
    }
    return validos;
}

void mostrar(int arreglo[],int validos, int i) /// para mostrarlo invertido solo cambio de lugar la
{                                              ///   llamada recursiva y la pongo sobre el printf.
    if(i < validos)
    {
        printf("a: %i\n", arreglo[i]);
        mostrar(arreglo, validos, i+1);
    }
}

int capicua(int arreglo[], int i, int j)
{
    int rta = -1;
    if(i < j)
    {
        if(arreglo[i] == arreglo[j])
        {
            rta = capicua(arreglo, i+1, j-1);
        }
        else
        {
            rta = 0;
        }
    }
    else
    {
        rta = 1;
    }

    return rta;
}

int sumar(int arreglo[], int validos, int i)
{
    int rta = 0;

    if(i < validos)
    {
        rta = arreglo[i] + sumar(arreglo, validos, i+1);
    }
    return rta;
}

int buscarMenor(int arreglo[], int validos, int pos)
{
    int menor;

    if(pos < validos-1)
    {
        menor = buscarMenor(arreglo, validos, pos+1);
        if(menor > arreglo[pos])
        {
            menor = arreglo[pos];
        }
    }
    else
    {
        menor = arreglo[validos-1];
    }
    return menor;
}

int buscarElemento(int arreglo[], int validos, int elemento, int i)
{
    int rta = 0;

    if(i < validos)
    {
        if(elemento == arreglo[i])
        {
            rta = 1;
        }
        else
        {
            rta = buscarElemento(arreglo, validos, elemento, i+1);
        }
    }
    return rta;
}
