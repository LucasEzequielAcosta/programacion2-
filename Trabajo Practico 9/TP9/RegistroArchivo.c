#include "RegistroArchivo.h"

void cargarArchivo(char archivo[])
{
    char control = 's';
    registroArchivo reg;

    FILE * archi = fopen(archivo, "ab");


    while(control == 's')
    {
        printf("\nIngrese animal: ");
        fflush(stdin);
        scanf("%s", &reg.animal);

        printf("\nIngrese especie: ");
        fflush(stdin);
        scanf("%s", &reg.especie);

        printf("\nIngrese cantidad: ");
        fflush(stdin);
        scanf("%i", &reg.cant);

        printf("\nIngrese idEspecie: ");
        fflush(stdin);
        scanf("%i", &reg.idEspecie);

        printf("\nIngrese Habitat: ");
        fflush(stdin);
        scanf("%i", &reg.habitat);

        fwrite(&reg, sizeof(registroArchivo), 1, archi);

        printf("\nDesea continuar? s/n");
        fflush(stdin);
        scanf("%c", &control);
    }
    fclose(archi);
}







