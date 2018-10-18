#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include "service.h"
int main()
{
    int qtyEmpleados =0;
    int qtyService=0;
    char auxiliar[50];
    char auxiliares[50];
    int i;
    Empleado* listaEmpleados[1000];
    Service* listaService[1000];
    for (i=0;i<100;i++)
    {
        sprintf(auxiliar,"Juan_%d",i);
        listaEmpleados[i] = empleado_NewParametros(auxiliar,"Fretez", 1.73);
        qtyEmpleados++;

    }


    for (i=0;i<qtyEmpleados;i++)
    {
       listarEmpleados(listaEmpleados[i]);
    }


    //----------------------------------------
     for (i=0;i<100;i++)
    {
        sprintf(auxiliares,"Devoto_%d",i);
        listaService[i] = service_NewParametros(auxiliares,"pc", 1);
        qtyService++;

    }


    for (i=0;i<qtyService;i++)
    {
       listarService(listaService[i]);
    }

    return 0;
}
/*
Empleado* empleado_new()
{
    return malloc(sizeof(Empleado));
}


void empleado_mostrar(Empleado* this)
{
    printf("\n %s - %s - %f - %d",this->nombre,this->apellido,this->altura,this->idEmpleado);
}
*/
void ordenar ( void * lista[], int limite)
{
    int flagSwap;
    int i;
    void* auxiliarPuntero;


    do
    {
        flagSwap=0;
        for(i=0;i<limite-1;i++)
        {
            if compare(lista[i], lista [i+1] >0)
            {
                auxiliarPuntero = lista [i+1]
                lista[i]
                lista

            }
        }


    }while (flagswap);

}
