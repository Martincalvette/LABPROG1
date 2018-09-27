#include <stdio_ext.h>
#include <stdlib.h>
#include "parcial.h"
#include "utn.h"
#include "contrataciones.h"
#define LIMITEP 100
#define LIMITEC 1000

int main()
{

    printf("Hola0");
    Pantalla pantallas[LIMITEP];
    Contrataciones contrataciones[LIMITEC];

    init_isEmpty(pantallas,LIMITEP);
    con_init_isEmpty(contrataciones,LIMITEC);

    altaPantalla(pantallas);
    altaContrataciones (contrataciones,pantallas,LIMITEP,LIMITEC);

    return 0;
}

 /*

       int opcion=0; (esto va arriba de todo

    do
    {
        printf("Ingrese 1 para dar de alta una pantalla:\n");
        printf("Ingrese 2 para modificar datos de pantalla:\n");
        printf("Ingrese 3 para dar de baja una pantalla:\n");
        printf("Ingrese 4 para contratar una publicidad:\n");
        printf("Ingrese 5 para modificar condiciones de publicidad:\n");
        printf("Ingrese 6 para cancelar una contratacion:\n");
        printf("Ingrese 7 para consultar facturacion:\n");
        printf("Ingrese 8 para ver lista de contrataciones:\n");
        printf("Ingrese 9 para ver lista de pantallas:\n");
        printf("Ingrese 10 para ver la lista de clientes:\n");

        utn_getEntero(&opcion,3,"ingrese una opcion","opcion invalida",0,11);

        switch (opcion)
        {
        case 1:
            altaPantalla(pantallas);
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            break;

        case 10:
            break;
        }


    } while (opcion!=10);*/
