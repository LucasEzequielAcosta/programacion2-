#include "Animal.h"

void mostrarAnimal(animal A)
{
    printf("\nNombre: %s", A.nombreAnimal);
    printf("\nHabitat: %i", A.habitat);
    printf("\nCantidad: %i", A.cantidad);
    puts("\n---------------------------");
}
