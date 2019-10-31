#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct nodoArbol
{
    int dato;
    struct nodoArbol * izq;
    struct nodoArbol * der;
}nodoArbol;

nodoArbol * inicArbol();
nodoArbol * crearNodo(int dato);
nodoArbol * insertar(nodoArbol * arbol, int dato);
nodoArbol * buscar(nodoArbol * arbol, int dato);
void preorder(nodoArbol * arbol);
void inorder(nodoArbol * arbol);
void posorder(nodoArbol * arbol);

#endif // ARBOL_H_INCLUDED
