#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int valores[100];
    int posTope; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor
} Pila;


int main()
{
    Pila pilita;

    inicPila(&pilita);
    apilar(&pilita, 10);
    apilar(&pilita, 9);
    apilar(&pilita, 7);
    apilar(&pilita, 5);
    apilar(&pilita, 3);
    apilar(&pilita, 1);

    mostrar(&pilita);

     Pila pilota;

    inicPila(&pilota);
    apilar(&pilota, 11);
    apilar(&pilota, 8);
    apilar(&pilota, 6);
    apilar(&pilota, 4);
    apilar(&pilota, 3);
    apilar(&pilota, 2);

    mostrar(&pilota);

    Pila requetepilita;
    inicPila(&requetepilita);

    intercalarPilas(&pilita, &pilota, &requetepilita);

   mostrar(&pilita);
   mostrar(&pilota);
   mostrar(&requetepilita);

    return 0;
}

void apilar(Pila * p, int valor)
{
    if(p->posTope < 100)
    {
        p->valores[p->posTope] = valor;
        p->posTope++;
    }
    else
    {
        printf("\nLa pila esta llena...");
    }
}

int desapilar(Pila * p)
{
    int rta;
    if(p->posTope > 0)
    {
        rta=p->valores[p->posTope-1];
        p->posTope--;
    }

    return rta;
}

int tope(Pila * p)
{
    int rta=0;

    rta=p->valores[p->posTope-1];

    return rta;
}

int pilavacia(Pila * p)
{
    int rta=0;

    if(p->posTope==0)
    {
        rta=1;
    }

    return rta;
}

void mostrar(Pila * p)
{
    int i=0;

    printf("\nBase..............................................Tope\n");

    while(i<p->posTope)
    {
        printf("| %d ", p->valores[i]);
        i++;
    }

    printf("|\nBase..............................................Tope\n");
}

void inicPila(Pila *p)
{
    p->posTope=0;
}

void intercalarPilas(Pila *a, Pila * b, Pila * destino)
{
     while(!pilavacia(a)&&!pilavacia(b))
    {
        if (tope(a)<tope(b))
        {
            apilar(destino, desapilar(a));
        }
        else
        {
            apilar(destino, desapilar(b));
        }
    }

    // ahora evaluo si quedo algo en alguna de las dos pilas

    if(!pilavacia(a))
    {
        while(!pilavacia(a))
            apilar(destino, desapilar(a));
    }
    else
    {
        while(!pilavacia(b))
            apilar(destino, desapilar(b));
    }
}














