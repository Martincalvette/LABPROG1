#include <stdio_ext.h>
#include <stdlib.h>
#include "parcial.h"
#include "utn.h"
#include <string.h>

static int generarId(void);


void modificarPantalla(Pantalla* pPantalla, int id)
{
    int index;

    index = buscarPantallaPorID(pPantalla, LIMITEP, id);

    utn_getLetrasYNumeros(pPantalla[index].direccion,LIMITEP,"Ingrese la direccion:");
    get_tipo(&pPantalla[index].tipo);
    utn_getFloat(&pPantalla[index].precio,0,"Ingrese el precio:","Mal ingresado",0.0,100000.0);
    utn_getLetrasYNumeros(pPantalla[index].nombre,50,"Ingrese el nombre de la pantalla: ");

}

void altaPantalla(Pantalla* pPantalla)
{
    int index;



    index=getEspacioVacio(pPantalla,LIMITEP);


    get_tipo(&pPantalla[index].tipo);
    pPantalla[index].id = generarId();
    utn_getLetrasYNumeros(pPantalla[index].direccion,LIMITEP,"Ingrese la direccion:");
    utn_getFloat(&pPantalla[index].precio,0,"Ingrese el precio","Mal ingresado",0.0,100000.0);
    utn_getLetrasYNumeros(pPantalla[index].nombre,50,"Ingrese el nombre de la pantalla: ");
    listarPantalla(pPantalla,LIMITEP);

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
            break;
        }
    }

    return index;
}

void get_tipo(int* tipo)
{
    int opcion;

    __fpurge(stdin);
    printf("Ingrese una opcion:");
    printf("\n1) LED");
    printf("\n2) LCD\n");
    scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                *tipo = 1;
                break;

            case 2:
                *tipo = 2;
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

    pPantalla[index].isEmpty = 1;

}

void listarPantalla(Pantalla* pPantalla, int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        if(pPantalla[i].isEmpty==1)
        {
            printf("Direccion: %s\n",pPantalla[i].direccion);
            printf("ID: %d\n",pPantalla[i].id);
            printf("Nombre: %s\n",pPantalla[i].nombre);
            printf("Precio: %2.f\n",pPantalla[i].precio);
            printf("Tipo: %d \n",pPantalla[i].tipo);
        }
    }
}
