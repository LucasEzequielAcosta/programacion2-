#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

typedef struct {
     char nombre[20];
     int edad;
} persona;

typedef struct nodoDoble
{
    persona dato;
    struct nodoDoble * siguiente;
    struct nodoDoble * anterior;
}nodoDoble;


nodoDoble * inicLista();
nodoDoble * crearNodo(persona dato);
nodoDoble * agregarAlPrincipio(nodoDoble * lista, nodoDoble * nuevoNodo);
nodoDoble * buscarUltimoRec(nodoDoble * lista);
nodoDoble * buscarUltimo(nodoDoble * lista);
nodoDoble * agregarAlFinal(nodoDoble * lista, nodoDoble * nuevoNodo);
nodoDoble * agregarEnOrden(nodoDoble * lista, nodoDoble * nuevoNodo);
persona cargarPersona();
nodoDoble * cargarLista(nodoDoble * lista);
void mostrarPersona(persona dato);
void mostrarNodo(nodoDoble * aux);
void recorrerYmostrarLista(nodoDoble * lista);

#endif // LISTADOBLE_H_INCLUDED
