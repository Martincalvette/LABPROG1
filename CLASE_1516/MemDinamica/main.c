#include <stdio.h>
#include <stdlib.h>

 int initArray(int* pArray, int limite, int valor);
 int* newArray(int size);
 int show_Array(int* pArray, int limite);

 int main()
{
    int* pArray=NULL;
    newArray(100);
    initArray(pArray,100,1024); // NO FUNCIONA
    show_Array(pArray,100);

return 0;
}
int init_Array(int* pArray, int limite, int valor)
    {
        int retorno =-1;
        int i;
        if (pArray!=NULL && limite>0)
        {
            for (i=0;i<limite;i++)
            {
                *(pArray+i)=valor;
            }

        retorno=0;

        }
        return retorno;
    }

    int show_Array(int* pArray, int limite)
    {
        int retorno =-1;
        int i;
        if (pArray!=NULL && limite>0)
        {
            for (i=0;i<limite;i++)
            {
                printf("%d",*pArray);
            }

        retorno=0;

        }
        return retorno;
    }

 int* newArray(int size)
    {
        int* retorno =NULL;
        if (size<0)
        {
            retorno= malloc(sizeof(int)*size);
        }
        return retorno;
    }

    int* reSizeArray(int* pArray,int size)
    {
        int* retorno =NULL;
        int* auxiliarInt;
        if (size<0)
        {
            retorno= realloc(auxiliarInt,sizeof(int)*size);
        }
        return retorno;
    }
