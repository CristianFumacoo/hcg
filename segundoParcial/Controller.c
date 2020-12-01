#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concur.h"
#include "LinkedList.h"
#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* concur)
{
    FILE* pArchivo;
    int retorno= 0;

    pArchivo = fopen(path,"r");

    if(pArchivo != NULL && concur != NULL)
    {
        retorno = parser_concurFromText(pArchivo,concur);
    }
    fclose(pArchivo);

    return retorno;
}

void mostrarLista(LinkedList* concur)
{
    eConcur* auxConcur;
    int numero;
    int anio;
    char nombre[51];
    char dni[9];
    char fecha[15];
    char tema[51];
    int puntaje;
    int puntajeDos;
    float promedio;

    if(concur != NULL)
    {
        printf("%5s%15s%15s%10s%20s%20s%25s%15s%10s\n","NUMERO","ANIO","NOMBRE","DNI","FECHA","TEMA","PUNTAJE","SEG PUNTAJE","PROMEDIO");

        for(int i = 0; i < ll_len(concur); i++)
        {
            auxConcur = ll_get(concur,i);

            concur_getNumero(auxConcur,&numero);
            concur_getAnioNaci(auxConcur,&anio);
            concur_getNombre(auxConcur,nombre);
            concur_getDni(auxConcur,dni);
            concur_getFecha(auxConcur,fecha);
            concur_getTemaPresen(auxConcur,tema);
            concur_getPuntajePrimeraRonda(auxConcur,&puntaje);
            concur_getPuntajeSegundaRonda(auxConcur,&puntajeDos);
            concur_getPromedio(auxConcur,&promedio);

            printf("%5d%15d%15s%15s%20s%25s%15d%10d%15.2f\n",numero,anio,nombre,dni,fecha,tema,puntaje,puntajeDos,promedio);
        }
    }
}

int controller_saveFromText(char* path, LinkedList* concur)
{
    int retorno = 0;
    eConcur* auxConcur;
    int numero;
    int anio;
    int puntajeUno;
    int puntajeDos;
    float promedio;

    char auxNumero[51];
    char auxAnioNaci[51];
    char auxNombre[51];
    char auxDni[51];
    char auxFecha[51];
    char auxTema[51];
    char auxPuntajeUno[51];
    char auxPuntajeDos[51];
    char auxPromedio[51];



    FILE* pFile=fopen(path,"w");


    if(pFile!=NULL && concur !=NULL)
    {
        fprintf(pFile,"Numero,Anio,Nombre,Dni,Fecha,Tema,PuntajeUno,PuntajeDos,Promedio\n");

        for(int i= 0; i < ll_len(concur); i++)
        {

            auxConcur = ll_get(concur,i);

            concur_getNumero(auxConcur,&numero);
            concur_getAnioNaci(auxConcur,&anio);
            concur_getNombre(auxConcur,auxNombre);
            concur_getDni(auxConcur,auxDni);
            concur_getFecha(auxConcur,auxFecha);
            concur_getTemaPresen(auxConcur,auxTema);
            concur_getPuntajePrimeraRonda(auxConcur,&puntajeUno);
            concur_getPuntajeSegundaRonda(auxConcur,&puntajeDos);
            concur_getPromedio(auxConcur,&promedio);

            sprintf(auxNumero, "%d", numero);
            sprintf(auxAnioNaci,"%d",anio);
            sprintf(auxPuntajeUno,"%d",puntajeUno);
            sprintf(auxPuntajeDos,"%d",puntajeDos);
            sprintf(auxPromedio,"%f",promedio);
            fprintf(pFile,"%s,%s,%s,%s,%s,%s,%s,%s,%s\n",auxNumero,auxAnioNaci,auxNombre,auxDni,auxFecha,auxTema,auxPuntajeUno,auxPuntajeDos,auxPromedio);
            //printf("%s,%s,%s,%s,%s,%s,%s,%s,%s\n",auxNumero,auxAnioNaci,auxNombre,auxDni,auxFecha,auxTema,auxPuntajeUno,auxPuntajeDos,auxPromedio);
        }
        fclose(pFile);

        retorno = 1;
    }

    return retorno;
}


int calcularPromedio(void* concur)
{
    eConcur* aux = (eConcur*) concur;
    int puntajeDos = rand() % 101;
    int puntajeUno;
    float promedio;

    if(concur != NULL)
    {
        promedio = (aux->puntajePrimeraRonda + puntajeDos) / 2;
    }

    concur_setPuntajeSegundaRonda(aux,puntajeDos);
    concur_setPromedio(aux,promedio);
}

int llamadoProm(LinkedList* concur)
{
    int retorno = 0;

    if(concur != NULL)
    {
        ll_map(concur,calcularPromedio);
        retorno = 1;
    }

    return retorno;
}

int calcularCant(void* concur,int cant)
{
    int retorno = 0;
    int auxPuntaje;
    char dni[15];
    LinkedList* ll_aux = ll_newLinkedList();
    int auxDni;
    eConcur* aux = (eConcur*) concur;
    concur_getPuntajePrimeraRonda(aux,&auxPuntaje);
    concur_getDni(aux,&auxDni);

    if(auxPuntaje > cant)
    {
        ll_add(ll_aux,concur);
        itoa(auxDni,dni,10);
        strcat(dni,".csv");
        controller_saveFromText(dni,ll_aux);
        retorno = 1;
    }

    return retorno;
}

int llamadoCant(LinkedList* concur)
{
    int cant;
    eConcur* concursante;
    int cantidadMas;
    int retorno = 0;

    printf("Ingrese el numero: ");
    scanf("%d",&cant);

    if(concur != NULL)
    {
        cantidadMas = ll_count(concur,calcularCant,cant);

        retorno = 1;
    }

    printf("Hay %d concursantes que superan esa nota.\n",cantidadMas);

    return retorno;
}












