#include <stdio_ext.h>
#include <stdlib.h>
#include "parcial.h"
#include "utn.h"
#include <string.h>
#include "contrataciones.h"
#define LIMITEP 100
#define LIMITEC 1000



static int generarId(void);


void con_init_isEmpty(Contrataciones* pContrataciones, int limite)
{
    int i=0;

    if(pContrataciones!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pContrataciones[i].isEmpty = 1;
        }
    }
}


void altaContrataciones (Contrataciones* pContrataciones,  Pantalla* pPantalla, int limitePant, int limiteCont)
{
    int id;
    int index;

    listarPantallas(pPantalla,LIMITEP);
    {
        utn_getEntero(&id,3,"ID cargado","Id mal ingresado",0,101);
    }

    index=con_getEspacioVacio(pContrataciones,LIMITEC);

    pContrataciones[index].id = generarId();
    getString("\nIngrese el nombre del video de la pantalla: ",pContrataciones[index].video);
    getString("\nIngrese el cuit del cliente: ", pContrataciones[index].cuit);
    getString("\nIngrese el la cantidad de dias de la contratacion: ", pContrataciones[index].dias);

}

int con_getEspacioVacio(Contrataciones* pContrataciones , int limite)
{
    int i;
    int index;

    for(i=0;i<limite;i++)
    {
        if(pContrataciones[i].isEmpty==1)
        {
            index = i;
        }
    }

    return index;
}

static int generarId(void)
{
    static int id = 0;
    id++;
    return id;
}

