#include <stdio.h>
#include <stdlib.h>

const char archivo[] = {"archivo.dat"};

int main()
{
    cargarDatos();
    mostrarDatos();

    return 0;
}

void cargarDatos()
{
    char control='s';
    int z=0;

    FILE * archi;
    archi = fopen(archivo, "ab");

    do
    {
        printf("Ingrese un numero: \n");
        scanf("%i", &z);
        fflush(stdin);
        printf("Desea continuar: s/n \n ");
        scanf("%c", &control);
        fwrite(&z,sizeof(int),1,archi);
    }
    while(control=='s');
    fclose(archi);
}

void mostrarDatos()
{
    FILE * archi;
    int i=0;

    archi = fopen(archivo, "rb");

    while (fread(&i, sizeof(int), 1, archi)>0)
    {
        printf("[%i]-",i);
    }
    printf("\n");
}

int buscarMenorArchivoRec(int i, int menor)
{

    int temporal=0;
    FILE *archi=fopen(archivo, "rb");
    fseek(archi,sizeof(int)*(i),SEEK_SET);

    if(fread(&temporal,sizeof(int),1,archi)>0)
    {
        if (temporal < menor )
        {
            menor = temporal;
        }
        menor=buscarMenorArchivoRec(i+1,menor);
    }
    fclose(archi);

    return menor;
}
