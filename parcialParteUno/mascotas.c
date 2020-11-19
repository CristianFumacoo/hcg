#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"

void todoVacio(eMascota mascotas[], eRaza razas[], eTipo tipos[],int cantMas, int cantRaz,int cantTip)
{
    for(int i=0; i<cantMas; i++)
    {
        mascotas[i].idRaza = 0;
        mascotas[i].edad = 0;
        mascotas[i].isEmpty = 0;
        mascotas[i].id = 0;

        strcpy(mascotas[i].nombre," ");
        strcpy(mascotas[i].sexo," ");
        strcpy(mascotas[i].tipo," ");
    }

    for(int i=0; i<cantRaz; i++)
    {
        razas[i].id = 0;
        razas[i].isEmpty = 0;

        strcpy(razas[i].descripcion," ");
        strcpy(razas[i].tamanio," ");
        strcpy(razas[i].paisOrigen," ");
    }

    for(int i=0; i<cantTip; i++)
    {
        tipos[i].id = 0;
        tipos[i].cantXTipo = 0;
        tipos[i].totalPeso = 0;
        tipos[i].peso = 0;

        strcpy(tipos[i].tipo," ");
    }
}

void hardcodeMascotas(eMascota mascotas[])
{
    int idRaza[7] = {1,2,4,3,1,1,6};
    int idTipo[7] = {2,2,3,3,1,1,2};
    int edad[7] = {5,8,10,2,4,8,4};
    int suId[7] = {1,2,3,4,5,6,7};
    char nombre[7][51] = {"Juan","Gwen","Tomi","Uma","Agus","Pastor","Chucho"};
    char sexo[7][2] = {"m","f","m","f","m","m","m"};
    char tipo[7][51] = {"Perro","Perro","Raro","Raro","Gato","Gato","Perro"};
    float peso[7] = {5,8,4,2,9,12,6};

    for(int i=0; i<7; i++)
    {
        mascotas[i].idRaza = idRaza[i];
        mascotas[i].edad = edad[i];
        mascotas[i].isEmpty = 1;
        mascotas[i].id = suId[i];
        mascotas[i].peso = peso[i];
        mascotas[i].idTipo = idTipo[i];

        strcpy(mascotas[i].nombre,nombre[i]);
        strcpy(mascotas[i].sexo,sexo[i]);
        strcpy(mascotas[i].tipo,tipo[i]);
    }
}

void hardcodeRazas(eRaza razas[])
{
    int id[6] = {1,2,3,4,5,6};
    char descripcion[6][51] = {"Siames","Doberman","Persa","Pastor Belga","Pastor Aleman","Dogo Argentino"};
    char tamanio[6][51] = {"Chico","Grande","Mediano","Grande","Grande","Mediano"};
    char pais[6][51] = {"Tailandia","Alemania","Persia","Belgica","Alemania","Argentina"};
    int idPais[6] = {4,2,5,3,2,1};

    for(int i=0; i<6; i++)
    {
        razas[i].id = id[i];
        razas[i].isEmpty = 1;
        razas[i].idPais = idPais[i];


        strcpy(razas[i].descripcion,descripcion[i]);
        strcpy(razas[i].tamanio,tamanio[i]);
        strcpy(razas[i].paisOrigen,pais[i]);
    }
}

void hardcodeTipo(eTipo tipo[])
{
    int id[3] = {1,2,3};
    char tipos[3][51] = {"Gato","Perro","Raro"};

    for(int i=0; i<3; i++)
    {
        tipo[i].id = id[i];
        strcpy(tipo[i].tipo,tipos[i]);
    }
}

void harcodePais(ePais pais[])
{
    int id[5] = {1,2,3,4,5};
    char paisA[5][51] = {"Argentina","Alemania","Belgica","Tailandia","Persia",};
    int codigoTelefonico[5] = {54,49,32,66,98};
    char continente[5][51] = {"America del Sur","Europa","Europa","Asia","Africa"};

    for(int i=0; i<5; i++)
    {
        pais[i].codigoTelefonico = codigoTelefonico[i];
        pais[i].isEmpty = 1;
        pais[i].id = id[i];
        pais[i].cont = 0;

        strcpy(pais[i].nombreDePais,paisA[i]);
        strcpy(pais[i].continente,continente[i]);
    }
}

void harcodeTam(eTam tam[])
{
    int id[3] = {1,2,3};
    char tamanio[3][51] = {"Chico","Mediano","Grande"};

    for(int i=0; i<3; i++)
    {
        tam[i].id = id[i];
        tam[i].isEmpty = 1;

        strcpy(tam[i].tamanio,tamanio[i]);
    }
}

void ingresarMascota(eMascota mascota[], eRaza raza[],eTipo tipos[], int cantMas,int cantRaz,int cantTip, int id)
{
    int idTipo;

    for(int i=0; i<cantMas; i++)
    {
        if(mascota[i].isEmpty != 1)
        {
            printf("Ingrese el nombre de su mascota: ");
            fflush(stdin);
            scanf("%[^\n]",&mascota[i].nombre);

            printf("Ingrese sexo de su mascota (f o m): ");
            fflush(stdin);
            scanf("%c",&mascota[i].sexo);

            printf("Ingrese la edad de su mascota: ");
            scanf("%d",&mascota[i].edad);

            printf("Ingrese el peso de su mascota :");
            scanf("%f",&mascota[i].peso);

            idTipo = elegirTipo(tipos,cantTip);

            strcpy(mascota[i].tipo,tipos[idTipo-1].tipo);

            mascota[i].idRaza = elegirRaza(raza,cantRaz);

            mascota[i].isEmpty = 1;
            mascota[i].id = id;

            break;
        }
    }
}

void ingresarRaza(eRaza razas[],ePais paises[],eTam tam[], int cantRaz,int id, int cantPai,int cantTam)
{

    int auxPais;
    int auxTam;

    for(int i=0; i<cantRaz; i++)
    {
        if(razas[i].isEmpty == 0)
        {
            auxPais = elegirPais(paises,cantPai);
            strcpy(razas[i].paisOrigen,paises[auxPais-1].nombreDePais);

            printf("Ingrese el nombre de la raza: ");
            fflush(stdin);
            scanf("%s",&razas[i].descripcion);


            auxTam = elegirTam(tam,cantTam);
            strcpy(razas[i].tamanio,tam[auxTam-1].tamanio);

            razas[i].id = id;
            razas[i].isEmpty = 1;

            break;
        }
    }
}

int elegirRaza(eRaza raza[],int cant)
{
    int opc;
    printf("\nEstas son las razas disponibles:\n");
    mostrarRazas(raza,cant);
    printf("\nIngrese el id de la raza de su mascota: ");
    scanf("%d",&opc);

    return opc;
}

int elegirTipo(eTipo tipo[],int cant)
{
    int opc;
    printf("De que tipo es su mascota: \n");
    printf("1.Gato.\n");
    printf("2.Perro.\n");
    printf("3.Raro.\n");

    scanf("%d",&opc);

    return opc;
}

int elegirPais(ePais paises[],int cant)
{
    int opc;
    printf("Los paises disponibles son:\n");
    mostrarPaises(paises,cant);

    printf("Elija el ID del pais de su raza: ");
    scanf("%d",&opc);

    return opc;
}

int elegirTam(eTam tam[],int cant)
{
    int opc;
    printf("Los tamanios son: \n");
    printf("1.Chico\n");
    printf("2.Mediano\n");
    printf("3.Grande\n");

    printf("Elija el id del tamanio: ");
    scanf("%d",&opc);

    return opc;
}

void mostrarMascotas(eMascota* mascotas,int cant)
{
    printf("%s%10s%10s%10s%10s%15s\n","ID","NOMBRE","SEXO","PESO","EDAD","TIPO");
    for(int i=0; i<cant; i++)
    {
        if(mascotas[i].isEmpty == 1)
        {
            printf("%d%10s%10s%10.1f%10d%15s\n",(mascotas+i)->id,(mascotas+i)->nombre,(mascotas+i)->sexo,(mascotas+i)->peso,(mascotas+i)->edad,(mascotas+i)->tipo);
        }
    }
}

void mostrarRazas(eRaza* razas,int cant)
{
    printf("%s%15s%15s%20s\n","ID","RAZA","TAMANIO","PAIS DE ORIGEN");

    for(int i=0; i<cant; i++)
    {
        if(razas[i].isEmpty == 1)
        {
            printf("%d%15s%15s%20s\n",(razas+i)->id,(razas+i)->descripcion,(razas+i)->tamanio,(razas+i)->paisOrigen);
        }
    }
}

eRaza buscarRaza(eRaza raza[],int cant,int idRaza)
{
    eRaza aux;

    for(int i=0; i<cant; i++)
    {
        if(idRaza==raza[i].id)
        {
            aux = raza[i];
            break;
        }
    }
    return aux;
}

ePais buscarPais(ePais pais[],int cant,int idPais)
{
    ePais aux;

    for(int i=0; i<cant; i++)
    {
        if(idPais == pais[i].id)
        {
            aux = pais[i];
            break;
        }
    }
    return aux;
}

eTipo buscarTipo(eTipo tipo[],int cant,int idTipo)
{
    eTipo aux;

    for(int i=0; i<cant; i++)
    {
        if(idTipo == tipo[i].id)
        {
            aux = tipo[i];
            break;
        }
    }
    return aux;
}


void mostrarUnaMascota(eMascota mascota, eRaza raza,ePais pais,eTipo tipo)
{
    printf("%5d%10s%10s%10s%10d%20s%15s%25f%20s%15d\n",mascota.id,tipo.tipo,mascota.nombre,mascota.sexo,mascota.edad,raza.descripcion,raza.tamanio,mascota.peso,raza.paisOrigen,pais.codigoTelefonico);
}

void mostrarMascotaConRaza(eMascota mascotas[], eRaza razas[],ePais pais[],eTipo tipo[],int cant,int cantRaz,int cantPai,int cantTip)
{
    int index;
    int indexPai;
    eRaza raz;
    ePais pai;
    eTipo tip;

    printf("%5s%10s%10s%10s%10s%20s%15s%20s%25s%25s\n","ID","TIPO","NOMBRE","SEXO","EDAD","RAZA","TAMANIO","PESO","PAIS DE ORIGEN","CODIGO DEL PAIS");
    for(int i=0; i<cant; i++)
    {
        raz = buscarRaza(razas,cantRaz,mascotas[i].idRaza);
        pai = buscarPais(pais,cantPai,raz.idPais);
        tip = buscarTipo(tipo,cantTip,mascotas[i].idTipo);

        if(mascotas[i].isEmpty == 1)
        {
            mostrarUnaMascota(mascotas[i],raz,pai,tip);
        }
    }
}

void mostrarPaises(ePais pais[],int cant)
{
    printf("%5s%15s%30s%30s\n","ID","PAIS","NUMERO TELEFONICO","CONTINENTE");

    for(int i=0; i<cant; i++)
    {
        if(pais[i].isEmpty == 1)
        {
            printf("%5d%15s%25d%35s\n",pais[i].id,pais[i].nombreDePais,pais[i].codigoTelefonico,pais[i].continente);
        }
    }
}


void borrarMascota(eMascota mascota[],int cant)
{
    int opc;
    char resp;
    mostrarMascotas(mascota,cant);
    printf("Ingrese el id de la mascota que quiere borrar: ");
    scanf("%d",&opc);

    printf("¿Esta seguro? s o n: ");
    fflush(stdin);
    scanf("%c",&resp);

    if(resp == 's')
    {
        for(int i=0; i<cant; i++)
        {
            if(opc == mascota[i].id)
            {
                mascota[i].isEmpty = 0;
                break;
            }
        }
    }
    else
    {
        system("cls");
        borrarMascota(mascota,cant);
    }
}

void borrarRaza(eMascota mascota[],eRaza raza[],int cantMas,int cantRaz)
{

    int opc;
    char resp;
    mostrarRazas(raza,cantRaz);
    printf("Ingrese el id de la raza que quiere borrar: ");
    scanf("%d",&opc);

    printf("¿Esta seguro? s o n: ");
    fflush(stdin);
    scanf("%c",&resp);

    if(resp == 's')
    {
        for(int i=0; i<cantRaz; i++)
        {
            if(opc == raza[i].id)
            {
                raza[i].isEmpty = 0;
                break;
            }
        }
        for(int i = 0;i < cantMas;i++)
        {
            if(mascota[i].idRaza == opc)
            {
                mascota[i].isEmpty = 0;
            }
        }
    }
}

void mostrarPorPais(eMascota* mascota, int cantMas, eRaza raza[], int cantRaz,ePais paises[],int cantPai)
{
    int flag = 0;
    eMascota aux;
    eRaza auxRazaI;
    eRaza auxRazaJ;

    for(int i=0; i<cantMas-1; i++)
    {
        if(mascota[i].isEmpty == 1)
        {
            auxRazaI = buscarRaza(raza,cantRaz, mascota[i].idRaza);

            for(int j=i+1; j<cantMas; j++)
            {
                if(mascota[j].isEmpty == 1)
                {
                    auxRazaJ = buscarRaza(raza,cantRaz, mascota[j].idRaza);

                    if(strcmp(auxRazaI.paisOrigen, auxRazaJ.paisOrigen)>0)
                    {
                        aux = mascota[i];
                        mascota[i] = mascota[j];
                        mascota[j] = aux;
                        flag = 1;
                    }
                }
            }
        }
    }

    if(flag == 1)
    {
        mostrarPorPais(mascota,cantMas,raza,cantRaz,paises,cantPai);
        return;
    }
        //mostrarMascotaConRaza(mascota,raza,paises,,cantMas,cantRaz,cantPai);
}

void modificarMascota(eMascota mascota[],eRaza raza[],eTipo tipo[],ePais paises[],int cantMas,int cantRaz,int cantTip,int cantPai)
{
    int opc;
    int menu;
    int auxTipo;
    char seguro;
    int idAModificar;
    mostrarMascotaConRaza(mascota,raza,paises,tipo,cantMas,cantRaz,cantPai,cantTip);

    printf("\nIngrese el id de la mascota que quiere modificar: ");
    scanf("%d",&opc);

    printf("¿Seguro quiere modificar la mascota con ID :%d ? s/n:",opc);
    fflush(stdin);
    scanf("%c",&seguro);

    if(seguro == 's')
    {
        for(int i=0; i<cantMas; i++)
        {
            if(mascota[i].id == opc)
            {
                idAModificar = i;
            }
        }
    }
    else
        return;

    menu = modifyMascota();

    switch(menu)
    {
    case 1:
        printf("Ingrese el nombre de su mascota: ");
        fflush(stdin);
        scanf("%s",&mascota[idAModificar].nombre);
        break;
    case 2:
        printf("Ingrese sexo de su mascota (f o m): ");
        fflush(stdin);
        scanf("%c",&mascota[idAModificar].sexo);
        break;
    case 3:
        printf("Ingrese la edad de su mascota: ");
        scanf("%d",&mascota[idAModificar].edad);
        break;
    case 4:
        auxTipo = elegirTipo(tipo,cantTip);
        strcpy(mascota[idAModificar].tipo,tipo[auxTipo-1].tipo);
        break;
    case 5:
        mascota[idAModificar].idRaza = elegirRaza(raza,cantRaz);
        break;
    }
}

void mostrarPorCodigo(eMascota* mascota,eRaza raza[],ePais pais[],int cantMas,int cantRaz,int cantPai)
{
    eMascota otraMascota;
    eRaza auxRazaI;
    eRaza auxRazaJ;

    ePais auxPaisI;
    ePais auxPaisJ;

    for(int i=0; i<cantMas-1; i++)
    {
        if(mascota[i].isEmpty == 1)
        {
            auxRazaI = buscarRaza(raza,cantRaz, mascota[i].idRaza);

            auxPaisI = buscarPais(pais,cantPai,auxRazaI.idPais);

            for(int j=i; j<cantMas; j++)
            {
                if(mascota[j].isEmpty == 1)
                {
                    auxRazaJ = buscarRaza(raza,cantRaz, mascota[j].idRaza);

                    auxPaisJ = buscarPais(pais,cantPai,auxRazaJ.idPais);

                    if(auxPaisJ.codigoTelefonico < auxPaisI.codigoTelefonico)
                    {
                        otraMascota = mascota[i];
                        mascota[i] = mascota[j];
                        mascota[j] = otraMascota;
                    }
                }
            }
        }
    }
}

void mostrarPorTam(eMascota mascota[],eRaza raza[],ePais pais[],eTam tam[],int cantMas,int cantRaz,int cantPai)
{
    int opc;

    printf("Tamanios existentes.\n");
    printf("1.Chico\n");
    printf("2.Mediano\n");
    printf("3.Grande\n");
    printf("Elija el ID del tamanio que quiere ver: ");
    scanf("%d",&opc);

    if(opc < 0 || opc > 3)
    {
        printf("Tamanio no existe, nv\n");
        return;
    }

    mostrarSEP(mascota,raza,tam,cantMas,cantRaz,opc);
}

void mostrarSEP(eMascota mascota[],eRaza raza[],eTam tam[],int cantMas,int cantRaz,int opc)
{
    int index;
    eRaza auxRaz;

    printf("%5s%15s%15s%15s\n","NOMBRE","SEXO","EDAD","PESO");

    for(int i=0; i<cantMas; i++)
    {
        if(mascota[i].isEmpty == 1)
        {
            auxRaz = buscarRaza(raza,cantRaz, mascota[i].idRaza);

            if(strcmp(auxRaz.tamanio,tam[opc-1].tamanio)==0)
            {
                printf("%5s%15s%15d%20f\n",mascota[i].nombre,mascota[i].sexo,mascota[i].edad,mascota[i].peso);
            }
        }
    }
}



void mostrarPorRaz(eMascota mascota[],eRaza raza[],ePais pais[],eTam tam[],int cantMas,int cantRaz,int cantPai)
{
    for(int i =0;i<cantRaz;i++)
    {
        if(raza[i].isEmpty == 1)
        {
            printf("RAZA: %s\n",raza[i].descripcion);

            for(int j = 0;j < cantMas;j++)
            {
                if(mascota[j].isEmpty == 1)
                {
                    if(raza[i].id == mascota[j].idRaza)
                    {
                        printf("Nombre: %s\n",mascota[j].nombre);
                    }
                }
            }
        }
    }
}

void contMascotasPorRaza(eMascota mascota[],eRaza raza[],ePais pais[],int cantMas,int cantRaz,int cantPai)
{
    eRaza auxRaza;
    int indexRaza;
    int indexPai;
    int max;

    for(int i = 0; i < cantMas; i++)
    {
        if(mascota[i].isEmpty == 1)
        {
            auxRaza = buscarRaza(raza,cantRaz,mascota[i].idRaza);

            for(int j = 0; j  < cantPai; j++)
            {
                if(pais[j].isEmpty == 1)
                {
                    if(auxRaza.idPais == pais[j].id)
                    {
                        pais[j].cont++;
                        break;
                    }
                }

            }
        }
    }

    for(int i = 0;i < cantPai; i++)
    {
        if(pais[i].isEmpty == 1)
        {
            if(i == 0)
            {
                indexPai = i;
                max = pais[indexPai].cont;
            }
            else
            {
                if(max < pais[i].cont)
                {
                    indexPai = i;
                    max = pais[indexPai].cont;
                }
            }
        }
    }

    printf("\nEl pais con mas mascotas es: %s\n",pais[indexPai].nombreDePais);
}

void mostrarTipoPeso(eMascota mascota[],eTipo tipo[], int cantMas, int cantTip)
{
    float prom = 0;

    for(int i = 0;i < cantMas;i++)
    {
        for(int j = 0; j < cantTip;j++)
        {
            if(mascota[i].idTipo == tipo[j].id)
            {
                tipo[j].totalPeso += mascota[i].peso;
                tipo[j].cantXTipo++;
                break;
            }
        }
    }

        printf("%25s%25s%25s\n","PESO","CANTIDAD","PROMEDIO");

    for(int i = 0;i < cantTip;i++)
    {
        prom = tipo[i].totalPeso / tipo[i].cantXTipo;

        printf("%s%25f%20d%25f\n",tipo[i].tipo,tipo[i].totalPeso,tipo[i].cantXTipo,prom);
    }
}

void mostrarPorTipoPeso(eMascota mascota[],eTipo tipo[],int cantMas,int cantTip)
{
    eMascota otraMascota;

    for(int i=0; i < cantMas-1; i++)
    {
        if(mascota[i].isEmpty == 1)
        {
            for(int j=i; j<cantMas; j++)
            {
                if(mascota[j].isEmpty == 1)
                {
                    if(mascota[i].idTipo == mascota[j].idTipo)
                    {
                        if(mascota[i].peso > mascota[j].peso)
                        {
                            otraMascota = mascota[i];
                            mascota[i] = mascota[j];
                            mascota[j] = otraMascota;
                        }
                    }
                    else if(mascota[i].idTipo > mascota[j].idTipo)
                    {
                        otraMascota = mascota[i];
                        mascota[i] = mascota[j];
                        mascota[j] = otraMascota;

                    }
                }
            }
        }
    }
}




