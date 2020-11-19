typedef struct
{
    int idRaza;
    int idTipo;
    int id;
    int edad;
    char nombre[51];
    char sexo[2];
    float peso;
    char tipo[51];
    int isEmpty;
}eMascota;

typedef struct
{
    int id;
    int idPais;
    int idTam;
    char descripcion[51];
    char tamanio[51];
    char paisOrigen[51];
    int isEmpty;
}eRaza;

typedef struct
{
    int id;
    float peso;
    float totalPeso;
    int cantXTipo;
    char tipo[51];
}eTipo;

typedef struct
{
    int id;
    int isEmpty;
    char tamanio[51];
}eTam;


typedef struct
{
    int contador;
    char nombrePais[51];
    int isEmpty;
}eCont;

typedef struct
{
    int id;
    char nombreDePais[51];
    char continente[51];
    int codigoTelefonico;
    int isEmpty;
    int cont;
}ePais;

void todoVacio(eMascota[],eRaza[],eTipo[],int,int,int);
void hardcodeMascotas(eMascota[]);
void hardcodeRazas(eRaza[]);
void harcodeTipo (eTipo[]);
void harcodePais (ePais[]);
void hardcodeTam(eTam[]);

eRaza buscarRaza(eRaza[],int,int);
ePais buscarPais(ePais[],int,int);
eTipo buscarTipo(eTipo[],int,int);

void mostrarMascotas(eMascota*,int);
void mostrarRazas(eRaza*,int);
void mostrarUnaMascota(eMascota,eRaza,ePais,eTipo);
void mostrarMascotaConRaza(eMascota[],eRaza[],ePais[],eTipo[],int,int,int,int);
void mostrarPaises(ePais[],int);

void ingresarMascota(eMascota[],eRaza[],eTipo[],int,int,int,int);
int elegirRaza(eRaza[],int);
int elegirTipo(eTipo[],int);
int elegirTam(eTam[],int);

void ingresarRaza(eRaza[],ePais[],eTam[],int,int,int,int);
int elegirPais(ePais[],int);

void modificarMascota(eMascota[],eRaza[],eTipo[],ePais[],int,int,int,int);

void borrarMascota(eMascota[],int);
void borrarRaza(eMascota[],eRaza[],int,int);

void mostrarPorPais(eMascota*,int,eRaza[],int,ePais[],int);
void mostrarListadoPorRaza(eMascota[],eRaza[],eTipo[],int,int);
void mostrarPorCodigo(eMascota*,eRaza[],ePais[],int,int,int);
void mostrarPorTipoPeso(eMascota[],eTipo[],int,int);
void mostrarSEP(eMascota[],eRaza[],eTam[],int,int,int);

void paisConMasMascotas(eMascota*,eRaza*,int,int);

void mostrarPorTam(eMascota[],eRaza[],ePais[],eTam[],int,int,int);
void listarParRaz(eMascota[],eRaza[],ePais,eTam[],int,int,int);

void contMascotasPorRaza(eMascota[],eRaza[],ePais[],int,int,int);

void mostrarTipoPeso(eMascota[],eTipo[],int,int);
