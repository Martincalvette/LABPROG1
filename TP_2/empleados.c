#include "utn.h"
#include "empleados.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static int generarId(void);


int init_isEmpty(Empleados* pEmpleados, int limite)
{
    int i;
    int retorno=-1;
    if(pEmpleados!= NULL && i<limite)
    {
        for(i=0; i<limite; i++)
        {
            pEmpleados[i].isEmpty = 1;
            retorno=0;
        }
    }
    return retorno;
}

void altaEmpleados(Empleados* pEmpleados)
{
    int index;



    index=getEspacioVacio(pEmpleados,LIMITEE);


    pEmpleados[index].id = generarId();
    utn_getLetrasYNumeros(pEmpleados[index].nombre,51,"Ingrese el nombre del empleado:");
    utn_getLetrasYNumeros(pEmpleados[index].apellido,51,"Ingrese el apellido del emepleado: ");
    utn_getFloat(&pEmpleados[index].sueldo,2,"Ingrese el sueldo","Reintente",0.0,1000000.0);
    utn_getEntero(&pEmpleados[index].sector,2,"Ingrese el sector donde trabaja el empleado","Ingreso invalido",0,51);
//listarPantalla(pEmpleados,LIMITEE);

}
int getEspacioVacio(Empleados* pEmpleados , int limite)
{
    int i;
    int index;

    for(i=0;i<limite;i++)
    {
        if(pEmpleados[i].isEmpty==1)
        {
            index = i;
            break;
        }
    }

    return index;
}

int modificarEmpleados(Empleados* pEmpleados,int limite,int id)
{
    int i;
    int auxSector;
    char auxNombre[51];
    char auxApellido[51];
    float auxSueldo;
    int retorno=-1;
    if(pEmpleados!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pEmpleados[i].id==id&& pEmpleados[i].isEmpty==1){
                retorno=0;
                if(utn_getLetras(auxNombre,50,3,"\nIngrese el nombre: ","\nIngrese un nombre valido")==0&&
                utn_getLetras(auxApellido,50,3,"\nIngrese el apellido: ","\nIngrese un apellido valido")==0&&
                utn_getFloat(&auxSueldo,3,"\nIngrese el salario: ","\nIngrese un salario valio",0,999999)==0&&
                utn_getEntero(&auxSector,3,"\nIngrese el sector: ","\nIngrese un sector valido",1,3)==0){
                    strcpy(pEmpleados[i].apellido,auxApellido);
                    strcpy(pEmpleados[i].nombre,auxNombre);
                    pEmpleados[i].sueldo=auxSueldo;
                    pEmpleados[i].sector=auxSector;
                    break;
                }
            }
        }
    }
    return retorno;
}
int buscarPorID(Empleados* pEmpleados, int limite, int id)
{
    int i;
    int retorno=-1;

    for (i=0;i<limite;i++)
    {
        if(pEmpleados[i].isEmpty==0 && pEmpleados[i].id==id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

static int generarId(void)

{
    static int id = 0;
    id++;
    return id;
}

void listarEmpleados(Empleados* pEmpleados, int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        if(pEmpleados[i].isEmpty==1)
        {
            printf("ID: %d\n",pEmpleados[i].id);
            printf("Nombre: %s\n",pEmpleados[i].nombre);
            printf("Apellido: %s\n",pEmpleados[i].apellido);
            printf("Sueldo: %2.f\n",pEmpleados[i].sueldo);
            printf("Sector: %d \n",pEmpleados[i].sector);
        }
    }
}


int buscarEmpleadoPorId(Empleados* pEmpleados, int limite, int id)
{
    int i;
    int retorno=-1;

    for (i=0;i<limite;i++)
    {
        if(pEmpleados[i].isEmpty==0 && pEmpleados[i].id==id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
int bajaDeEmpleado(Empleados* pEmpleados,int limite,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pEmpleados[i].isEmpty==0&& pEmpleados[i].id==id){
            pEmpleados[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
int totalYPromedioSueldos(Empleados* pEmpleados,int limite)
{
    int retorno = -1;
    int i;
    float resultado=0;
    float promedio=0;
    float cantidadSupProm=0;
    float contadorSueldos=0;


    if(pEmpleados != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            if(pEmpleados[i].isEmpty==0)
            {
                resultado = resultado+pEmpleados[i].sueldo;
                contadorSueldos++;
                promedio = resultado/contadorSueldos;

                if(pEmpleados[i].sueldo > promedio)
                {
                    cantidadSupProm++;
                }
            }
        }
        retorno = 0;
        printf("\n-El total de los salarios es: %.2f \n2-El promedio de los salarios es: %.2f \n3-La cantidad que superan el salario promedio son: %.2f"
               ,resultado,promedio,cantidadSupProm);
    }
    return retorno;
}
int OrdenarApellidoYSector(Empleados* pEmpleados, int limite)
{

   int i;
   int retorno = -1;
   Empleados auxiliar;
   int j;


   if(pEmpleados != NULL && limite > 0)
   {
       for(i=0;i<limite -1;i++)
       {
           for(j=i+1;j<limite;j++)
           {
               if(strcmp(pEmpleados[j].apellido,pEmpleados[i].apellido)<0)
               {
                   auxiliar = pEmpleados[i];
                   pEmpleados[i]=pEmpleados[j];
                   pEmpleados[j]=auxiliar;
               }
               else if(strcmp(pEmpleados[j].apellido,pEmpleados[i].apellido)==0 &&pEmpleados[j].sector<pEmpleados[i].sector)
               {
                   auxiliar=pEmpleados[i];
                   pEmpleados[i]=pEmpleados[j];
                   pEmpleados[j]=auxiliar;
               }
           }
       }
       retorno=0;
   }
   return retorno;
}
