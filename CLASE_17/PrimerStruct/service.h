#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED
typedef struct
{
  int gravedad;
  char mensaje[65];
  int serviceId;
} Service;


int service_SetMensaje(Service* this,char* mensaje);
int service_SetGravedad(Service* this,int gravedad);
int service_SetservisId(Service* this,int serviceId);
Service* service_NewParametros(int gravedad, char* mensaje, int serviceId);
void listarService(Service* this);
void service_delete(Service* this);

#endif // SERVICE_H_INCLUDED
