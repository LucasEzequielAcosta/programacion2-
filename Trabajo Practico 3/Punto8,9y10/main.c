#include <stdio.h>
#include <stdlib.h>

const char archivo[] = {"archivo.dat"};

int main()
{
    cargarDatos();
    mostrarDatos();

    abreYmuestraMenor(archivo);

    iniciaMostrarInvertido(archivo);
    iniciaInvierteArchivo(archivo);

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
    fclose(archi);
}

int menorEnArchivo (FILE * arch)
{

    int menor;
    int aux;

    if(fread(&aux,sizeof(int),1,arch)==0) /// cuando llego al final del archivo
    {
        /// me muevo uno para atras
        fseek(arch, -1*sizeof(int), SEEK_END);
        /// lo leo
        fread(&menor, sizeof(int),1,arch); /// leo el ultimo elemento para retornarlo
    }
    else
    {
        menor = menorEnArchivo(arch);

        if(aux<menor)
        {
            menor=aux;
        }
    }
    return menor;
}

/// subprograma que inicia la conexión con el archivo y busca el menor
void abreYmuestraMenor (char nombre[])
{
    FILE *arch=NULL;

    arch=fopen(nombre, "rb");

    if(arch!=NULL)
    {
        int menor= menorEnArchivo(arch);

        printf("\n\nEl menor en el archivo es %d", menor);

        fclose(arch);
    }
    else
    {
        printf("Paso algo muy malo...");
    }
}

int leer(FILE * arch)
{
    int aux;
    fread(&aux, sizeof(int),1,arch);
    return aux;
}

void escribir(FILE *arch, int valor)
{
    fwrite(&valor, sizeof(int), 1, arch);
}

int cuentaRegistroArchivo(FILE * arch)
{
    int cant=0;

    fseek(arch, 0, SEEK_END);
    cant=ftell(arch)/sizeof(int);

    return cant;
}

void invierteArchivo(FILE *arch, int i, int u)
{
    /// la condicion de corte con su solucion final no queda explicita
    /// pero la idea es: contar la cantidad de registros en el archivo
    /// e ir leyendo, intercambiando y escribiendo desde el ppio hacia el final y
    /// viceversa
    int ppio;
    int fin;
    if(i<u)
    {
        /// posiciono el cursor en el extremo inferior del archivo
        fseek(arch,i*sizeof(int),SEEK_SET);
        /// leemos el primer dato
        ppio=leer(arch);

        /// ahora en el extremo superior del archivo
        fseek(arch, u*sizeof(int),SEEK_SET);
        /// ahora el segundo
        fin=leer(arch);

        /// y ahora hacemos el intercambio

        /// posiciono el cursor en el extremo inferior del archivo
        fseek(arch,i*sizeof(int),SEEK_SET);
        /// escribo el dato del final en el ppio
        escribir(arch, fin);

        /// ahora en el extremo superior del archivo
        fseek(arch, u*sizeof(int),SEEK_SET);
        /// y el del ppio en el final
        escribir(arch, ppio);

        /// ahora hacemos la llamada recursiva
        /// con la aproximacion a la condicion de corte
        invierteArchivo(arch, i+1, u-1);
    }
}

/// otra version
void invertir_archivo(FILE* archi)
{
    int dato;


    if(fread(&dato,sizeof(int),1,archi)>0)
    {

        invertir_archivo(archi);

        fwrite(&dato,sizeof(int),1,archi);
    }
    else
    {
        fseek(archi,0,SEEK_SET);
    }
}

void iniciaInvierteArchivo(char nombre[])
{
    FILE *arch=NULL;

    arch=fopen(nombre, "r+b");

    if(arch!=NULL)
    {
        int cantidad=cuentaRegistroArchivo(arch);

        invierteArchivo(arch, 0, cantidad-1);

        fclose(arch);
    }
    else
    {
        printf("Paso algo muy malo...");
    }
}

void muestraArchivoInvertido (FILE * arch)
{
    int valor;
    // no queda explicita la condicion de corte con su solucion final...
    if(fread(&valor, sizeof(int),1,arch)>0)
    {
        muestraArchivoInvertido(arch);
        // y muestro el elemento cuando vuelve de la recursion..
        printf(" %d", valor);
    }
}

void iniciaMostrarInvertido(char nombre[])
{
    FILE *arch=NULL;

    arch=fopen(nombre, "rb");

    if(arch!=NULL)
    {
        printf("\n\nContenido del archivo invertido: ");
        muestraArchivoInvertido(arch);
        fclose(arch);
    }
    else
    {
        printf("Paso algo muy malo...");
    }
}
