#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "concur.h"
#include "Controller.h"

/*
    COMIENZO DE LOS SETTERS
*/

int concur_setNumero(eConcur* concur, int numero)
{
    int retorno = 0;

    if(concur != NULL)
    {
        concur->numeroConcursante = numero;
        retorno = 1;
    }

    return retorno;
}

int concur_setAnioNaci(eConcur* concur, int anio)
{
    int retorno = 0;

    if(concur != NULL)
    {
        concur->anioNacimiento = anio;
        retorno = 1;
    }

    return retorno;
}

int concur_setDni(eConcur* concur,char* dni)
{
    int retorno = 0;

    if(concur != NULL)
    {
        strcpy(concur->dni,dni);
        retorno = 1;
    }

    return retorno;
}

int concur_setNombre(eConcur* concur,char* nombre)
{
    int retorno = 0;

    if(concur != NULL)
    {
        strcpy(concur->nombre,nombre);
        retorno = 1;
    }

    return retorno;
}

int concur_setTemaPresen(eConcur* concur,char* tema)
{
    int retorno = 0;

    if(concur != NULL)
    {
        strcpy(concur->temaPresentacion,tema);
        retorno = 1;
    }

    return retorno;
}

int concur_setPuntajePrimeraRonda(eConcur* concur,int puntaje)
{
    int retorno = 0;

    if(concur != NULL)
    {
        concur->puntajePrimeraRonda = puntaje;
        retorno = 1;
    }

    return retorno;
}

int concur_setFecha(eConcur* concur,char* fecha)
{
    int retorno = 0;

    if(concur != NULL)
    {
        strcpy(concur->fecha,fecha);
        retorno = 1;
    }

    return retorno;
}

int concur_setPuntajeSegundaRonda(eConcur* concur,int puntajeSeg)
{
    int retorno = 0;

    if(concur != NULL)
    {
        concur->puntajeSegundaRonda = puntajeSeg;
        retorno = 1;
    }

    return retorno;
}

int concur_setPromedio(eConcur* concur,float promedio)
{
    int retorno = 0;

    if(concur != NULL)
    {
        concur->promedioPuntaje = promedio;
        retorno = 1;
    }

    return retorno;
}

/*
        FIN DE LOS SETTERS
*/

/*
    COMIENZO DE LOS GETTERS
*/

int concur_getNumero(eConcur* concur, int* numero)
{
    int retorno = 0;

    if(concur != NULL)
    {
        *numero = concur->numeroConcursante;
        retorno = 1;
    }

    return retorno;
}

int concur_getAnioNaci(eConcur* concur, int* anio)
{
    int retorno = 0;

    if(concur != NULL)
    {
        *anio = concur->anioNacimiento;
        retorno = 1;
    }

    return retorno;
}

int concur_getDni(eConcur* concur,int* dni)
{
    int retorno = 0;

    if(concur != NULL)
    {
        strcpy(dni,concur->dni);
        retorno = 1;
    }

    return retorno;
}

int concur_getNombre(eConcur* concur,char* nombre)
{
    int retorno = 0;

    if(concur != NULL)
    {
        strcpy(nombre,concur->nombre);
        retorno = 1;
    }

    return retorno;
}

int concur_getTemaPresen(eConcur* concur,char* tema)
{
    int retorno = 0;

    if(concur != NULL)
    {
        strcpy(tema,concur->temaPresentacion);
        retorno = 1;
    }

    return retorno;
}

int concur_getPuntajePrimeraRonda(eConcur* concur,int* puntaje)
{
    int retorno = 0;

    if(concur != NULL)
    {
        *puntaje = concur->puntajePrimeraRonda;
        retorno = 1;
    }

    return retorno;
}

int concur_getFecha(eConcur* concur, char* fecha)
{
    int retorno = 0;

    if(concur != NULL)
    {
        strcpy(fecha,concur->fecha);
        retorno = 1;
    }

    return retorno;
}

int concur_getPuntajeSegundaRonda(eConcur* concur,int* puntajeSeg)
{
    int retorno = 0;

    if(concur != NULL)
    {
        *puntajeSeg = concur->puntajeSegundaRonda;
        retorno = 1;
    }

    return retorno;
}

int concur_getPromedio(eConcur* concur,float* promedio)
{
    int retorno = 0;

    if(concur != NULL)
    {
        *promedio = concur->promedioPuntaje;
        retorno = 1;
    }

    return retorno;
}



/*
    FIN DE LOS GETTERS
*/

/*
    COMIENZO DE CONSTRUCTORES
*/

eConcur* concur_new()
{
    eConcur* concur;

    concur = malloc(sizeof(eConcur));

    return concur;
}

eConcur* concur_conParemetros(char* numero,char* anioNaci,char* nombre, char* dni,char* fecha,char* tema,char* puntaje,int* puntajeDos,float* promedio)
{
    eConcur* concur = concur_new();

    if(concur_setNumero(concur,atoi(numero))&&
       concur_setNombre(concur,nombre)&&
       concur_setAnioNaci(concur,atoi(anioNaci)) &&
       concur_setFecha(concur,fecha) &&
       concur_setDni(concur,dni) &&
       concur_setPuntajePrimeraRonda(concur,atoi(puntaje)) &&
       concur_setTemaPresen(concur,tema) &&
       concur_setPuntajeSegundaRonda(concur,puntajeDos) &&
       concur_setPromedio(concur,atoi(promedio)))
    {
         return concur;
    }

    return NULL;
}


int archivoLeer(eConcur* concur)
{
    int retorno = 0;
    int opc = menuArchivo();
    char nombreArchivo[51];

    switch(opc)
    {
        case 1:
            strcpy(nombreArchivo,"buenosaires.csv");
            retorno = 1;
            break;
        case 2:
            strcpy(nombreArchivo,"misiones.csv");
            retorno = 1;
            break;
        case 3:
            strcpy(nombreArchivo,"neuquen.csv");
            retorno = 1;
            break;
        default:
            printf("\nOpcion incorrecta.\n");
            archivoLeer(concur);
            break;
    }
    controller_loadFromText(nombreArchivo,concur);

    return retorno;
}

void mostrar(eConcur* concur)
{
    int numero;
    int anio;
    char nombre[51];
    char dni[9];
    char fecha[15];
    char tema[51];
    int puntaje;

    concur_getNumero(concur,numero);
    concur_getAnioNaci(concur,anio);
    concur_getNombre(concur,nombre);
    concur_getDni(concur,dni);
    concur_getFecha(concur,fecha);
    concur_getTemaPresen(concur,tema);
    concur_getPuntajePrimeraRonda(concur,puntaje);

    printf("%d - %d - %s - %s - %s - % s - %d",numero,anio,nombre,dni,fecha,tema,puntaje);

}





















