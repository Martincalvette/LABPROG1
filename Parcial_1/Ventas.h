#ifndef AFICHES_H_INCLUDED
#define AFICHES_H_INCLUDED
#define LIMITE_V 2

typedef struct
{
    char nombre[51];
    int  cantidad;
    char zona[20];
    int id;
    int idCliente;
    int isEmpty;
} Ventas;
/**
    listar_Ventas:Muestra una lista con las ventas
    @param :Puntero a array de ventas
    @return void
*/
void listar_Ventas(Ventas* pVentas, int limite);
/**
    init_isEmptyVentas:Recorre el array marcando "isEmpty" como "ocupado"
    @param Puntero a array de ventas
    @param limite del array
    @return 0 is ok, -1 error
*/
int init_isEmptyVentas(Ventas* pVentas, int limite);
/**
    VentasCargadas:confirma que la carga fue exitosa imprimiendo el id
    @param Puntero a array de ventas
    @param limite del array
    @return 0 is ok, -1 error
*/
void VentasCargadas(Ventas* pVentas, int limite, Clientes* pClientes, int len);
/**
    Ventas_getEspacioVacio:Busca un espacio vacio en el array
    @param Puntero a array de ventas
    @param limite del array
    @param Puntero a array de clientes
    @param limite del array
    @return 0 is ok, -1 error
*/
int Ventas_getEspacioVacio(Ventas* pVentas, int limite);
/**
    utn_getchar:valida una entrada al usuario en formato char
    @param pResultado: puntero donde guardar el char obtenido
    @return 0 is ok, -1 error
*/
int modificarVentas(Ventas * pVentas,int limite,int id);
int buscarPorID(Ventas* pVentas, int limite, int id);
#endif // AFICHES_H_INCLUDED
