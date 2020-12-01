#include "LinkedList.h"
typedef struct
{
    int numeroConcursante;
    int anioNacimiento;
    char nombre[51];
    char dni[9];
    char fecha[15];
    char temaPresentacion[31];
    int puntajePrimeraRonda;
    int puntajeSegundaRonda;
    float promedioPuntaje;
}eConcur;

eConcur* concur_new();//Listo
eConcur* concur_conParemetros(char*,char*,char*,char*,char*,char*,char*,int*,float*);
int archivoLeer(eConcur*);

void mostrar(eConcur*);


int concur_setNumero(eConcur*,int);//Listo
int concur_getNumero(eConcur*,int*);//Listo

int concur_setAnioNaci(eConcur*,int);//Listo
int concur_getAnioNaci(eConcur*,int*);//Listo

int concur_setNombre(eConcur*,char*);//Listo
int concur_getNombre(eConcur*,char*);

int concur_setDni(eConcur*,char*);//Listo
int concur_getDni(eConcur*,int*);//Listo

int concur_setFecha(eConcur*,char*);//Listo
int concur_getFecha(eConcur*,char*);//Listo

int concur_setTemaPresen(eConcur*,char*);//Listo
int concur_getTemaPresen(eConcur*,char*);//Listo

int concur_setPuntajePrimeraRonda(eConcur*,int);//Listo
int concur_getPuntajePrimeraRonda(eConcur*,int*);//Listo


int concur_setPuntajeSegundaRonda(eConcur*,int);
int concur_getPuntajeSegundaRonda(eConcur*,int*);

int concur_setPromedio(eConcur*,float);
int concur_getPromedio(eConcur*,float*);



