//#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED
#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED
#include <string.h>
#define LIMITEE 1000

typedef struct
{
 int id;
 char nombre[51];
 char apellido[51];
 float sueldo;
 int sector;
 int isEmpty;
} Empleados;

/** \brief Da de alta la lista de empleados
 * \param Puntero Empleados* a el array de empleados
 * \return
 */
void altaEmpleados(Empleados* pEmpleados);
/** \brief Busca por ID la posicion del array la cual queremos utilizar
 * \param Puntero Empleados* a el array de empleados
 * \param Int limite, limite maximo del array
 * \return devuelve la posicion del indice en el array
 */
int buscarPorID(Empleados* pEmpleados, int limite, int id);

/** \brief Lista los empleados con sus datos cargados
 * \param Puntero Empleados* a el array de empleados
 * \param Int limite, limite maximo del array
 * \return
 */
void listarEmpleados(Empleados* pEmpleados, int limite);
/** \brief Busca en el array el espacio de memoria sin sobrescribir
 * \param Puntero Empleados* a el array de empleados
 * \param Int limite, limite maximo del array
 * \return devuelve (-1) si hay un error, y (0) si pudo ejecutar
 */
int getEspacioVacio(Empleados* pEmpleados, int limite);

/** \brief Inicializa con la bandera "isEmpty" para demostrar si esta o no inicializado
 * \param Puntero Empleados* a el array de empleados
 * \param Int limite, limite maximo del array
 * \return devuelve (-1) si hay un error, y (0) si pudo ejecutar
 */
int init_isEmpty(Empleados* pEmpleados, int limite);
/** \brief Busca por ID la posicion del array que ocupa el empleado
 * \param Puntero Empleados* a el array de empleados
 * \param ID del empleado a modificar
 * \param Int limite, limite maximo del array
 * \return devuelve la posicion del indice en el array
 */
int buscarEmpleadoPorId(Empleados* pEmpleados, int limite, int id);
/** \brief Da de baja el empleado cuyo ID fue ingresado
 * \param Puntero Empleados* a el array de empleados
 * \param ID del empleado a modificar
 * \param Int limite, limite maximo del array
 * \return devuelve (-1) si hay un error, y (0) si pudo ejecutar
 */
int bajaDeEmpleado(Empleados* pEmpleados,int limite,int id);
/** \brief Modifica el empleado cuyo ID fue ingresado
 * \param Puntero Empleados* a el array de empleados
 * \param ID del empleado a modificar
 * \param Int limite, limite maximo del array
 * \return devuelve (-1) si hay un error, y (0) si pudo ejecutar
 */
int modificarEmpleados(Empleados* pBuffer,int limite,int id);
/** \brief Da un total y un promedio de la suma de los sueldos
 * \param Puntero Empleados* a el array de empleados
 * \param Int limite, limite maximo del array
 * \return devuelve (-1) si hay un error, y (0) si pudo ejecutar
 */
int totalYPromedioSueldos(Empleados* pEmpleados,int limite);

int OrdenarApellidoYSector(Empleados* pEmpleados, int limite);




#endif // EMPLEADOS_H_INCLUDED
