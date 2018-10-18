#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

static int isValidNombre(char*nombre);
static int isValidApellido(char* apellido);
static int isValidAltura(float altura);

Empleado*empleado_NewParametros(char*nombre, char* apellido, float altura)
{
    Empleado* this = new_empleado();
    if (this == NULL ||
        empleado_SetNombre(this,nombre) ||
        empleado_SetApellido(this,apellido) ||
        empleado_SetAltura(this,altura))

        {
            empleado_delete(this);
            this =NULL;
        }
    return this;

}
static int isValidNombre(char* nombre)
{
    return 1;
}


 Empleado* new_empleado()
 {
    return (Empleado*) malloc (sizeof(Empleado));
 }


int empleado_SetNombre(Empleado* this,char* nombre)
{
    int retorno=-1;

    if(this !=NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}
int empleado_SetAltura(Empleado* this,float altura)
{
    int retorno=-1;

    if(this !=NULL && isValidAltura(altura))
    {
        this->altura=altura;
        retorno=0;
    }
    return retorno;
}

int empleado_SetApellido(Empleado* this,char* apellido)
{
    int retorno=-1;

    if(this !=NULL && isValidApellido(apellido))
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

 void empleado_delete(Empleado* this)
 {
    free (this);
 }


static int isValidApellido(char* apellido)
{
    return 1;
}
static int isValidAltura(float apellido)
{
    return 1;
}

void listarEmpleados(Empleado* this)
{
    printf("\n %s - %s - %f - %d",this->nombre,this->apellido,this->altura,this->idEmpleado);
}
