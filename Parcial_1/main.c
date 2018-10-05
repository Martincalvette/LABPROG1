#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Clientes.h"
#include "Ventas.h"
int main()
{
    Clientes sClientes[LIMITE_C];
    Ventas sVentas[LIMITE_V];
    int opcion;
    int auxId;
    int banderaDeDatos= -1;


    do
    {
        menu();

        utn_getEntero(&opcion,3,"\nIngrese una opcion:","opcion invalida",0,60);

        switch (opcion)
        {
        case 1:
            init_isEmpty(sClientes,LIMITE_C);
            altaClientes(sClientes);
            listar_Clientes(sClientes,LIMITE_C);
            banderaDeDatos=0;
            break;
        case 2:
            if(-1==banderaDeDatos)
            {
                printf("\nEl sistema no dispone de datos ingresados\n");
            }
            else if (utn_getEntero(&auxId,3,"\nIngrese el id del cliente a modificar :"
                                    ,"\nError. Ingrese un id valido",-1,100)==0)

            {
                modificarClientes(sClientes,LIMITE_C,auxId);
                listar_Clientes(sClientes,LIMITE_C);
            }

            break;
        case 3:
            if(-1==banderaDeDatos)
            {
                printf("\nEl sistema no dispone de datos ingresados\n");
            }
            else if (!utn_getEntero(&auxId,3,"\nIngrese el id del cliente a dar de baja :"
                                    ,"\nError. Ingrese un id valido",-1,100))

            {
                bajaDeCliente(sClientes,LIMITE_C,auxId);
            }

            break;
        case 4:
            altaVentas(sVentas,LIMITE_V,sClientes,LIMITE_C);
            init_isEmptyVentas(sVentas,LIMITE_V);

            break;
        case 5:
            listar_Ventas(sVentas,LIMITE_V);
            modificarVentas(sVentas,LIMITE_V,auxId);
            break;
        case 6:
            listar_Ventas(sVentas,LIMITE_V);
        }
    }
    while (opcion!=0);
}


