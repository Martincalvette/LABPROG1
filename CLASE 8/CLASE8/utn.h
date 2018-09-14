#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


/**
    utn_getEntero : pide un entero al usuario
    @param pEdad: puntero a edad
    @param reintentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int utn_getFloat(  float* pFloat, char* msg,
                    char msgErr[],float min, float max,
                    int reintentos);

/**
    ORDENA ARRAYS POR INSERCION

*/
void insertion(int datos[],int len);

#endif // UTN_H_INCLUDED
