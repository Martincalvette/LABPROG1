#include "LinkedList.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    FILE* pFile;
    int retorno=0;
    char bufferId[1000];
    char bufferNombre[1000];
    char bufferHorasTrabajadas[200];
    Empleado* auxEmpleado;
    int flagOnce = 0;
    pFile=fopen(fileName,"r");

    if(fileName!=NULL && listaEmpleados!=NULL)
    {
        retorno=1;
        do
        {
            if(!flagOnce)
            {
                fscanf(pFile,"%[^\n]\n,%[^\n]\n,%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas);
                flagOnce=1;
            }
            fscanf(pFile,"%[^\n]\n,%[^\n]\n,%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas);
            auxEmpleado=Employee_newConParametros(bufferId,bufferNombre,bufferHorasTrabajadas);
            if(auxEmpleado!=NULL)
                ll_add(listaEmpleados,auxEmpleado);
            else
            {
              printf("%s, %s, %s",bufferId,bufferNombre,bufferHorasTrabajadas);
              getchar();
            }
        }while(!feof(pFile));
    }
    fclose(fileName);
    return retorno;
}
