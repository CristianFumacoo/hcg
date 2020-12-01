#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "concur.h"
#include "LinkedList.h"

int parser_concurFromText(FILE* pFile, LinkedList* listaConcur)
{
    char auxNumero[51];
    char auxAnioNaci[51];
    char auxNombre[51];
    char auxDni[51];
    char auxFecha[51];
    char auxTema[51];
    char auxPuntaje[51];
    int retorno = 0;
    int flagOnce = 1;
    int tam;
    eConcur* concur;

    if(pFile!=NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxNumero,auxAnioNaci,auxNombre,auxDni,auxFecha,auxTema,auxPuntaje);

        while(!feof(pFile))
        {
            tam = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxNumero,auxAnioNaci,auxNombre,auxDni,auxFecha,auxTema,auxPuntaje);

            concur = concur_conParemetros(auxNumero,auxAnioNaci,auxNombre,auxDni,auxFecha,auxTema,auxPuntaje,0,0);

            if(tam == 7)
            {
                if(concur != NULL)
                {
                    ll_add(listaConcur,concur);
                    retorno = 1;
                }
            }
        }
    }

    return retorno;
}














