#include <stdio.h>
#include <stdlib.h>

#include "mascotas.h"
#include "menu.h"

#define TAM 10
#define RAZ 20
#define TIP 3
#define PAI 10
#define TAMA 3

int main()
{
    int opc;
    int idMascota = 8;
    int idRazas = 7;
    eMascota mascotas[TAM];
    eRaza razas[RAZ];
    eTipo tipos[TIP];
    ePais paises[PAI];
    eTam tama[TAMA];
    todoVacio(mascotas,razas,tipos,TAM,RAZ,TIP);

    hardcodeMascotas(mascotas);
    hardcodeRazas(razas);
    hardcodeTipo(tipos);
    harcodePais(paises);
    harcodeTam(tama);


    do
    {
        opc = menu();

        switch(opc)
        {
        case 1:
            ingresarMascota(mascotas,razas,tipos,TAM,RAZ,TIP,idMascota);
            idMascota++;
            system("pause");
            system("cls");
            break;
        case 2:
            ingresarRaza(razas,paises,tama,RAZ,idRazas,PAI,TAMA);
            idRazas++;
            system("pause");
            system("cls");
            break;
        case 3:
            mostrarMascotas(mascotas,TAM);
            system("pause");
            system("cls");
            break;

        case 4:
            mostrarRazas(razas,RAZ);
            system("pause");
            system("cls");
            break;

        case 5:
            mostrarMascotaConRaza(mascotas,razas,paises,tipos,TAM,RAZ,PAI,TIP);
            system("pause");
            system("cls");
            break;
        case 6:
            borrarMascota(mascotas,TAM);
            system("pause");
            system("cls");
            break;
        case 7:
            borrarRaza(mascotas,razas,TAM,RAZ);
            system("pause");
            system("cls");
            break;
        case 8:
            modificarMascota(mascotas,razas,tipos,paises,TAM,RAZ,TIP,PAI);
            system("pause");
            system("cls");
            break;
        case 9:
            mostrarPorPais(mascotas,TAM,razas,RAZ,paises,PAI);
            printf("Se ordeno correctamente.\n");
            system("pause");
            system("cls");
            break;
        case 10:
            mostrarPorTam(mascotas,razas,paises,tama,TAM,RAZ,PAI);
            system("pause");
            system("cls");
            break;
        case 11:
            mostrarPorRaz(mascotas,razas,paises,TAM,RAZ,PAI);
            system("pause");
            system("cls");
            break;
        case 12:
            contMascotasPorRaza(mascotas,razas,paises,TAM,RAZ,PAI);
            system("pause");
            system("cls");
            break;
        case 13:
            mostrarPorCodigo(mascotas,razas,paises,TAM,RAZ,PAI);
            printf("Se ordeno correctamente.\n");
            system("pause");
            system("cls");
            break;
        case 14:
            mostrarTipoPeso(mascotas,tipos,TAM,TIP);
            system("pause");
            system("cls");
            break;
        case 15:
            mostrarPorTipoPeso(mascotas,tipos,TAM,TIP);
            printf("Se ordeno correctamente.\n");
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc != 99);

    return 0;
}
