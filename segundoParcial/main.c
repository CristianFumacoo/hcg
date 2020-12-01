#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "concur.h"
#include "LinkedList.h"
#include "Controller.h"
#include "menu.h"

#define TAM 10
/*
    TEMA 3
*/

int main()
{
    int opc;
    int opcArch;
    LinkedList* concursante = ll_newLinkedList();


    do
    {
        opc = menu();

            switch(opc)
            {
                case 1:
                   if(controller_loadFromText("2doparcial.csv",concursante))
                   {
                       printf("\nSe leyo correctamente.\n");
                       system("pause");
                   }
                    system("cls");
                    break;
                case 2:
                    mostrarLista(concursante);
                    system("pause");
                    system("cls");
                    break;

                case 3:
                   if(llamadoProm(concursante))
                   {
                       printf("Se calculo correctamente.\n");
                    system("pause");
                   }
                    system("cls");
                    break;
                case 4:
                    if(controller_saveFromText("resultado2doparcial.csv",concursante))
                    {
                        printf("\nSe guardaron correctamente.\n");
                        system("pause");
                    }
                    system("cls");
                    break;
                case 5:
                    if(llamadoCant(concursante))
                    {
                        printf("Hecho correctamente.\n");
                        system("pause");
                    }
                    system("cls");
                    break;
            }


    }while(opc != 99);

    return 0;
}
