#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "service.h"


static int isValidGravedad(int gravedad);
static int isValidMensaje(char*mensaje);
static int isValidServiceId(int serviceId);

Service* new_service()
 {
    return (Service*) malloc (sizeof(Service));
 }

Service* service_NewParametros(int gravedad, char* mensaje, int serviceId)
{
    Service* this = new_service();
    if (this == NULL ||
        service_SetGravedad(this,gravedad) ||
        service_SetMensaje(this,mensaje) ||
        service_SetservisId(this,serviceId))

        {
            service_delete(this);
            this =NULL;
        }
    return this;

}


int service_SetGravedad(Service* this,int gravedad)
{
    int retorno=-1;

    if(this !=NULL && isValidGravedad(gravedad))
    {
        this->gravedad=gravedad;
        retorno=0;
    }
    return retorno;
}

int service_SetMensaje(Service* this,char* mensaje)
{
    int retorno=-1;

    if(this !=NULL && isValidMensaje(mensaje))
    {
         strcpy(this->mensaje,mensaje);
        retorno=0;
    }
    return retorno;
}

int service_SetservisId(Service* this,int serviceId)
{
    int retorno=-1;

    if(this !=NULL && isValidServiceId(serviceId))
    {
          this->serviceId=serviceId;
        retorno=0;
    }
    return retorno;
}


 void service_delete(Service* this)
 {
    free (this);
 }

static int isValidGravedad(int gravedad)
{
    return 1;
}
static int isValidMensaje(char* mensaje)
{
    return 1;
}

static int isValidServiceId(int serviceId)
{
    return 1;
}

void listarService(Service* this)
{
    printf("\n %d - %s - %d",this->gravedad,this->mensaje,this->serviceId);
}
