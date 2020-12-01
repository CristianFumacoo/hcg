#include <stdio.h>
#include <stdlib.h>

int menu()
{
    int opc;

    printf("Bienvenido a LA VOZ, ¡segunda temporada!\n");
    printf("1.Cargar archivo CSV.\n");
    printf("2.Mostrar archivo CSV.\n");
    printf("3.Calcular promedio.\n");
    printf("4.Guardar en archivo\n");
    printf("5.Cantidad de personas con mas del deseado.\n");
    printf("6.Mostrar con segunda nota y promedio.\n");
    printf("Opcion: ");
    scanf("%d",&opc);

    return opc;
}

int menuArchivo()
{
    int opc;

    printf("Bienvenido.\n");
    printf("¿Que archivo quiere leer?\n");
    printf("1.Buenos Aires.\n");
    printf("2.Misiones.\n");
    printf("3.Neuquen.\n");
    printf("Opcion: ");
    scanf("%d",&opc);

    return opc;
}
