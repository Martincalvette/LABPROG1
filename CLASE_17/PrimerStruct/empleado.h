#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
  char nombre[50];
  char apellido[50];
  float altura;

  int idEmpleado;
} Empleado;

Empleado*empleado_NewParametros(char*nombre, char* apellido, float altura);
int empleado_SetNombre(Empleado* this,char* nombre);
int empleado_SetApellido(Empleado* this,char* apellido);
int empleado_SetAltura(Empleado* this,float altura);
void empleado_delete(Empleado* this);
void listarEmpleados(Empleado* this);
Empleado* new_empleado();


#endif // EMPLEADO_H_INCLUDED
