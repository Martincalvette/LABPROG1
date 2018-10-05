#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "Clientes.h"
#include "Ventas.h"

static int generarId(void);
static int proximoId(void);


int init_isEmptyVentas(Ventas* pVentas, int limite)
{
    int i;
    int retorno=-1;
    if(pVentas!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pVentas[i].isEmpty = 1;
            retorno=0;
        }
    }

    return retorno;
}
int altaVentas(Ventas* pVentas,int limite,
              Clientes* pClientes, int lenCLientes)
{
    int retorno = -1;
    int i;
    int idCliente;
    int posicionCliente;
    int Aux;


    if(limite > 0 && pClientes != NULL)
    {
        i = getEspacioVacio(pClientes,LIMITE_C);
        if(i >= 0)
        {

            utn_getEntero(&posicionCliente,1,"Ingrese el id","Ingrese un ID valido",-1,999);
            posicionCliente = buscarPorID(pVentas,LIMITE_V,idCliente);
            if(posicionCliente>=0)
            {
                pVentas[i].idCliente = idCliente;
                pVentas[i].isEmpty=0;
                pVentas[i].id = proximoId();
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}
/*
void altaVentas(Ventas* pVentas)
{
    int index;

    index=Ventas_getEspacioVacio(pVentas,LIMITE_V);

    pVentas[index].id = generarId();
    utn_getLetrasYNumeros(pVentas[index].nombre,51,"Ingrese el nombre del empleado:");
    utn_getLetrasYNumeros(pVentas[index].cantidad,51,"Ingrese el apellido del emepleado: ");
    utn_getLetras(pVentas[index].zona,20,2,"Ingrese la zona","Ingrese una zona valida");
    listar_Clientes(pVentas,LIMITE_V);

}*/
void listar_VentasPorId(Ventas* pVentas, int limite)
{
    int i;

    for(i=0; i<limite; i++)
    {
        if(pVentas[i].isEmpty==1)
        {
            printf("Nombre: %s\n",pVentas[i].nombre);
            printf("Cantidad: %d\n",pVentas[i].cantidad);
            printf("Zona: %s\n",pVentas[i].zona);
            printf("idCLiente: %d \n",pVentas[i].idCliente);
        }
    }
}

int Ventas_getEspacioVacio(Ventas* pVentas, int limite)
{
    int i;
    int index;

    for(i=0; i<limite; i++)
    {
        if(pVentas[i].isEmpty==1)
        {
            index = i;
            break;
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
int modificarVentas(Ventas * pVentas,int limite,int id)
{
    int i;
    int auxCantidad;
    char auxZona[20];
    int retorno=-1;
    if(pVentas!=NULL&&limite>0)
    {
        for (i=0; i<limite; i++)
        {
            if(pVentas[i].id==id&& pVentas[i].isEmpty==1)
            {
                retorno=0;
                if(!utn_getEntero(pVentas[i].cantidad,1,"Ingrese la cantidad","Ingrese cantidad valida",-1,999)&&
                    !utn_getLetras(pVentas[i].zona,20,1,"ingrese la zona","Ingrese una zona valida"))
                {

                    auxCantidad=pVentas[i].cantidad;
                    strcpy(pVentas[i].zona,auxZona);
                    break;
                }
            }
        }
    }
    return retorno;
}
int buscarPorID(Ventas* pVentas, int limite, int id)
{
    int i;
    int retorno=-1;

    for (i=0;i<limite;i++)
    {
        if(pVentas[i].isEmpty==0 && pVentas[i].id==id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
static int proximoId(void)
{


    static int proximoId = -1;
    proximoId++;
    return proximoId;
}
/*void VentasCargadas(Ventas* pVentas, int limite, Clientes* pClientes, int len)
{
    if (altaVentas(pVentas))
    {
        int i;

        for(i=0; i<limite; i++)
        {
            if(pVentas[i].isEmpty==1)
            {
                printf("idCLiente: %d \n",pVentas[i].id);
            }
        }
    }
}*/
