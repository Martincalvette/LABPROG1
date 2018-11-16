#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int isLetras(char*pBuffer);
static int isInt(char *pBuffer);

Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* Employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
{
    Employee* this;
    this=Employee_new();
    if( !isInt(id) && !isLetras(nombre) && !isInt(horasTrabajadas)&& !isInt(sueldo) &&
        !Employee_setId(this,atoi(id))&&
        !Employee_setNombre(this,nombre)&&
        !Employee_setHorasTrabajadas(this,atoi(horasTrabajadas))&&
        !Employee_setSueldo(this,atoi(sueldo))){
            return this;
    }
    Employee_delete(this);
    return NULL;
}

int Employee_setId(Employee* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else{
        this->id=id;
        retorno=0;
    }

    if(id>proximoId)
    {
        proximoId=id;
        retorno=0;
    }
    return retorno;
}

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}
static int isInt(char *pBuffer)
{
    int retorno=-1;
    int i=0;
    do{
        if(*(pBuffer+i)<48||*(pBuffer+i)>57)
        {
                break;
        }
        i++;
    }while (i<strlen(pBuffer));
    if(i==strlen(pBuffer))
    {
        retorno=0;
    }
    return retorno;
}
static int isLetras(char*pBuffer)
{
    int retorno=-1;
    int i=0;
    if(pBuffer!=NULL){
        do{
            if(*(pBuffer+i)==' '||*(pBuffer+i)=='-')
            {
                i++;
                continue;
            }
            if((*(pBuffer+i)<65||*(pBuffer+i)>90) && (*(pBuffer+i)<97||*(pBuffer+i)>122))
            {
                break;
            }
            i++;
        }while(i<strlen(pBuffer));
        if(i==strlen(pBuffer))
        {
            retorno=0;
        }
    }
    return retorno;
}
void menu(void)
{
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
}
