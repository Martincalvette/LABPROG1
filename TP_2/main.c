#include <stdio.h>
#include <stdlib.h>
#include "empleados.h"
#include "utn.h"

//[]


int main()
{
    Empleados empleados[LIMITEE];

    int opcion=0;
    int auxId;
    int opcionInforme;
    int bandera=-1;
    do
    {
        printf("\nIngrese 1 para dar de alta un empleado:\nIngrese 2 para modificar datos de un empleado:\nIngrese 3 para dar de baja un empleado:\n");
        printf("Ingrese 4 para ingresar al menu de informes:\nIngrese 0 para salir del programa:\n");

        utn_getEntero(&opcion,3,"\nIngrese una opcion:","opcion invalida",0,4);
        switch (opcion)
        {
        case 1:
            init_isEmpty(empleados,LIMITEE);
            altaEmpleados(empleados);
            listarEmpleados(empleados,LIMITEE);
            bandera=0;
            break;
        case 2:
            if(bandera==-1)
            {
                   printf("\nEl sistema no dispone de datos ingresados\n");
            }else if(utn_getEntero(&auxId,3,"\nIngrese el id del empleado a modificar :","\nError..Ingrese un id valido",-1,100)==0)
                    {
                    modificarEmpleados(empleados,LIMITEE,auxId);
                    }

            break;
    case 3:
         if(bandera==-1)
            {
                   printf("\nEl sistema no dispone de datos ingresados\n");
            }else if (utn_getEntero(&auxId,3,"\nIngrese el ID que quiere dar de baja :","\nIngrese un ID valido",-1,100)==0)
            bajaDeEmpleado(empleados,LIMITEE,auxId);
        break;
    case 4:
            utn_getEntero(&opcionInforme,3,"\nIngrese 1 para ordenar por Apellido y Sector \nIngrese 2 para saber el total y promedio de los sueldos\n","Mal ingresado",0,50);
            switch(opcionInforme)
            {
            case 1:
                OrdenarApellidoYSector(empleados,LIMITEE);
                break;
            case 2:
                totalYPromedioSueldos(empleados,LIMITEE);
                break;
            }
        }
}
while (opcion!=0);
}


/*

    */
