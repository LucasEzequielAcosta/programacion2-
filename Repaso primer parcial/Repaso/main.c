#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
   char patente[6];
   int valor;
   char marca[10];
} automovil;

typedef struct nodoAuto
{
   automovil dato;
   struct nodoAuto * siguiente;
} nodoAuto;

nodoAuto * inicLista();
nodoAuto * crearNodo(automovil dato);
nodoAuto * buscarUltimo(nodoAuto * lista);
void agregarAlFinal(nodoAuto ** lista, nodoAuto * nuevo);
int insertarCelda(automovil A[], automovil dato, int v);
void agregarMuchos(nodoAuto ** lista);

int main()
{
    nodoAuto * lista = inicLista();
    agregarMuchos(&lista);

    int dim = 10;
    automovil A[dim];
    int validos = pasar(lista, A, dim);
    mostrarArregloRecursivo(A, 0, validos);

    int suma = sumarValores(lista);
    printf("\nSuma: %i", suma);

    return 0;
}

nodoAuto * inicLista()
{
    return NULL;
}

nodoAuto * crearNodo(automovil dato)
{
    nodoAuto * aux = (nodoAuto*)malloc(sizeof(nodoAuto));
    aux->dato = dato;
    aux->siguiente = NULL;

    return aux;
}

nodoAuto * buscarUltimo(nodoAuto * lista)
{
    nodoAuto * seg = lista;
    if(seg)
    {
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    }
    return seg;
}

void agregarAlFinal(nodoAuto ** lista, nodoAuto * nuevo)
{
    if((*lista) == NULL)
    {
        (*lista) = nuevo;
    }
    else
    {
        nodoAuto * ultimo = buscarUltimo((*lista));
        ultimo->siguiente = nuevo;
    }
}

int insertarCelda(automovil A[], automovil dato, int v)
{
    int i = v-1;
    while(i>=0 && A[i].valor > dato.valor)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = dato;

    return v+1;
}

void agregarMuchos(nodoAuto ** lista)
{
    char control = 's';
    automovil a;
    nodoAuto * aux = NULL;

    while(control == 's')
    {
        printf("\n Ingrese patente: ");
        fflush(stdin);
        gets(a.patente);

        printf("\n Ingrese valor: $ ");
        scanf("%d",&a.valor);

        printf("\n Ingrese marca: ");
        fflush(stdin);
        gets(a.marca);

        aux = crearNodo(a);
        agregarAlFinal(lista, aux);

        printf("\ndesea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);
    }
}

int pasar(nodoAuto * lista, automovil A[], int dim)
{
    int v = 0;
    nodoAuto * seg = lista;

    if(seg)
    {
        while(seg != NULL && v < dim)
        {
            v = insertarCelda(A, seg->dato, v);
            seg = seg->siguiente;
        }
    }
    return v;
}

void mostrarAuto(automovil A)
{
    printf("\nMarca: %s", A.marca);
    printf("\nPatente: %s", A.patente);
    printf("\nValor: $%i", A.valor);
    printf("\n------------------");
}

void mostrarArregloRecursivo(automovil A[], int i, int cant)
{
    if(i < cant)
    {
        mostrarAuto(A[i]);
        mostrarArregloRecursivo(A, i+1, cant);
    }
}

int ultimoValorPatente(char patente[])
{
    int i = strlen(patente);
    int num = (int)patente[i-1]-48;

    return num;
}

int sumarValores(nodoAuto * lista)
{
    int rta = 0;
    if(lista)
    {
        if(ultimoValorPatente(lista->dato.patente) %2 == 0)
        {
            rta = lista->dato.valor + sumarValores(lista->siguiente);
        }
        else
        {
            rta = sumarValores(lista->siguiente);
        }
    }
    return rta;
}




