#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED
#define LIMITEC 2
typedef struct
{
    int id;
    char video[50];
    char cuit[50];
    int dias;
    int idPantalla;
    int isEmpty;

}Contrataciones;
int con_getEspacioVacio(Contrataciones* pContratacion , int limite);
void con_init_isEmpty(Contrataciones* pContratacion, int limite);
void alta_contrataciones(Contrataciones* pContratacion,Pantalla* pPantalla, int limiteP,int limiteC);
#endif // CONTRATACIONES_H_INCLUDED
