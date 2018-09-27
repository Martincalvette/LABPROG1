#ifndef CONTRATACIONES_H_INCLUDED
#define CONTRATACIONES_H_INCLUDED

typedef struct
{
    int id;
    char video[50];
    char cuit[11];
    int dias;
    int idPantalla;
    int isEmpty;

}Contrataciones;

void altaContrataciones (Contrataciones* pContrataciones,  Pantalla* pPantalla, int limitePant, int limiteCont);
int con_getEspacioVacio(Contrataciones* pContrataciones , int limite);
void con_init_isEmpty(Contrataciones* pContrataciones, int limite);



#endif // CONTRATACIONES_H_INCLUDED
