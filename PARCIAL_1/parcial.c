#include <stdio_ext.h>
#include <stdlib.h>
#include "parcial.h"
#include "utn.h"
#include <string.h>
#define LIMITEP 100
#define LIMITEC 1000


static int generarId(void);


void modificarPantalla(Pantalla* pPantalla, int id)
{
    int index;

    index = buscarPantallaPorID(pPantalla, LIMITEP, id);

    getString("Ingrese la direccion de la pantalla: ",pPantalla[index].direccion);
    get_tipo(&pPantalla[index]);
    utn_getFloat(&pPantalla[index].precio,3,"bien hecho","no",0,99);
    getString("Ingrese el nombre de la pantalla: ", pPantalla[index].nombre);

}

void altaPantalla(Pantalla* pPantalla)
{
    int index;

    index=getEspacioVacio(pPantalla,LIMITEP);

    pPantalla[index].id = generarId();
    getString("Ingrese la direccion de la pantalla: ",pPantalla[index].direccion);
    get_tipo(&pPantalla[index]);
    utn_getFloat(&pPantalla[index].precio,3,"bien hecho","no",0,99);
    getString("Ingrese el nombre de la pantalla: ", pPantalla[index].nombre);

}

static int generarId(void)
{
    static int id = 0;
    id++;
    return id;
}

void init_isEmpty(Pantalla* pPantalla, int limite)
{
    int i=0;

    if(pPantalla!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pPantalla[i].isEmpty = 1;
        }
    }
}

int getEspacioVacio(Pantalla* pPantalla , int limite)
{
    int i;
    int index;

    for(i=0;i<limite;i++)
    {
        if(pPantalla[i].isEmpty==1)
        {
            index = i;
        }
    }

    return index;
}

void get_tipo(Pantalla* pPantalla)
{
    int opcion;

    __fpurge(stdin);
    printf("Ingrese una opcion: ");
    printf("\n1) LED");
    printf("\n2) LCD");
    scanf("%d",&opcion);

    switch(opcion)
    {
        case 1:
            pPantalla->tipo = 1;
            break;
        case 2:
            pPantalla->tipo = 2;
            break;
    }
}
int buscarPantallaPorID(Pantalla* pPantalla, int limite, int id)
{
    int i;
    int retorno=-1;

    for (i=0;i<limite;i++)
    {
        if(pPantalla[i].isEmpty==0 && pPantalla[i].id==id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

void bajaDePantalla(Pantalla* pPantalla, int id)
{
    int index;

    index = buscarPantallaPorID(pPantalla,LIMITEP,id);

    pPantalla[index].isEmpty=1;

}

void listarPantallas(Pantalla* pPantalla, int limite)
{

    int i;
    for (i=0;i<limite;i++)
    {
        if (pPantalla[i].isEmpty==1)
        {
            printf(" %d",pPantalla[i].id);
            printf(" %d",pPantalla[i].tipo);
            printf(" %f",pPantalla[i].precio);
            printf(" %s",pPantalla[i].nombre);
            printf(" %s\n",pPantalla[i].direccion);
        }
    }

}


void listarPorId(Pantalla* pPantalla, int limite)
{

    int i;
    for (i=0;i<limite;i++)
    {
        if (pPantalla[i].isEmpty==1)
        {
            printf(" %d",pPantalla[i].id);

        }
    }

}


