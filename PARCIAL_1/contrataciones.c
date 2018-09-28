#include <stdio.h>
#include <stdlib.h>
#include "parcial.h"
#include "utn.h"
#include <string.h>
#include "contrataciones.h"


static int generarId(void)
{
    static int id = 0;
    id++;
    return id;
}

void con_init_isEmpty(Contrataciones* pContratacion, int limite)
{
    int i=0;

    if(pContratacion!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pContratacion[i].isEmpty = 1;
        }
    }
}


void alta_contrataciones(Contrataciones* pContratacion,Pantalla* pPantalla, int limiteP,int limiteC)
{
    int id;
    int index;

    index = con_getEspacioVacio(pContratacion,limiteC);

    utn_getEntero(&id,1,"\nIngrese el ID de la pantalla donde se quiera publicar: ","Mal ingresado",0,100);

    pContratacion[index].id = generarId();
    pContratacion[index].idPantalla = id;
    utn_getEntero(&pContratacion[index].dias,1,"Ingrese la cantidad de dias:","Mal ingresado",0,1000);
    utn_getLetrasYNumeros(pContratacion[index].video,50,"Ingrese el nombre del video:");
    utn_getLetrasYNumeros(pContratacion[index].cuit,50,"Ingrese el numero cuit:");
}

int con_getEspacioVacio(Contrataciones* pContratacion , int limite)
{
    int i;
    int index;

    for(i=0;i<limite;i++)
    {
        if(pContratacion[i].isEmpty==1)
        {
            index = i;
        }
    }

    return index;
}

void listarContratacion(Contrataciones* pContrataciones, int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        if(pContrataciones[i].isEmpty==1)
        {
            printf("ID: %d\n",pContrataciones[i].id);
            printf("Cuit: %s\n",pContrataciones[i].cuit);
            printf("Dias: %d\n",pContrataciones[i].dias);
        }
    }
}



