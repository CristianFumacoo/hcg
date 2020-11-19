int menu()
{
    int opc;

    printf("¡Bienvenido a mi veterinaria!\n");
    printf("1.Ingresar mascota.\n");
    printf("2.Ingresar raza.\n");
    printf("3.Mostrar mascotas.\n");
    printf("4.Mostrar razas.\n");
    printf("5.Mostrar mascotas con sus razas.\n");
    printf("6.Borrar mascota.\n");
    printf("7.Borrar raza.\n");
    printf("8.Modificar mascota.\n");
    printf("9.Ordenar por pais de origen.\n");
    printf("10.Mostrar Tamanio a elegir\n");
    printf("11.Listar por raza\n");
    printf("12.Pais con mas mascotas.\n");
    printf("13.Ordenar por codigo telefonico.\n");
    printf("14.Mostrar pesos, promedios y cantidad.\n");
    printf("15.Ordenar por Tipo y peso.\n");
    printf("99.Salir.\n");
    printf("Opcion: ");
    scanf("%d",&opc);

    return opc;
}

int modifyMascota()
{
    int opc;
    printf("¿Que desea modificar?\n");
    printf("1.Nombre.\n");
    printf("2.Sexo.\n");
    printf("3.Edad.\n");
    printf("4.Tipo.\n");
    printf("5.Raza.\n");
    scanf("%d",&opc);

    return opc;
}
